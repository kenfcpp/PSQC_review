= Qubits, Gates, and Circuits

== Bits and Qubits
Digital systems that are most familiar are based on binary digits,
 or “bits.” Each bit can take on either the value “1” or “0,” 
 and any arbitrary data can be represented by such a binary representation.
 We will refer to these familiar systems as "classical" systems, since they are governed by the everyday laws of classical physics.
 @<br>{}
　Quantum computing is different from classical computing in a number of significant ways.
 The fundamental unit of information in quantum computing is the @<i>{qubit} (pronounced "KEW-bit"), short for quantum bit.
 The capabilities and behavior of qubits are quite different than bits,
  and we begin by pointing out and discussing the key differences as a launching point for our study of quantum computing.

=== Circuits in Space vs. Circuits in Time
A simple classical logic circuit is represented by the NOT gate shown in Figure 1.1(a).
 The NOT gate turns a "0" into "1" and vice versa.
 In this circuit diagram the horizontal direction represents space, i.e.,
  the input and output of the circuit are physically accessible from different points in the circuit,
   and they can be measured simultaneously.
@<br>{}
　The quantum version of the NOT gate is the X gate shown in Figure 1.1(b).
 For qubits, the "0" and "1" states are normally written |0⟩, and |1⟩, respectively.
 We will discuss the meaning of this notation in more detail in a future section,
  but for now just consider them to be labels for the two states.
 In this case, the horizontal direction represents time, i.e.,
  the input and output of the circuit represent the state of the same qubit after performing the X gate operation.
 In other words, unlike the usual structure of classical logic,
  a quantum gate represents an operation that you perform on a @<i>{single} qubit or set of qubits.
 The output effectively overwrites the input, and every time a gate is applied it changes the state of the qubit.

=== Superposition
A classical bit must either be a "0" or a "1." In contrast, a qubit can also be in a @<i>{super position state} that is part "0" and part "1."

//image[fig1][Interpretation of classical versus quantum NOT gates.][scale=0.3]{
//}

 If the qubit is in a "1" or "0" state, we say the qubit is in a basis state.@<fn>{fn-1} 

//footnote[fn-1][To be more precise, |0> and |1> are known as the "computational basis" or "standard basis" states. For this chapter, we will restrict our discussion to the standard basis and will simply refer to basis states.]

 For basis states, the state of the qubit can be measured any number of times without changing the state,
  much like measuring the state of a classical gate.
 A superposition state will also yield either a "0" or a "1" when measured, with a probability determined by the mixture.
 In this case the action of making the measurement will "collapse" the superposition state onto one of the constituent basis states,
  and the information stored in the superposition state will be lost.
 For example, If |𝜓⟩ happens to represent a superposition state,
  then measuring the qubit at any time will collapse the state to either |0⟩ or |1⟩, destroying the information in the superposition state.
 From this point on, repeated measurement of the qubit will always yield the same result as the first measurement,
  just like a classical bit.
@<br>{}
　Mathematically the superposition state can be written 

//indepimage[eq_1_1]
#@# \begin{equation}
#@# |\psi\rangle = \alpha |0\rangle + \beta |1\rangle\tag{1.1}
#@# \end{equation}


where α and β are complex constants.

　As mentioned, if such a superposition state is measured,
 it will always give either |0⟩ or |1⟩ but with probabilities of each determined by α and ẞ.
 Specifically, the probabilities of measuring the two possible outcomes are given by

//indepimage[eq_1_2]
#@# \begin{equation}
#@# Pr[0] = |\alpha|^2, \quad Pr[1] = |\beta|^2\tag{1.2}
#@# \end{equation}

If these are the only two possible outcomes of the measurement, then the probabilities must sum to 1, or

//indepimage[eq_1_3]
#@# \begin{equation}
#@# |\alpha|^2 + |\beta|^2 = 1\tag{1.3}
#@# \end{equation}

This ability to represent superposition states is one of the secrets to the power of quantum computing:
 there is a sense in which the qubits are able to explore multiple possibilities in parallel.

=== No Cloning
In a classical logic circuit we can measure the state of a bit at any time, and make as many copies of the state as we want. 
 We can also do this for a qubit if it is known to be in one of the basis states; as described above, 
 we can measure the |0⟩ or |1⟩ state without disturbing it, and we can make as many copies of |0⟩ or |1⟩ as needed.
 @<br>{}
　However, it turns out that it is not possible to create a precise, independent copy of an @<i>{arbitrary} quantum state.
 This is known as @<i>{the no-cloning theorem}.
 We'll show a proof in Section 1.7, but for now let us consider the challenges this poses to the quantum programmer.
 @<br>{}
　For example, we can't get estimates of α or ẞ from running a circuit once.
 Cloning would allow me to run the circuit, make lots of copies of the result,
 and then measure each copy to estimate |𝛼|2 and |𝛽|2 by the probability of measuring |0⟩ or |1⟩. 
 Without cloning, we can only measure the result once.
 To get many measurements, we must run the same computation many times to produce (hopefully!) the same result over and over.
 @<br>{}
　We cannot make copies of states for breakpoints, or to help with debugging or error recovery.
 It is also challenging to apply different operators to a single state during the course of a computation.
 Classical programmers take the ability to copy a state for granted, and this limitation requires some adjustment.
 @<br>{}
　It turns out that it is possible to copy a quantum state using entanglement (Section 1.1.5),
 but only by destroying the state being copied.
 This represents a @<i>{transfer} of state rather than a copy, and is referred to as @<i>{teleportation}.

=== Reversibility

Classical NOT gates are reversible; i.e., two NOT gates in series returns the bit to its original state. 
 However, the situation is different for classical logic gates with multiple inputs.
 As an example, consider the NAND Gate shown in Figure 1.2. 
 It is not possible to uniquely determine the input bits from the output bit. 
 Because of this, conventional multi-input logic is @<i>{irreversible}@<fn>{fn-2} .

//footnote[fn-2][Note: There are classical multi-input logic gates that are reversible, called "conservative logic" gates To date these have not been widely used, but they have the advantage of making it possible in principle to compute without dissipating power(1)]
@<br>{}
　In contrast, quantum gates are reversible. 
 As a result, even though the output overwrites the input, 
 the input is not lost since the effect of a series of gate operations can be reversed by applying the appropriate inverse operations.

=== Entanglement

The fact that we can only calculate the probability of measurement results-not the precise results-on qubits in superposition states allows for a phenomenon that has no classical analog:  @<i>{entanglement}. 
If two qubits are entangled, 
then the states are correlated even though the outcome of a measurement on either of the qubits can only be predicted by its probability. 
For example, if two qubits are entangled, 
then a measurement on one of the qubits will give a result with probability determined by its superposition state, 
just as would happen with an isolated qubit. 
However, once the state of one of the qubits has been collapsed by a measurement, 
the entanglement means that we know exactly what we will get if we measure the second qubit.

//image[fig2][NAND circuit diagram.][scale=0.3]{
//}

@<br>{}
　It is a bit like flipping two coins at the same time, and having them always come up the same, ie., 
 both heads or both tails. Or alternatively, having them always come up opposite-one heads and the other tails. 
 Prior to making a measurement, the states of both of the qubits have not yet been determined. 
 However, when the state of one is collapsed by a measurement, 
 the second qubit somehow instantaneously "knows" the result. 
 This is true regardless of how far apart the qubits are. 
 For example, suppose we entangle two qubits, 
 send one to New York and the other to Tokyo, 
 then make prior arrangements to measure both at the same time. 
 We will discover that the results of the measurements will be correlated even though 
 there was not enough time for a signal traveling the speed of light to travel between the qubits. 
 Einstein called this "spooky action at a distance."
@<br>{}
　If it were possible to control the result of the first measurement, 
 then it would appear that we could communicate faster than the speed of light-violating the principle of special relativity. 
 However, the fact that we cannot control the result of the first measurement means 
 that we cannot actually send any information using this mechanism@<fn>{fn-3}. 

//footnote[fn-3][Entanglement can be used to increase the capacity of a communication channel, however, using a protocol known as super-dense coding.]

@<br>{}
So we can rest comfortably knowing that relativity has not been violated.
@<br>{}
　We will see that the phenomena of @<i>{superposition} and  @<i>{entanglement} give quantum computing 
 its unusual and powerful capabilities.

== Single-Qubit States

Since there are two components in a qubit's state, 
 we can represent the state as a two-dimensional vector, referred to as a state vector. 
 The basis states can be written

//indepimage[eq_1_4]
#@# \begin{equation}
#@# |0\rangle = \begin{bmatrix} 1 \\ 0 \end{bmatrix}, \quad |1\rangle = \begin{bmatrix} 0 \\ 1 \end{bmatrix}.\tag{1.4}
#@# \end{equation}

It follows that we can express a general superposition state as a weighted sum of the basis states:

//indepimage[eq_1_5]
#@# \[
#@# |\psi\rangle = \alpha |0\rangle + \beta |1\rangle = \alpha \begin{bmatrix} 1 \\ 0 \end{bmatrix} + \beta \begin{bmatrix} 0 \\ 1 \end{bmatrix} = \begin{bmatrix} \alpha \\ \beta \end{bmatrix}\tag{1.5}
#@# \]

The notation |𝜓⟩ is called a “ket.” 
 The transpose complex conjugate@<fn>{fn-4} of a ket is denoted ⟨𝜓| and is called a “bra”:

//footnote[fn-4][The transpose of a matrix or vector is formed by interchanging the rows and columns. The transpose of a column vector gives a row vector. The transpose complex conjugate is formed by taking the transpose of the vector or matrix and then taking the complex conjugate of each element.]

//indepimage[eq_1_6]
#@# \begin{equation}
#@# |\psi\rangle^\dagger = \langle \psi | = \begin{bmatrix} \alpha^* & \beta^* \end{bmatrix}\tag{1.6}
#@# \end{equation}

where the † superscript indicates the transpose complex conjugate, 
 also referred to as the Hermitian conjugate, or adjoint. 
 The “bra” and “ket” terminologymay seem strange until you multiply them together to form a “bra-ket.” 
 For example,

//indepimage[eq_1_7]
#@# \begin{equation}
#@# \langle \psi | \psi \rangle = \begin{bmatrix} \alpha^* & \beta^* \end{bmatrix} \begin{bmatrix} \alpha \\ \beta \end{bmatrix} = \alpha^* \alpha + \beta^* \beta\tag{1.7}
#@# \end{equation}

//indepimage[eq_1_8]
#@# \begin{equation}
#@# = |\alpha|^2 + |\beta|^2\tag{1.8}
#@# \end{equation}

(Note that when written as a bra-ket, only a single vertical bar is used in the center.)
 The bra-ket operation (i.e., multiplying a bra and ket) is also referred to as an “innerproduct.” 
 Referring to (1.8), we see that the inner product of a state vector with itself gives the sum of 
 the probabilities that each of the basis states will be obtained in a measurement.
 Since the sum of the probabilities of all possible outcomes must equal 1, we see that the state vectors
 must be properly normalized to a length of unity.

== Measurement and the Born Rule
We have previously stated that the probability of measuring a given component of a superposition state is 
 given by the magnitude squared of its coefficient.
 The act of measuring requires an apparatus that interacts with the qubit in order to extract information.
 The rules of quantum mechanics tell us that the apparatus can only give partial information, 
 related to a set of basis states. 
 For now, we will assume that measurement is always with respect to the standard basis states, |0⟩ and |1⟩, 
 which is the case for most quantum computing systems. 
 However, it is possible for a measurement apparatus to be associated with a different set of basis states. 
 (We will discuss measurement in more detail in later chapters.)
@<br>{}
　When a qubit is measured: (a) the state is changed to one of the basis states associated with the measurement, 
 and (b) the measurement apparatus tells us the resulting state.
 In general, the probability that a state |𝜓⟩ will be found in the basis state |𝑎⟩ when measured is given by

//indepimage[eq_1_9]
#@# \begin{equation}
#@# Pr(|a\rangle) = |\langle \psi | a \rangle|^2\tag{1.9}
#@# \end{equation}

This is called the Born Rule. 
 For example, the probability that the outcome of measuring the state |𝜓⟩ above is |0⟩ , |1⟩ is given by

//indepimage[eq_1_10]
#@# \begin{equation}
#@# Pr(|0\rangle) = |\langle \psi | 0 \rangle|^2 = |\alpha|^2 |\langle 0 | 0 \rangle|^2 = |\alpha|^2\tag{1.10}
#@# \end{equation}

//indepimage[eq_1_11]
#@# \begin{equation}
#@# Pr(|1\rangle) = |\langle \psi | 1 \rangle|^2 = |\beta|^2 |\langle 1 | 1 \rangle|^2 = |\beta|^2\tag{1.11}
#@# \end{equation}

as we found before.

== Unitary Operations and Single-Qubit Gates

We refer to a transformation from one quantum state to another as a gate. 
 The effect of a single qubit gate is to change 𝛼 and 𝛽 into a new mixture 𝛼′ and 𝛽′:

//indepimage[eq_1_12]
#@# \begin{align}
#@# \alpha' &= U_{11} \alpha + U_{12} \beta \notag \\
#@# \beta' &= U_{21} \alpha + U_{22} \beta\tag{1.12}
#@# \end{align}

This can be written as a matrix equation

//indepimage[eq_1_13]
#@# \begin{equation}
#@# \begin{bmatrix}
#@# \alpha' \\
#@# \beta'
#@# \end{bmatrix}
#@# =
#@# \begin{bmatrix}
#@# U_{11} & U_{12} \\
#@# U_{21} & U_{22}
#@# \end{bmatrix}
#@# \begin{bmatrix}
#@# \alpha \\
#@# \beta
#@# \end{bmatrix}\tag{1.13}
#@# \end{equation}

//indepimage[eq_1_14]
#@# \begin{equation}
#@# |\psi'\rangle \equiv U |\psi\rangle\tag{1.14}
#@# \end{equation}

Since the length of the state vector must always be unity, 
 we are only allowed to use matrices 𝑈 that conserve the length of the vector. 
 In other words, ⟨𝜓′|𝜓′⟩ = ⟨𝜓|𝜓⟩ = 1.
 This puts a very important constraint on the matrix 𝑈:

//indepimage[eq_1_15]
#@# \begin{equation}
#@# \langle \psi' | \psi' \rangle = \langle \psi | U^\dagger U | \psi \rangle = 1\tag{1.15}
#@# \end{equation}

using the following observation:

//indepimage[eq_1_16]
#@# \begin{equation}
#@# \langle \psi' | = (U |\psi\rangle)^\dagger = \langle \psi | U^\dagger.\tag{1.16}
#@# \end{equation}

Since ⟨𝜓|𝜓⟩ = 1, we conclude that

//indepimage[eq_1_17]
#@# \begin{equation}
#@# U^\dagger U = I\tag{1.17}
#@# end{equation}

where 𝐼 is the identity matrix

//indepimage[eq_1_18]
#@# \begin{equation}
#@# I = \begin{bmatrix}
#@# 1 & 0 \\
#@# 0 & 1
#@# \end{bmatrix}\tag{1.18}
#@# \end{equation}

Matrices that satisfy this requirement are called unitary matrices. 
 We can view these matrices as performing an operation on a qubit by changing the mixture of basis states.
 Consequently, the matrices 𝑈 are also referred to as unitary operators.
@<br>{}
　The identity matrix 𝐼 can be considered to be the simplest “gate” and leaves the state vector unchanged. 
 Classically, the NOT gate is the only non-trivial single-bit gate. 
 In contrast, there are many non-trivial single qubit quantum gates 
 (technically, the number of 2 × 2 unitary matrices is unlimited). 
 The most common non-trivial single qubit gates are the Pauli-X (𝑋), Pauli-Y (𝑌), Pauli-Z (𝑍), 
 and Hadamard (𝐻) gates defined as follows:

//indepimage[eq_1_19]
#@# \begin{equation}
#@# X = \begin{bmatrix}
#@# 0 & 1 \\
#@# 1 & 0
#@# \end{bmatrix}\tag{1.19}
#@# \end{equation}

//indepimage[eq_1_20]
#@# \begin{equation}
#@# Y = \begin{bmatrix}
#@# 0 & -i \\
#@# i & 0
#@# \end{bmatrix}\tag{1.20}
#@# \end{equation}

//indepimage[eq_1_21]
#@# \begin{equation}
#@# Z = \begin{bmatrix}
#@# 1 & 0 \\
#@# 0 & -1
#@# \end{bmatrix}\tag{1.21}
#@# \end{equation}
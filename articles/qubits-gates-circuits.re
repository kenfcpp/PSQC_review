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

//image[fig_1_1][Interpretation of classical versus quantum NOT gates.][scale=0.3]{
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

The fact that we can only calculate the probability of measurement results-not the precise 
 results-on qubits in superposition states allows for a phenomenon that has no classical analog:  @<i>{entanglement}. 
 If two qubits are entangled, 
 then the states are correlated even though the outcome of a measurement on either of the qubits can only be predicted by its probability. 
 For example, if two qubits are entangled, 
 then a measurement on one of the qubits will give a result with probability determined by its superposition state, 
 just as would happen with an isolated qubit. 
 However, once the state of one of the qubits has been collapsed by a measurement, 
 the entanglement means that we know exactly what we will get if we measure the second qubit.

//image[fig_1_2][NAND circuit diagram.][scale=0.3]{
//}

@<br>{}
　It is a bit like flipping two coins at the same time, and having them always come up the same, ie., both heads or both tails. 
 Or alternatively, having them always come up opposite-one heads and the other tails. 
 Prior to making a measurement, the states of both of the qubits have not yet been determined. 
 However, when the state of one is collapsed by a measurement, 
 the second qubit somehow instantaneously "knows" the result. 
 This is true regardless of how far apart the qubits are. 
 For example, suppose we entangle two qubits, send one to New York and the other to Tokyo, 
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

//indepimage[eq_1_22]
#@# \begin{equation}
#@# H = \frac{1}{\sqrt{2}} \begin{bmatrix} 1 & 1 \\ 1 & -1 \end{bmatrix}\tag{1.22}
#@# \end{equation}

To get an understanding of what these gates do, consider applying an 𝑋 gate to the “ground” state |0⟩:

//indepimage[eq_1_23]
#@# \begin{equation}
#@# X |0\rangle = \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} 1 \\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\ 1 \end{bmatrix} = |1\rangle\tag{1.23}
#@# \end{equation}

Similarly,

//indepimage[eq_1_24]
#@# \begin{equation}
#@# X |1\rangle = \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} 0 \\ 1 \end{bmatrix} = \begin{bmatrix} 1 \\ 0 \end{bmatrix} = |0\rangle\tag{1.24}
#@# \end{equation}

We see then that the 𝑋 gate is a “bit flip” gate, and transforms |0⟩ into |1⟩ and vice versa.
 This, then is the analog of the classicalNOT gate.You should verify the following results from applying 𝑌, 
 𝑍, and 𝐻 gates:

//indepimage[eq_1_25]
#@# \begin{equation}
#@# Y |0\rangle = i |1\rangle, \quad Y |1\rangle = -i |0\rangle\tag{1.25}
#@# \end{equation}

//indepimage[eq_1_26]
#@# \begin{equation}
#@# Z |0\rangle = |0\rangle, \quad Z |1\rangle = -|1\rangle\tag{1.26}
#@# \end{equation}

//indepimage[eq_1_27]
#@# \begin{equation}
#@# H |0\rangle = \frac{1}{\sqrt{2}} (|0\rangle + |1\rangle), \quad
#@# H |1\rangle = \frac{1}{\sqrt{2}} (|0\rangle - |1\rangle)\tag{1.27}
#@# \end{equation}

In addition, it is interesting to note that each one of these matrices is its own Hermitian conjugate. 
 Consequently, these four gates have the property that applying them twice gives the identity matrix:

//indepimage[eq_1_28]
#@# \begin{equation}
#@# X^2 = Y^2 = Z^2 = H^2 = I\tag{1.28}
#@# \end{equation}

Note that while 𝑋,𝑌, and 𝑍 gates transform between the |0⟩ and |1⟩ states, 
 the Hadamard gate actually creates a superposition state, and therefore will prove to be
 particularly useful. 
 The states resulting from applying 𝐻 to the basis states are given their own names:

//indepimage[eq_1_29]
#@# \begin{equation}
#@# |+\rangle \equiv H |0\rangle = \frac{|0\rangle + |1\rangle}{\sqrt{2}}\tag{1.29}
#@# \end{equation}

//indepimage[eq_1_30]
#@# \begin{equation}
#@# |-\rangle \equiv H |1\rangle = \frac{|0\rangle - |1\rangle}{\sqrt{2}}\tag{1.30}
#@# \end{equation}

Multiple gates can be sequentially applied to a qubit by matrix multiplication:

//indepimage[eq_1_31]
#@# \begin{equation}
#@# XYH\,|0\rangle\tag{1.31}
#@# \end{equation}

This expression says that we start with the ground state, then apply a Hadamard gate, followed by a 
 Pauli-Y and then a Pauli-Z.
 Note that this process conceptually moves from right to left. 
 This computation can be represented by a quantum circuit diagram as shown in Figure 1.3. 
 Note that the process moves from left to right on the circuit diagram: 

//image[fig_1_3][Circuit representation of Eq. (1.31). In a quantum circuit diagram, the operation goes from left to right, while the matrix expression is shown going from right to left. The final box is a measurement in the standard basis, resulting in a classical bit.][scale=0.3]{
//}

 we begin with the ground state on the left, then apply a Hadamard gate, a Pauli-Y gate, and a Pauli-X.
@<br>{}
　Finally, after performing a quantum calculation, we generally measure each qubit.
 The symbol for a measurement is shown as the last element in Figure 1.3. 
 This action collapses the final state onto one of the basis states. 
 The outcome of a measurement is a classical bit that is stored in a classical register. 
 “Quantum wires” are denoted by solid lines, and “classical wires” are denoted with double lines. 
 A quantum wire simply represents a time-interval over which the state is kept unchanged.

== Two-Qubit Gates

It is also possible to have gates with multiple qubits as inputs. 
 However, unlike classical multi-bit gates, the fact that quantum gates are reversible requires 
 that there must be the same number of output qubits as input qubits. 
 In this section we will explore some common two-qubit gates.

=== Two-Qubit States

When we consider a system with two qubits, we don’t just consider each qubit independently of the other. 
 Instead, this forms a two-qubit system with its own set of basis states. 
 If we know the state of each qubit, then the combined two-qubit state is described using 
 the tensor product of the two state vectors, defined as follows:

//indepimage[eq_1_32]
#@# \begin{equation}
#@# \begin{bmatrix}
#@# a \\
#@# b
#@# \end{bmatrix}
#@# \otimes
#@# \begin{bmatrix}
#@# c \\
#@# d
#@# \end{bmatrix}
#@# =
#@# \begin{bmatrix}
#@# a \begin{bmatrix} c \\ d \end{bmatrix} \\
#@# b \begin{bmatrix} c \\ d \end{bmatrix}
#@# \end{bmatrix}
#@# =
#@# \begin{bmatrix}
#@# ac \\
#@# ad \\
#@# bc \\
#@# bd
#@# \end{bmatrix}\tag{1.32}
#@# \end{equation}

Using the standard basis, the basis states for a two-qubit system are defined by combinations of the |0⟩ and |1⟩ states:

//indepimage[eq_1_33]
#@# \begin{equation}
#@# |00\rangle = |0\rangle \otimes |0\rangle =
#@# \begin{bmatrix}
#@# 1 \times
#@# \begin{bmatrix}
#@# 1 \\
#@# 0
#@# \end{bmatrix} \\
#@# 0 \times
#@# \begin{bmatrix}
#@# 1 \\
#@# 0
#@# \end{bmatrix}
#@# \end{bmatrix}
#@# =
#@# \begin{bmatrix}
#@# 1 \\
#@# 0 \\
#@# 0 \\
#@# 0
#@# \end{bmatrix}\tag{1.33}
#@# \end{equation}

//indepimage[eq_1_34]
#@# \begin{equation}
#@# |01\rangle = |0\rangle \otimes |1\rangle =
#@# \begin{bmatrix}
#@# 1 \times \begin{bmatrix} 0 \\ 1 \end{bmatrix} \\
#@# 0 \times \begin{bmatrix} 0 \\ 1 \end{bmatrix}
#@# \end{bmatrix}
#@# =
#@# \begin{bmatrix}
#@# 0 \\
#@# 1 \\
#@# 0 \\
#@# 0
#@# \end{bmatrix}\tag{1.34}
#@# \end{equation}

//indepimage[eq_1_35]
#@# \begin{equation}
#@# |10\rangle = |1\rangle \otimes |0\rangle =
#@# \begin{bmatrix}
#@# 0 \times \begin{bmatrix} 1 \\ 0 \end{bmatrix} \\
#@# 1 \times \begin{bmatrix} 1 \\ 0 \end{bmatrix}
#@# \end{bmatrix}
#@# =
#@# \begin{bmatrix}
#@# 0 \\
#@# 0 \\
#@# 1 \\
#@# 0
#@# \end{bmatrix}\tag{1.35}
#@# \end{equation}

//indepimage[eq_1_36]
#@# \begin{equation}
#@# |11\rangle = |1\rangle \otimes |1\rangle =
#@# \begin{bmatrix}
#@# 0 \times \begin{bmatrix} 0 \\ 1 \end{bmatrix} \\
#@# 1 \times \begin{bmatrix} 0 \\ 1 \end{bmatrix}
#@# \end{bmatrix}
#@# =
#@# \begin{bmatrix}
#@# 0 \\
#@# 0 \\
#@# 0 \\
#@# 1
#@# \end{bmatrix}\tag{1.36}
#@# \end{equation}

Any two-qubit state can be written as a linear combination of the basis states:

//indepimage[eq_1_37]
#@# \begin{equation}
#@# |\psi\rangle = \alpha_{00} |00\rangle + \alpha_{01} |01\rangle + \alpha_{10} |10\rangle + \alpha_{11} |11\rangle\tag{1.37}
#@# \end{equation}

Two-qubit state vectors are also normalized:

//indepimage[eq_1_38]
#@# \begin{equation}
#@# |\alpha_{00}|^2 + |\alpha_{01}|^2 + |\alpha_{10}|^2 + |\alpha_{11}|^2 = 1\tag{1.38}
#@# \end{equation}

As we will see later, while every two-qubit state can be written in the form of Eq. (1.37),
 not every two-qubit state can be written as the tensor product of single-qubit states.
 This can be generalized into a system with 𝑛 qubits, requiring state vectors with 2𝑛 components 
 with 2𝑛 complex coefficients.

=== Matrix Representation of Two-Qubit Gates

Just as single qubit gates can be represented by 2 × 2 matrices, an 𝑛-qubit gate can be represented bya 2𝑛 ×2𝑛 matrix. 
 Consequently two-qubit gates require the construction of 4×4 unitary matrices. 
 Given two single-qubit operators 𝐴 and 𝐵, the tensor product is defined as:

//indepimage[eq_1_39]
#@# \begin{equation}
#@# A \otimes B \equiv
#@# \begin{bmatrix}
#@# A_{11} B & A_{12} B \\
#@# A_{21} B & A_{22} B
#@# \end{bmatrix}
#@# =
#@# \begin{bmatrix}
#@# A_{11}
#@# \begin{bmatrix}
#@# B_{11} & B_{12} \\
#@# B_{21} & B_{22}
#@# \end{bmatrix}
#@# & 
#@# A_{12}
#@# \begin{bmatrix}
#@# B_{11} & B_{12} \\
#@# B_{21} & B_{22}
#@# \end{bmatrix}
#@# \\[10pt]
#@# A_{21}
#@# \begin{bmatrix}
#@# B_{11} & B_{12} \\
#@# B_{21} & B_{22}
#@# \end{bmatrix}
#@# & 
#@# A_{22}
#@# \begin{bmatrix}
#@# B_{11} & B_{12} \\
#@# B_{21} & B_{22}
#@# \end{bmatrix}
#@# \end{bmatrix}\tag{1.39}
#@# \end{equation}

which creates a 4 × 4 matrix.
@<br>{}
　Suppose we wanted to construct a two-qubit circuit starting in the state |10⟩ with an
 X gate applied to the left qubit, and a Y gate applied to the other. 
 Mathematically this would be written

//indepimage[eq_1_40]
#@# \begin{equation}
#@# X \otimes Y|10\rangle .\tag{1.40}
#@# \end{equation}

Referring to (1.24) we see that the X gate will simply flip the left qubit, and referring to (1.25)
 we see that the Y gate will flip the right qubit and add the coefficient 𝑖. 
 We conclude that

//indepimage[eq_1_41]
#@# \begin{equation}
#@# X \otimes Y|10\rangle=i|01\rangle.\tag{1.41}
#@# \end{equation}

To see how this would be implemented using the matrix representation, we first construct the 𝑋 ⊗ 𝑌 matrix:

//indepimage[eq_1_42]
#@# \begin{equation}
#@# X \otimes Y=\left[\begin{array}{cc}
#@# 0\left[\begin{array}{cc}
#@# 0 & -i \\
#@# i & 0
#@# \end{array}\right] & 1\left[\begin{array}{cc}
#@# 0 & -i \\
#@# i & 0
#@# \end{array}\right] \\
#@# 1\left[\begin{array}{cc}
#@# 0 & -i \\
#@# i & 0
#@# \end{array}\right] & 0\left[\begin{array}{cc}
#@# 0 & -i \\
#@# i & 0
#@# \end{array}\right]
#@# \end{array}\right]=\left[\begin{array}{cccc}
#@# 0 & 0 & 0 & -i \\
#@# 0 & 0 & i & 0 \\
#@# 0 & -i & 0 & 0 \\
#@# i & 0 & 0 & 0
#@# \end{array}\right] .\tag{1.42}
#@# \end{equation}

Completing the calculation gives the expected result:

//indepimage[eq_1_43]
#@# \begin{equation}
#@# X \otimes Y|10\rangle=\left[\begin{array}{cccc}
#@# 0 & 0 & 0 & -i \\
#@# 0 & 0 & i & 0 \\
#@# 0 & -i & 0 & 0 \\
#@# i & 0 & 0 & 0
#@# \end{array}\right]\left[\begin{array}{l}
#@# 0 \\
#@# 0 \\
#@# 1 \\
#@# 0
#@# \end{array}\right]=i\left[\begin{array}{l}
#@# 0 \\
#@# 1 \\
#@# 0 \\
#@# 0
#@# \end{array}\right]=i|01\rangle .\tag{1.43}
#@# \end{equation}

A particularly interesting two-qubit circuit is formed by applying a Hadamard gate to each qubit 
 in the ground state: 𝐻 ⊗ 𝐻 |00⟩. 
 Let us first compute 𝐻 ⊗ 𝐻:

//indepimage[eq_1_44]
#@# \begin{equation}
#@# H \otimes H=\frac{1}{2}\left[\begin{array}{cc}
#@# 1\left[\begin{array}{cc}
#@# 1 & 1 \\
#@# 1 & -1
#@# \end{array}\right] & 1\left[\begin{array}{cc}
#@# 1 & 1 \\
#@# 1 & -1
#@# \end{array}\right] \\
#@# 1\left[\begin{array}{cc}
#@# 1 & 1 \\
#@# 1 & -1
#@# \end{array}\right] & -1\left[\begin{array}{cc}
#@# 1 & 1 \\
#@# 1 & -1
#@# \end{array}\right]
#@# \end{array}\right]=\frac{1}{2}\left[\begin{array}{cccc}
#@# 1 & 1 & 1 & 1 \\
#@# 1 & -1 & 1 & -1 \\
#@# 1 & 1 & -1 & -1 \\
#@# 1 & -1 & -1 & 1
#@# \end{array}\right].\tag{1.44}
#@# \end{equation}

Completing the calculation gives:

//indepimage[eq_1_45]
#@# \begin{equation}
#@# H \otimes H|00\rangle=\frac{1}{2}\left[\begin{array}{cccc}
#@# 1 & 1 & 1 & 1 \\
#@# 1 & -1 & 1 & -1 \\
#@# 1 & 1 & -1 & -1 \\
#@# 1 & -1 & -1 & 1
#@# \end{array}\right]\left[\begin{array}{l}
#@# 1 \\
#@# 0 \\
#@# 0 \\
#@# 0
#@# \end{array}\right]=\frac{1}{2}\left[\begin{array}{l}
#@# 1 \\
#@# 1 \\
#@# 1 \\
#@# 1
#@# \end{array}\right].\tag{1.45}
#@# \end{equation}

Note that the resulting state vector can be decomposed into a sum of all of the two-qubit basis states:

//indepimage[eq_1_46]
#@# \begin{equation}
#@# \frac{1}{2}\left[\begin{array}{l}
#@# 1 \\
#@# 1 \\
#@# 1 \\
#@# 1
#@# \end{array}\right]=\frac{1}{2}\left[\begin{array}{l}
#@# 1 \\
#@# 0 \\
#@# 0 \\
#@# 0
#@# \end{array}\right]+\frac{1}{2}\left[\begin{array}{l}
#@# 0 \\
#@# 1 \\
#@# 0 \\
#@# 0
#@# \end{array}\right]+\frac{1}{2}\left[\begin{array}{l}
#@# 0 \\
#@# 0 \\
#@# 1 \\
#@# 0
#@# \end{array}\right]+\frac{1}{2}\left[\begin{array}{l}
#@# 0 \\
#@# 0 \\
#@# 0 \\
#@# 1
#@# \end{array}\right].\tag{1.46}
#@# \end{equation}

or alternatively

//indepimage[eq_1_47]
#@# \begin{equation}
#@# H \otimes H|00\rangle=\frac{1}{2}(|00\rangle+|01\rangle+|10\rangle+|11\rangle).\tag{1.47}
#@# \end{equation}

We see that application of Hadamard gates to each qubit creates an equally weighted superposition of 
 all possible basis states. 
 This is often a very useful starting point for a quantum calculation.
 @<br>{}
　Although the matrix representation can be helpful in understanding the operations,
calculations can often be done more compactly once the effect of the gates are understood.
 For example, we could write 𝐻 ⊗ 𝐻 |00⟩ = 𝐻 ⊗ 𝐻 |0⟩ |0⟩, apply the Hadamard gates to each qubit, 
 and simplify:
 
//indepimage[eq_1_48]
#@# \begin{align}
#@# H \otimes H\, |00\rangle &= H\,|0\rangle \otimes H\,|0\rangle \notag \\
#@# &= \left( \frac{|0\rangle + |1\rangle}{\sqrt{2}} \right) \otimes \left( \frac{|0\rangle + |1\rangle}{\sqrt{2}} \right) \notag \\\tag{1.48}
#@# &= \frac{1}{2} \left( |00\rangle + |01\rangle + |10\rangle + |11\rangle \right)\tag{1.48}
#@# \end{align}

We conclude this section with a comment on notation. 
 A more compact notation is often used for situations where the same operator is applied across multiple qubits; i.e.,
 𝐻 ⊗ 𝐻 is alternatively written 𝐻⊗2, 𝐻 ⊗ 𝐻 ⊗ 𝐻 = 𝐻⊗3, etc.

=== Controlled-NOT

The gates that we have considered so far involve operations that are independently applied to separate 
 qubits—there is no qubit–qubit interaction. 
 If we are to entangle two qubits, then we need classes of gates where the operation on one qubit depends
 on the state of another. 
 One of the most important such gates is the controlled-NOT,or CNOT gate. 
 For this gate, one of the input qubits is the “control,” and the other is the “target.” 
 If the control qubit is zero, then nothing is done to the target qubit, but if the control qubit is one, 
 then the target qubit is flipped. 
 For example, if the right qubit in our notation is the control and the left qubit is the target, 
 then the CNOT gate transforms the basis states as follows:

//indepimage[eq_1_49]
#@# \begin{align}
#@# U_{\text{CN}}\,|00\rangle &= |00\rangle \notag\\
#@# U_{\text{CN}}\,|01\rangle &= |11\rangle \notag\\
#@# U_{\text{CN}}\,|10\rangle &= |10\rangle \notag\\
#@# U_{\text{CN}}\,|11\rangle &= |01\rangle\tag{1.49}
#@# \end{align}

The effect of a CNOT can be compactly represented by 𝑈CN |𝑡⟩ |𝑐⟩ = |𝑐 ⊕ 𝑡⟩ |𝑐⟩, where ⊕represents 
 exclusive-OR or modulo-2 addition (e.g., 0+1=1, but 1+1=0). 
 The matrix representation of the CNOT gate is

//indepimage[eq_1_50]
#@# \begin{align}
#@# U_{\text{CN}} =
#@# \begin{bmatrix}
#@# 1 & 0 & 0 & 0 \\
#@# 0 & 0 & 0 & 1 \\
#@# 0 & 0 & 1 & 0 \\
#@# 0 & 1 & 0 & 0
#@# \end{bmatrix} 
#@# \tag{1.50}
#@# \end{align}

and the circuit symbol is shown in Figure 1.4.
@<br>{}
　It isworth noting at this point thatwe are putting the least-significant qubit at the top of a circuit diagram, 
 and on the right on the state labels used with kets. 
 This labels states with the natural binary order. 

//image[fig_1_4][Symbol for a CNOT gate, and its effect on basis states.][scale=0.3]{
//}

 However, there are different conventions in use, and this can be a point of confusion. 
 Some authors put the top-most qubit in a circuit diagram on the left when they label kets. 
 In this alternate notation, 𝑈′ 𝐶𝑁 |𝑐⟩ |𝑡⟩ = |𝑐⟩ |𝑐 ⊕ 𝑡⟩ so that

//indepimage[eq_1_51]
#@# \begin{align}
#@# U'_{\text{CN}}\,|00\rangle &= |00\rangle \notag\\
#@# U'_{\text{CN}}\,|01\rangle &= |01\rangle \notag\\
#@# U'_{\text{CN}}\,|10\rangle &= |11\rangle \notag\\
#@# U'_{\text{CN}}\,|11\rangle &= |10\rangle\tag{1.51}
#@# \end{align}

The matrix representation of the CNOT gate in this alternate convention is

//indepimage[eq_1_52]
#@# \begin{align}
#@# U'_{\text{CN}} =
#@# \begin{bmatrix}
#@# 1 & 0 & 0 & 0 \\
#@# 0 & 1 & 0 & 0 \\
#@# 0 & 0 & 0 & 1 \\
#@# 0 & 0 & 1 & 0
#@# \end{bmatrix}
#@# \tag{1.52}
#@# \end{align}

We will consistently use the first convention, with the least-significant qubit (top-most on a circuit diagram)
 on the right when writing state labels.

== Bell State

Consider the circuit shown in Figure 1.5. The circuit can be described mathematically as 𝑈CN (𝐼 ⊗ 𝐻) |00⟩. 
 Here the expression 𝐼⊗𝐻 simply means a Hadamard gate is applied to the right qubit, 
 and the identity matrix applied to the left qubit (which leaves the left qubit unchanged). 
 Completing the calculation gives

//indepimage[eq_1_53]
#@# \begin{align}
#@# U_{\text{CN}} \left( I \otimes H \right) |00\rangle
#@# = U_{\text{CN}} \left( |0\rangle \otimes \frac{|0\rangle + |1\rangle}{\sqrt{2}} \right)
#@# \tag{1.53}
#@# \end{align}

//indepimage[eq_1_54]
#@# \begin{align}
#@# = \frac{1}{\sqrt{2}}\, U_{\text{CN}} \left( |00\rangle + |01\rangle \right)
#@# \tag{1.54}
#@# \end{align}

//indepimage[eq_1_55]
#@# \begin{align}
#@# = \frac{1}{\sqrt{2}} \left( |00\rangle + |11\rangle \right)
#@# \tag{1.55}
#@# \end{align}

Note that there is no way to factor this state into (qubit 1 state) ⊗ (qubit 0 state). 
 This is known as a Bell State, and it is an example of an entangled state, as described in Section 1.1.5.
@<br>{}
　If we measure the state of one of the qubits in (1.55), then we will obtain either a zero or a one 
 with equal probability, as we would expect. 
 The unusual behavior happens when we measure the second qubit: if we measure |0⟩ on the first qubit,
 then we know the state has collapsed to |00⟩, so a measurement of the second qubit will also yield
 |0⟩. Similarly, if the first measurement yields |1⟩, then the state must have collapsed to |11⟩,
 so a measurement of the second qubit will also yield |1⟩. 

//image[fig_1_5][Circuit for creating an entangled state known as a Bell State. When the two qubits are measured, they will either both be 0, or they will both be 1.][scale=0.3]{
//}

//image[fig_1_6][Result of executing the circuit 1024 times on a quantum simulator, compared with executing the circuit 1024 times on a real IBM quantum computer.][scale=0.3]{
//}

 The measurements are correlated, no matter how far apart the physical qubits might be.
 @<br>{}
　We simulated the Bell circuit using IBM’s Qiskit [2], and also executed the circuit on real IBM Quantum hardware. 
 A histogram illustrating the results of simulating the circuit 1024 times 
 (each execution is referred to as a “shot”) is shown in Figure 1.6.
 From (1.55), we see that the probability amplitudes of the states |00⟩ and |11⟩ are both equal to 1∕√2.
 Since the probability of measuring a state is the absolute magnitude squared of the amplitude, 
 the probability of measuring each state is 1∕2. 
 Consistent with this, the measurements from the 1024 shots are roughly equally divided between the states 
 |00⟩ and |11⟩, with no other states occurring.
 @<br>{}
　The simulator gives the result expected from an error-free quantum processor. 
 In contrast, the quantum processors available today are noisy and contain errors. 
 As an illustration, Figure 1.6 also shows the result of executing 1024 shots on a real IBM Quantum processor. 
 Although the states |00⟩ and |11⟩ do occur most frequently, the error states |01⟩ and |10⟩ occasionally occur as well. 
 Fortunately there are techniques to reduce and partially mitigate such noise (Chapter 9), 
 and these techniques represent an active area of research.

== No Cloning, Revisited

With a better understanding of quantum states and operations, we are now ready to construct a proof of the no-cloning theorem. 
 The proof relies on the fact that unitary operators are linear; when applied to a sum of states, the operator operates
 independently on each component:

//indepimage[eq_1_56]
#@# \begin{equation}
#@# U \left( |\psi\rangle + |\phi\rangle \right) = U |\psi\rangle + U |\phi\rangle\tag{1.56}
#@# \end{equation}

Suppose we have an operator 𝑈clone that takes two qubits, as shown in Figure 1.7.
 When the second qubit is |0⟩, it is replaced with an exact copy of the first qubit. 
 The proof will show that such an operator cannot exist, because it is not compatible with the principle of linearity.

//image[fig_1_7][Hypothetical cloning operator, that creates an exact and independent copy of unknown quantum state |𝛼⟩. The text will show that such an operator cannot be implemented.][scale=0.3]{
//}

@<br>{}
　Further suppose that we have two states:

//indepimage[eq_1_57]
#@# \begin{equation}
#@# |\alpha\rangle=a_0|0\rangle+a_1|1\rangle \tag{1.57}
#@# \end{equation}

//indepimage[eq_1_58]
#@# \begin{equation}
#@# & |\beta\rangle=b_0|0\rangle+b_1|1\rangle\tag{1.58}
#@# \end{equation}

By the definition of cloning:

//indepimage[eq_1_59]
#@# \begin{equation}
#@# \begin{aligned}
#@# & U_{\text {clone }}|\alpha\rangle|0\rangle=|\alpha\rangle|\alpha\rangle=|\alpha \alpha\rangle, \\
#@# & U_{\text {clone }}|\beta\rangle|0\rangle=|\beta\rangle|\beta\rangle=|\beta \beta\rangle 
#@# \end{aligned}.\tag{1.59}
#@# \end{equation}

@<br>{}
　Now consider a new state |𝛿⟩ = (|𝛼⟩ + |𝛽⟩)∕√2. 
By the definition of cloning:

//indepimage[eq_1_60]
#@# \begin{equation}
#@# \begin{aligned}
#@# U_{\text {clone }}|\delta\rangle|0\rangle & =|\delta\rangle|\delta\rangle \\
#@# & =\frac{|\alpha\rangle+|\beta\rangle}{\sqrt{2}} \otimes \frac{|\alpha\rangle+|\beta\rangle}{\sqrt{2}} \\
#@# & =\frac{1}{2}(|\alpha \alpha\rangle+|\alpha \beta\rangle+|\beta \alpha\rangle+|\beta \beta\rangle)
#@# \end{aligned}\tag{1.60}
#@# \end{equation}

However, by the linearity of unitary operators:

//indepimage[eq_1_61]
#@# \begin{equation}
#@# \begin{aligned}
#@# U_{\text {clone }}|\delta\rangle|0\rangle & =\frac{1}{\sqrt{2}} U_{\text {clone }}(|\alpha\rangle|0\rangle+|\beta\rangle|0\rangle) \\
#@# & =\frac{|\alpha \alpha\rangle+|\beta \beta\rangle}{\sqrt{2}}
#@# \end{aligned}\tag{1.61}
#@# \end{equation}

@<br>{}
　Since Eqs. (1.60) and (1.61) cannot both be true, there is no unitary 𝑈clone that can perform the cloning operation for all states.
 We stated earlier that we can clone a (computational) basis state. 
 This can be done with the CNOT gate, with the first qubit as the control. 
 (With our bottom-to-top ordering, this corresponds to the 𝑈′CN operator from (1.52).) 
 Suppose state |𝜓⟩ is either |0⟩ or |1⟩, but we don’t know which.

//indepimage[eq_1_62]
#@# \begin{equation}
#@# U_{\mathrm{CN}}^{\prime}|\psi\rangle|0\rangle=\left\{\begin{array}{l}
#@# U_{\mathrm{CN}}^{\prime}|00\rangle=|00\rangle, \text { if }|\psi\rangle=|0\rangle \\
#@# U_{\mathrm{CN}}^{\prime}|10\rangle=|11\rangle, \text { if }|\psi\rangle=|1\rangle
#@# \end{array}\right\}=|\psi \psi\rangle\tag{1.62}
#@# \end{equation}

If we apply the circuit from Figure 1.5 to an arbitrary state |𝜓⟩ = 𝛼 |0⟩+𝛽 |1⟩, 
 we get a result that looks sort of like cloning, but not quite:

//indepimage[eq_1_63]
#@# \begin{equation}
#@# U_{\mathrm{CN}}(I \otimes H)|0\rangle|\psi\rangle=\frac{\alpha|00\rangle+\beta|11\rangle}{\sqrt{2}}\tag{1.63}
#@# \end{equation}

The result is not cloning because the two qubits are entangled. 
 We did not succeed in creating two independent copies of |𝜓⟩. 
 This is a useful construct, however, and can be extended to create 𝑛-qubit states that look like this:

//indepimage[eqe_1_1]
#@# \begin{equation}
#@# \frac{\alpha\,|0000\ldots\rangle + \beta\,|1111\ldots\rangle}{2^{n/2}}\notag
#@# \end{equation}

 These states will be useful for quantum error correction codes (Chapter 10).

== Example: Deutsch’s Problem

We now have enough quantum computing “machinery” to work out a simple example of a quantum algorithm. 
 The example algorithm is admittedly not very useful, 
 but it provides some important insights into how quantum computers can outperform classical computers.
@<br>{}
　Consider a function that takes a single binary digit as input, and provides a single binary digit as output. 
 There are four possible functions: 𝑓1(𝑥) = 0, 𝑓2(𝑥) = 1, 𝑓3(𝑥) = 𝑥, and 𝑓4(𝑥) = 𝑥̄ . 
 Suppose someone gave us an implementation of one of these functions in a black box, 
 and asked us to determine whether 𝑓(0) = 𝑓(1), or if 𝑓(0) ≠ 𝑓(1). 
 Classically, we could do this in two function calls, one with 𝑥 = 0, and one with 𝑥 = 1. 
 However, using a quantum algorithm we can answer this question with a single function call! Let’s see how this could be done.
@<br>{}
　First, suppose that we have the gate 𝑈 shown in Figure 1.8(a) for implementing the function 𝑓(𝑥). 
 The function is implemented by changing the sign of the state: if 𝑓(𝑥) = 0 then the sign is unchanged, 
 and if 𝑓(𝑥) = 1 then the sign of the state is flipped.
 We will return to the question of how to implement this gate shortly, but for now let us assume that the gate is given to us, 
 and our job is to determine if 𝑓(0) = 𝑓(1) or 𝑓(0) ≠ 𝑓(1).
 Now consider the circuit shown in Figure 1.8(b). 
 Applying the Hadamard gate to the input |0⟩ gives

//indepimage[eq_1_64]
#@# \begin{equation}
#@# \psi_1 = \frac{1}{\sqrt{2}} \left( |0\rangle + |1\rangle \right)\tag{1.64}
#@# \end{equation}

Note that the Hadamard gate enables us to apply 𝑈 to both |0⟩ and |1⟩ at the same time. 
 This is referred to as quantum parallelism and is one of the secrets behind the power of quantum computing 
 (although there are some key qualifications that make this somewhat less exciting than it would seem at first!).
@<br>{}
　Continuing with the calculation, we next compute 𝜓2 = 𝑈𝜓1 to obtain

//indepimage[eq_1_65]
#@# \begin{equation}
#@# \psi_2 = \frac{1}{\sqrt{2}} \left( (-1)^{f(0)} |0\rangle + (-1)^{f(1)} |1\rangle \right)\tag{1.65}
#@# \end{equation}

//image[fig_1_8][Conceptual illustration of the Deutsch Problem.][scale=0.3]{
//}

Applying the second Hadamard gate gives the final output:

//indepimage[eq_1_66]
#@# \begin{align}
#@# H\psi_2\tag{1.66}
#@# &= \frac{1}{2} \left[ (-1)^{f(0)} (|0\rangle + |1\rangle) + (-1)^{f(1)} (|0\rangle - |1\rangle) \right]\\
#@# &= \frac{1}{2} \left[ \left( (-1)^{f(0)} + (-1)^{f(1)} \right) |0\rangle + \left( (-1)^{f(0)} - (-1)^{f(1)} \right) |1\rangle \right]\tag{1.67}
#@# \end{align}

Examining (1.67), we see that if 𝑓(0) = 𝑓(1) the second term vanishes and the output is |0⟩. 
 In contrast, when 𝑓(0) ≠ 𝑓(1), then the first term vanishes and the output is ±|1⟩. 
 Therefore, if we measure the output as |0⟩, we know that 𝑓(0) = 𝑓(1), while if we measure |1⟩, we know that is not the case. 
 (Our measuring device will ignore the minus sign and show us a result of “1” if the output state is −|1⟩.)
@<br>{}
　Arranging for the amplitudes of the correct states to add and others to cancel is an example of quantum interference, 
 another key principle underlying quantum computing.
 So we see that in a single function call, we are able to determine whether or not 𝑓(𝑥) is balanced or 
 constant—a feat that would only be possible classically with two function calls!
@<br>{}
　Now let us turn our attention to how the gate 𝑈 can be realized. 
 First, we have to confess that the circuit in Figure 1.8 is hiding something: we need another qubit to implement the 𝑈 gate.
@<br>{}
　Consider the function 𝑓(𝑥) = 0. We want a unitary 𝑈𝑓 that converts |𝑥⟩ to |𝑓(𝑥)⟩, but this is clearly not reversible. 
 Given an output of |0⟩, there’s no way to know whether the input is |1⟩ or |0⟩. 
 To make the function reversible, we need to include both 𝑓(𝑥) and 𝑥 in the output, 
 so that we can reconstruct the input when reversing the operation.
@<br>{}
　For two outputs, we need two inputs. 
 We typically use |0⟩ as second input, but to be more general, let’s assume that the second input can be any input |𝑦⟩. 
 With |𝑥⟩ and |𝑦⟩ as the inputs, the outputs will be |𝑥⟩ and |𝑦 ⊕ 𝑓(𝑥)⟩, where ⊕ is the standard Boolean exclusive-OR (XOR) operation. 
 As shown in Figure 1.9, this function is its own inverse; if we use |𝑥⟩ and |𝑦 ⊕ 𝑓(𝑥)⟩ as the input, 
 we get |𝑥⟩ and |𝑦 ⊕ 𝑓(𝑥) ⊕ 𝑓(𝑥)⟩ = |𝑦⟩ as the output.
@<br>{}
　Figure 1.10 shows the four alternative implementations of 𝑈𝑓, depending on which version of 𝑓(𝑥) we want. 
 From left to right:

 * 𝑓1(𝑥) = 0, do nothing to 𝑦, equivalent to 𝑦 ⊕ 0.
 * 𝑓2(𝑥) = 1, flip 𝑦 using a NOT gate, equivalent to 𝑦 ⊕ 1.
 * 𝑓3(𝑥) = 𝑥, use a CNOT gate to flip 𝑦 if 𝑥 = 1, equivalent to 𝑦 ⊕ 𝑥.
 * 𝑓4(𝑥) = 𝑥̄ , flip 𝑥 and then XOR with 𝑦 using a CNOT gate, equivalent to 𝑦 ⊕ 𝑥̄ . Wethen use another NOT gate to restore 𝑥 to its original value.
@<br>{}
　Now, using our 𝑈𝑓 circuit, we will compute (−1)𝑓(𝑥) |𝑥⟩ using a technique known as phase kickback. 
 If we set |𝑦⟩ = |−⟩ = (|0⟩ − |1⟩)∕√2), then the top output of 𝑈𝑓 willremain |−⟩ and the bottom output will be |𝑥⟩ if 𝑓(𝑥) = 0 and will be −|𝑥⟩ if 𝑓(𝑥) = 1.
 Let’s do the math.

//image[fig_1_9][Reversible circuit for calculating f(x).][scale=0.3]{
//}

//image[fig_1_10][Implementations of black-box function Uf for Deutsch’s problem. Top output is |y ⊕ f(x)⟩, and bottom output is |x⟩.][scale=0.3]{
//}
@<br>{}
　First, consider what happens if we flip |−⟩ using the 𝑋 gate:

//indepimage[eq_1_68]
#@#\begin{align*}
#@# X \ket{-}
#@# &= \frac{1}{\sqrt{2}} X(\ket{0} - \ket{1}) \\
#@# &= \frac{1}{\sqrt{2}} (\ket{1} - \ket{0}) \tag{1.68}\\
#@# &= -\ket{-}
#@#\end{align*}

In the cases where 𝑈𝑓 flips |𝑦⟩, we have:

//indepimage[eq_1_69]
#@#\begin{align*}
#@# U_f \ket{x} \ket{-} = \ket{x} (-\ket{-}) = (-\ket{x}) \ket{-}\tag{1.69}
#@#\end{align*}

It might seem that we “magically” moved the minus sign from one qubit to the other, but remember that this is really a two-qubit state, 
 not two individual qubits. 
 And −1 is just a constant, so we can associate it with either part of the two-qubit state.
@<br>{}
　Figure 1.11 shows the under-the-covers implementation of the circuit from Figure 1.8, where the dashed box replaces𝑈.
 We add our ancilla qubit as part of this circuit.
 We typically assume that qubits are initialized in state |0⟩, so we use 𝐻𝑋 to create the desired |−⟩ state. 
 Then we have our black-box function, 𝑈𝑓, which has the desired sign-flipping effect on |𝑥⟩. 
 Finally, it is good practice to “uncompute” the ancilla bit, restoring it |0⟩, so that the qubit can be used elsewhere in a larger circuit.
@<br>{}
　If the notions of reversible logic and phase kickback seem strange, don’t worry.
 We’ll have a lot more to say about them in Chapters 11 and 12.

//image[fig_1_11][mplementation of Deutsch’s algorithm. The dashed box is equivalent to U in Figure 1.8.][scale=0.3]{
//}

== Key Characteristics of Quantum Computing

The Bell and Deutsch examples have illustrated several important characteristics of quantum computing:

・Results are (usually) statistical: When a classical program is executed, you obtain the same result each time. 
 However, when a quantum circuit is executed, multiple results are possible with probabilities determined by the magnitude 
 squared of the amplitudes of each state. 
 Consequently, in general a circuit must be executed a large number of times, with the results of the computation extracted from a histogram of the measured outcomes.
@<br>{}
　It is possible, however, for the outcome to be one particular state with probability 1.
 This is the case for Deutsch’s algorithm, for example.
 We know the answer for certain after one execution (assuming the quantum machine is error-free). 
 So it’s not the case that a quantum algorithm must be probabilistic, but the most interesting algorithms tend to be that way.

・Quantum parallelism: Arranging for the input state to be a superposition allows the calculation to consider multiple cases at once.
 However, it is not as easy to capitalize on this as it might sound. As indicated in the previous bullet, 
 even though the output state may contain the complete solution, a single measurement will yield only one state with a probability 
 given by the squared magnitude of the amplitude of the state in the solution of the problem.

・Exponential scaling: The number of cases that can be considered scales as 2𝑁, where 𝑁 is the number of qubits. 
 Beyond about 50 qubits, a general quantum processor cannot be simulated by a supercomputer; said differently, 
 a processor with of order 50 or more qubits is capable of computations not possible on the best classical computers.
 However, if the quantum program is restricted to certain types of gates, then the operation of the quantum computer 
 can be efficiently simulated by a classical computer.

・Quantum interference: When multiple cases are considered using superposition, the goal of the quantum circuit is to arrange for 
 the amplitudes of correct answer(s) to add constructively, while arranging for the incorrect answer(s) to add destructively.

・Asking the right question: Although the output state of a quantum calculation will generally contain information about many possibilities, 
 making a measurement collapses the state and therefore only gives a single result. 
 In the Deutsch Problem, two classical function calls would not only tell you whether the function was constant or balanced, 
 but it would tell you precisely what the function was. 
 In contrast, the quantum calculation answers the question about whether the function is constant or balanced in one function 
 call (which requires consideration of both cases), but it does not tell you which of the two possible functions it is.

== Quantum Computing Systems

At this point, you may be asking: what kind of physical system exhibits the behavior that we can exploit for quantum computing? 
 Any two-state quantum mechanical system can represent a qubit, and there are several possibilities, such as the spin of an electron, 
 the polarization of a photon, or the energy level of an electron in a charged ion.
 Any of these systems can be used to build a quantum computer, but there are tradeoffs regarding how the qubits can be manufactured
 and controlled, and how they interact with one another.
@<br>{}
　In this book, we concentrate on one specific technology for creating qubits and quantum computing systems: superconducting circuits. 
 Unlike many competing technologies, superconducting qubits are macroscopic in size and are based on well-known nanofabrication technologies. 
 They represent the current technology of choice for several companies building quantum computer systems, including IBM, Google, and Rigetti.
@<br>{}
　A large part of this book, Chapters 2–8, is devoted to a detailed explanation of these devices and how to control them
 to carry out the fundamental operations of a quantum computer, described above. 
 In this section, before diving into the details, we provide a high-level overview of a superconducting quantum computer.
@<br>{}
　As we will see in Chapter 2, we will need to couple the qubit to a signal whose frequency depends on the energy difference between the
 |0⟩ and |1⟩ states, i.e., the ground and excited states. 
 In superconducting quantum computers, this energy difference corresponds to a microwave frequency near 5 GHz. 
 Consequently,we must design a microwave system to control and measure superconducting qubit states.
@<br>{}
　The general features of the microwave system to control and readout superconducting qubits are shown in Figure 1.12. 
 A key feature is that the qubits must be held at a very low temperature, near absolute zero. 
 Consequently the qubits must be located in a cryogenic refrigerator. 
 To understand why this is necessary, we want to make sure that if we put the qubit in the ground state, it stays in the ground state. 
 In other words, we want to make sure that it is unable to absorb enough energy incidentally from its environment to make a transition. 
 A circuit in equilibrium at temperature 𝑇 can emit and absorb photons with the energy 𝑘𝑇, where 𝑘 is Boltzmann’s constant. 
 The energy of a photon is ℏ𝜔, where 𝜔 is the frequency and ℏ is Planck’s constant divided by 2𝜋.
 We want to make sure that 𝑘𝑇 << ℏ𝜔. For 𝜔∕(2𝜋) = 5 GHz, this means that 𝑇 << 0.24 K. 
 In state-of-the-art dilution refrigerators, the temperature of the qubits can be held at 10–15 mK. 
 In this range of temperatures, thermal excitation of 5 GHz qubits can be neglected.
@<br>{}
　Referring again to Figure 1.12, the quantum processor (QP) containing the qubits is located at the bottom left of the refrigerator. 
 In addition to being kept very close to absolute zero temperature, the quantum processor is also sensitive to stray magnetic fields, 
 so it is further placed inside a magnetic shield within the coldest stage of the refrigerator.
@<br>{}
　The round component just above the quantum processor is a circulator. 
 This is a non-reciprocal microwave component in which energy can only propagate between ports in the direction of the circulating arrow. 
 By non-reciprocal, we mean that the behavior of the component is different if you interchange the input with the output.
 For example, the RF signal from the control electronics enters the circulator at the top port; 
 the energy “circulates” around to the port to which the quantum processor is connected.
 Any reflected energy from the quantum processor, e.g., containing information about the state of a qubit, then re-enters the bottom port of the circulator. 
 However, since the circulator is non-reciprocal, instead of returning to the input port on the top side of the circulator, 
 it flows instead to the port on the right and is conveyed to the circulator located in the center. 
 We will return to this center circulator in a moment, but let us first consider the chain of coaxial cables and attenuators 
 conveying the control signal to the first circulator.

//image[fig_1_12][System diagram for a superconducting quantum computer.][scale=0.3]{
//}

@<br>{}
　If we simply used a copper coaxial cable to carry the signal from the roomtemperature electronics into the refrigerator, we would have at least two significant problems.
 First, copper is a good conductor of heat as well as electricity, so the copper cable would convey heat from 
 the upper stages to the lower stages, making it very difficult to reach the temperatures required at the lower stages. 
 To address this, coaxial cables made of an alloy of copper and nickel are used instead. 
 This alloy has very low thermal conductivity to assist with thermally isolating the stages, while having an acceptable electrical conductivity.
@<br>{}
　The second problem is that a cable coming straight from the outside environment would convey significant noise
 from the environment into the refrigerator. 
 To combat this, attenuators are placed in the lower stages. 
 These attenuators reduce noise power from the upper stages, but introduce their own noise proportional to their equilibrium temperature. 
 Consequently at the lowest stage, the thermal noise is minimized by the very low temperature of the attenuator. 
 Of course these attenuators also reduce the amplitude of the control signal, so we must make sure that the signal level produced
 by the signal source is strong enough to produce a satisfactory control signal at the quantum processor.
@<br>{}
　Returning to the signal reflected from the quantum processor, upon entering the center circulator, 
 the energy is transferred to the bottom port and delivered to a Josephson Junction Parametric Amplifier (JPA). 
 This is a quantum-limited amplifier, meaning that the noise it introduces to the circuit is close to the fundamental minimum allowed by quantum theory. 
 The JPA works in reflection mode, so the amplified reflected signal is returned to the circulator and transferred to the final circulator at the bottom right.
@<br>{}
　The circulator at the bottom right is operated as an isolator. Power applied to the input (left port) is delivered to the output (top port), 
 but any power reflected from impedance mismatches further down line, e.g., at the input of the HEMT amplifier, 
 will be delivered to the matched load attached to the bottom port. 
 In this way, the very sensitive quantum processor and quantum limited amplifier are isolated from reflected power or noise from the upper stages.
@<br>{}
　The measured signal at this point is very weak, and we definitely would not want to use a stack of attenuators on the output line! Instead, 
 a coaxial cable made of an alloy of Niobium and Titanium (NbTi) is used to convey the signal to the 3 K stage. 
 NbTi is a Type II superconductor with a transition temperature of about 10 K, so it provides an extremely low loss path to the 3 K stage. 
 At the 3 K stage, there is a more conventional low-noise amplifier (LNA), but made using a high electron mobility transistor (HEMT)—a type of transistor 
 that is known for producing very low noise. 
 The signal from the output of the HEMT LNA is further amplified at room temperature before delivery to the signal processing electronics.
@<br>{}
　Returning to the control-signal electronics, any band-limited signal centered on the frequency 𝜔 can be 
 represented by sine and cosine components:

//indepimage[eq_1_70]
#@#\begin{align*}
#@# f(t) = I(t) \cos \omega t + Q(t) \sin \omega t,\tag{1.70}
#@#\end{align*}

where 𝐼(𝑡) and 𝑄(𝑡) are “in-phase” and “quadrature” functions whose time variations are slow compared with the period 𝑇 = 2𝜋∕𝜔. 
 Digital samples of 𝐼 and 𝑄 are converted to band-limited analog signals by digital-to-analog converters followed in general by
 low-pass filters to eliminate high-frequency components resulting from aliasing. 
 The circular components in Figure 1.12 containing “×” are called mixers, and produce an output that is simply the product of the two input signals. 
 For example, the bottom-most mixer produces 𝑄(𝑡) sin 𝜔𝑡 on its output. Similarly, the output of the next-to-bottom mixer is 𝐼(𝑡) cos 𝜔𝑡. 
 The outputs of the two mixers are applied to a power combiner, shown as the square component with two terminals on the left, and one on the right.
 The output of the combiner is the sum of the two input signals, creating the desired general signal of the form given by Eq. (1.70). 
 This circuit is referred to as an IQ modulator.
@<br>{}
　There are different ways of combining RF signals, but the particular one shown is known as a Wilkinson combiner, or Wilkinson divider. 
 Note that this component is reciprocal, so it can be used either as a combiner or a divider. 
 An attractive feature of the Wilkinson circuit when used as a divider is that if all of the ports are matched, it does not introduce any loss.
@<br>{}
　The output signal fromthe quantum processor is applied to a signal processing circuit at the top center of Figure 1.12 that is very similar to 
 the IQmodulator used to generate the control signal. 
 The signal is first split into equal parts using a Wilkinson divider, and the divided signals are multiplied by either cos 𝜔𝑡 or sin 𝜔𝑡 before 
 being applied to low-pass filters. 
 The effect of the low-pass filters is to integrate the applied signal, so since the cross term proportional to cos 𝜔𝑡 sin 𝜔𝑡 averages to zero, 
 the filter outputs are proportional to either 𝐼(𝑡) or 𝑄(𝑡). 
 These signals are then digitized and analyzed by the classical computer.
@<br>{}
　With this high-level description as motivation, we are now ready to discuss in detail the principles that underlie the hardware 
 and software of superconducting quantum computing.

・Chapters 2 and 3 explore the quantum physics that determine the behavior of qubits and gates. 
 This gives us the tools to understand the fundamentals of quantum states and how they can be manipulated.

・Chapters 4–8 show how qubits are constructed from superconducting devices, how they are coupled to each other with microwave transmission lines, 
 and how they are controlled and measured by external systems.

・Chapters 9 and 10 discuss how imperfections in the systemswe build affect the quantum information we are trying to process. 
 In the near term, we need mechanisms to characterize and compensate for errors, while the long-term hope is thatwe will have
 a sufficient number of high-quality qubits to correct errors dynamically and sustain long-running, fault-tolerant quantum computations.

・Finally, Chapters 11 and 12 describe the computations that can be accomplished using qubits and gates, and the potential for applications 
 beyond the capabilities of classical computers.


　Our hope is to lay a firm foundation for those new to the quantum computing field whether students or practicing engineers, 
 as a first step toward tackling the many research and engineering challenges that are needed to make large-scale quantum computers a reality.

== Exercises

1.1 How many basis states are there for a three-qubit system? Show the vectors for the (computational) basis states.
@<br>{}
1.2 There are four Bell states that can be created by entangling two qubits. 
 In addition to the state shown in Figure 1.5, the three additional states are listed below.
@<br>{} 
//indepimage[ex_1_1]
#@#\begin{align*}
#@# \text{(a)}\quad \frac{1}{\sqrt{2}} (\ket{00} - \ket{11}) \\
#@# \text{(b)}\quad \frac{1}{\sqrt{2}} (\ket{01} + \ket{10}) \\
#@# \text{(c)}\quad \frac{1}{\sqrt{2}} (\ket{01} - \ket{10})
#@#\end{align*}
@<br>{} 
1.3 Prove the following equivalencies.
@<br>{}
//indepimage[ex_1_2]
#@#\begin{align*}
#@# & \text{(a)}\quad HZH = X \\
#@# & \text{(b)}\quad HXH = Z \\
#@# & \text{(c)}\quad HYH = -Y \\
#@# & \text{(d)}\quad \text{CNOT}_{1,0} = H^{\otimes 2} \cdot \text{CNOT}_{0,1} \cdot H^{\otimes 2}
#@#\end{align*}
@<br>{} 
　　In (d), CNOT𝑖,𝑗 means a CNOT with qubit 𝑖 as the control and qubit 𝑗 as the　target. 
𝐻⊗2 means a Hadamard gate applied to both qubits.
@<br>{} 
1.4 Create a quantum circuit that swaps two qubit states. In other words: |𝑎𝑏⟩ ↦|𝑏𝑎⟩. 
 Hint: Consider this classical algorithm that swaps two numbers 𝑥 and 𝑦 using an exclusive-OR (XOR) instruction.
@<br>{} 
//indepimage[ex_1_3]
#@#\begin{align*}
#@# & x \leftarrow x XOR y \\
#@# & y \leftarrow y XOR x \\
#@# & x \leftarrow x XOR y
#@#\end{align*}
@<br>{} 
1.5 Supposewe design a superconducting qubit where the energy difference between |0⟩ and |1⟩ is around 10 GHz. 
 What is the temperature needed to minimize the effect of thermal energy on the qubit, assuming that the qubit is in thermal
 equilibrium with its environment?
@<br>{} 


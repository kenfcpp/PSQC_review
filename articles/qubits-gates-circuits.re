= Qubits, Gates, and Circuits

== Bits and Qubits
Digital systems that are most familiar are based on binary digits, or "bits."
 Each bit can take on either the value "1" or "0," and any arbitrary data can be represented by such a binary representation.
 In addition, any arbitrary logical operation can be implemented using bits.
 We will refer to these familiar systems as "classical" systems, since they are governed by the everyday laws of classical physics.
 @<br>{}
　Quantum computing is different from classical computing in a number of significant ways.
 The fundamental unit of information in quantum computing is the qubit (pronounced "KEW-bit"), short for quantum bit.
 The capabilities and behavior of qubits are quite different than bits, and we begin by pointing out and discussing the key differences as a launching point for our study of quantum computing.

=== Circuits in Space vs. Circuits in Time
A simple classical logic circuit is represented by the NOT gate shown in Figure 1.1(a).
 The NOT gate turns a "0" into "1" and vice versa.
 In this circuit diagram the horizontal direction represents space, i.e., the input and output of the circuit are physically accessible from different points in the circuit, and they can be measured simultaneously.
@<br>{}
　The quantum version of the NOT gate is the X gate shown in Figure 1.1(b).
 For qubits, the "0" and "1" states are normally written | 0 >, and (1), respectively.
 We will discuss the meaning of this notation in more detail in a future section, but for now just consider them to be labels for the two states.
 In this case, the horizontal direction represents time, i.e., the input and output of the circuit represent the state of the same qubit after performing the X gate operation.
 In other words, unlike the usual structure of classical logic, a quantum gate represents an operation that you perform on a single qubit or set of qubits.
 The output effectively overwrites the input, and every time a gate is applied it changes the state of the qubit.

=== Superposition
A classical bit must either be a "0" or a "1." In contrast, a qubit can also be in a super position state that is part "0" and part "1."
//image[fig1][Classical NOT Circuit diagram. The horizontal direction represents space, i.e., the input and output of the circuit are physically accessible from different points in the circuit, and they can be measured simultaneously.][scale=0.3]{
Classical NOT Circuit diagram
//}
//image[fig2][CQuantum X gate circuit (quantum version of the NOT gate). he horizontal direction represents time, ie, the input and output of the circuit represent the state of the same qubit after performing the X gate operation. The lower part of the Figure shows an alternate symbol for the quantum NOT gate.][scale=0.3]{
Classical NOT Circuit diagram
//}
 If the qubit is in a "1" or "0" state, we say the qubit is in a basis state.@<fn>{fn-1} 
 For basis states, the state of the qubit can be measured any number of times without changing the state, much like measuring the state of a classical gate.
 A superposition state will also yield either a "0" or a "1" when measured, with a probability determined by the mixture.
 In this case the action of making the measurement will "collapse" the superposition state onto one of the constituent basis states, and the information stored in the superposition state will be lost.
 For example, If |ψ> happens to represent a superposition state, then measuring the qubit at any time will collapse the state to either |0> or |1>, destroying the information in the superposition state.
 From this point on, repeated measurement of the qubit will always yield the same result as the first measurement, just like a classical bit.
@<br>{}
　Mathematically the superposition state can be written

//footnote[fn-1][1 To be more precise, |0> and |1> are known as the "computational basis" or "standard basis" states. For this chapter, we will restrict our discussion to the standard basis and will simply refer to basis states.]

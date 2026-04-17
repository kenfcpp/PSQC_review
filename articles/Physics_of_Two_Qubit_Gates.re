= Physics of Two Qubit Gates

As mentioned in Chapter 1, distinguishing characteristics of quantum computing
 include the use of the quantum mechanical phenomena of superposition and entanglement.
 The simplest manifestation of superposition is the case of a single qubit in a 
 state with non-zero probabilities of getting either a 0 or a 1 when measured.
 We explored the physics underlying the generation of such single-qubit gates in Chapter 2.

The simplest manifestation of entanglement is a two-qubit state that cannot be
 expressed as a product of single-qubit states.
 The Bell State described in Section 1.6 is a classic example.

The CNOT gate thatwe used to create the Bell state combined with single-qubit gates comprise a universal gate set—i.e.,
 a set of gates capable of doing any arbitrary quantum computation1 [10]. 
 Further, it turns out that any two-qubit entangling gate along with single-qubit gates is universal [11]. 
 Consequently a number of entangling schemes have been proposed.We will concentrate on two: 
 (1) coupled qubits that have the same frequency, 
 and (2) coupled qubits with different frequencies where a signal at the frequency of one is applied to the other. 
 This latter scheme is referred to as cross-resonant entanglement.

== @<m>{\sqrt{\text{iSWAP\}\}} Gate
It is helpful to begin this discussion by defining theSWAP gate and two of its cousins.
 As the name implies, a SWAP gate simply interchanges the states on two qubits. 
 In other words, it makes the following transformations: 
 @<m>{|00 \rangle} →  @<m>{|00\rangle},  @<m>{|01\rangle} →  @<m>{|10\rangle}, @<m>{|10\rangle} → @<m>{|01\rangle}, and @<m>{|11\rangle} → @<m>{|11\rangle}. It is represented by the matrix

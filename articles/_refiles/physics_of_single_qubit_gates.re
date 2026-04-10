= Physics of Single Qubit Gates

== Requirements for a Quantum Computer
As you might expect, having some way to represent and manipulate qubits is a basic requirement of any quantum computer. 
 In thinking through all of the key requirements, DiVincenzo [3] identified the following five basic requirements:

 1. A scalable physical system with well-characterized qubits
 2. The ability to initialize the state of the qubits to a simple fiducial state, such as @<m>{|000...\rangle}
 3. Long relevant decoherence times, much longer than the gate operation time
 4. A “universal” set of quantum gates
 5. A qubit-specific measurement capability
In this Chapter we will discuss aspects of two of these requirements, but a bit out ofDiVincenzo’s order:
 * We will see that arbitrary manipulations of qubits can be interpreted as rotations, 
 so we begin by discussing rotations—a subtopic of Requirement 4;
 * We will then explore the physics of two-state systems needed to represent qubits—a subtopic of Requirement 1.
 We will delay discussions of entanglement, measurement, initialization, and decoherence time to subsequent chapters.

== Single Qubit Gates

=== Rotations
In the last chapter we encountered several types of gates and described them by 2 @<m>{x} 2 matrices. 
 To understand more generally what gates do to qubits we need to understand rotations.
 We will then see that the gates we have discussed can be viewed as particular rotations.

You may have encountered rotations in a classical physics or mechanics class, 
 so we will begin with a brief review of rotations of classical vectors in 3-space. 
 However, in quantum mechanics the physical state is represented by the state vector, 
 so we need to understand how these state vectors are rotated.

For a single qubit the state vector is represented by a 2 @<m>{x} 1 matrix (or vector), 
 and in other areas of quantum mechanics such state vectors are referred to as spinors. 
 The origin of this term comes from the fact that a particle with spin in a magnetic field is 
 one of the simplest two-state systems, 
 and in this context the 2 @<m>{x} 1 state vectors represent the spin state. 
 However, the concepts are valid for any two-state quantum mechanical system.

==== Classical Rotations
The rotation of a classical vector around the z axis by the angle 𝜃 in the counterclockwise(CCW)
 direction is illustrated in Figure 2.1. 
 From the geometry of the figure we see that the vector of length @<m>{\gamma} along 
 the @<m>{x} axis rotates into (@<m>{\gamma}cos 𝜃, @<m>{\gamma}sin 𝜃, 0).
 Following a similar construction, a vector of length @<m>{\gamma} along the @<m>{y} axis rotates into
 (−@<m>{\gamma} sin 𝜃, @<m>{\gamma} cos 𝜃, 0). 
 In general we can write
//texequation{
 \begin{bmatrix}
x' \\
y' \\
z'
\end{bmatrix}
=
\begin{bmatrix}
\cos\theta & -\sin\theta & 0 \\
\sin\theta & \cos\theta & 0 \\
0 & 0 & 1
\end{bmatrix}
\begin{bmatrix}
x \\
y \\
z
\end{bmatrix} \tag{2.1}
//}
 We refer to the square matrix as the rotation matrix for rotations about the z axis:
//texequation{
R_z^c(\theta) =
\begin{bmatrix}
\cos\theta & -\sin\theta & 0 \\
\sin\theta & \cos\theta & 0 \\
0 & 0 & 1
\end{bmatrix} \tag{2.2}
//}
 Here the superscript c indicates a classical physics rotation.

Following similar procedures, rotations about the @<m>{x} axis and @<m>{y} axis are 
 described by the following matrices:
//texequation{
R_x^c(\theta) =
\begin{bmatrix}
1 & 0 & 0 \\
0 & \cos\theta & -\sin\theta \\
0 & \sin\theta & \cos\theta
\end{bmatrix} \tag{2.3}
//}	
//texequation{
R_y^c(\theta) =
\begin{bmatrix}
\cos\theta & 0 & \sin\theta \\
0 & 1 & 0 \\
-\sin\theta & 0 & \cos\theta
\end{bmatrix} \tag{2.4}
//}

//image[fig_2_1][Rotation of a vector of length r CCW around the z axis.][scale=01.0]{
//}

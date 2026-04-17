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
In the last chapter we encountered several types of gates and described them by @<m>{2 \times 2} matrices. 
 To understand more generally what gates do to qubits we need to understand rotations.
 We will then see that the gates we have discussed can be viewed as particular rotations.

You may have encountered rotations in a classical physics or mechanics class, 
 so we will begin with a brief review of rotations of classical vectors in 3-space. 
 However, in quantum mechanics the physical state is represented by the state vector, 
 so we need to understand how these state vectors are rotated.

For a single qubit the state vector is represented by a @<m>{2 \times 1} matrix (or vector), 
 and in other areas of quantum mechanics such state vectors are referred to as spinors. 
 The origin of this term comes from the fact that a particle with spin in a magnetic field is 
 one of the simplest two-state systems, 
 and in this context the @<m>{2 \times 1} state vectors represent the spin state. 
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

==== Rotation of the Quantum Mechanical State Vector
In quantum mechanics, vectors result from taking the expectation value@<fn>{fn-1} of vector operators for a 
 specific quantum state. 
 For example, to determine the direction of an electron’s spin, 
 we take the expectation value of the spin operator using the electron’s state vector. 
 To rotate the measured spin vector, 
 we need to rotate the electron state vector in such a way that the vector obtained 
 by taking the expectation rotates in themanner we expect. 
 As mentioned above, it is sometimes helpful to refer to electron spin as an example, 
 but our discussion applies to any two-state quantum mechanical system.
//footnote[fn-1][The expectation value is the average outcome of a measurement for the operator.]

For this discussion, consider the general vector operator @<m>{A} :
//texequation{
A = \hat{x} A_x + \hat{y} A_y + \hat{z} A_z
//} \tag{2.5}
where @<m>{\hat{x\}}, @<m>{\hat{y\}} and @<m>{\hat{z\}} refer to unit vectors in the @<m>{x, y} and @<m>{z} direction, 
 respectively. 
 @<m>{A_x} refers to the matrix component of @<m>{A} that operates along the @<m>{x} axis.
 For the quantum state @<m>{|\psi\rangle}, the expectation of @<m>{A} is 
 given by @<m>{\langle \psi' | A | \psi' \rangle}|. 
 Now suppose we would like to rotate the system so that @<m>{\langle \psi' | A | \psi' \rangle}| rotates 
 by an angle 𝜃 in the CCW direction around the @<m>{z} axis.Wewant to find a unitary operator
 @<m>{U} such that @<m>{|\psi'\rangle = U |\psi\rangle}, and
//texequation{
\langle \psi' | A | \psi' \rangle = R_z^c(\theta) \langle \psi | A | \psi \rangle \tag{2.6}
//} 
Substituting in for  @<m>{|\psi'\rangle} leads to the following constraint on @<m>{U}
//texequation{
\langle \psi | U^\dagger A U | \psi \rangle
=
\langle \psi | R_z^c(\theta) A | \psi \rangle
\tag{2.7}
//}
//texequation{
U^\dagger A U = R_z^c(\theta) A \tag{2.8}
//}
Here we have used the fact that @<m>{R_z^c(\theta)\langle \psi|A|\psi\rangle = \langle \psi|R_z^c(\theta)A|\psi\rangle}, 
 which is easily verified by direct calculation.We have also used the fact that @<m>{(U|\psi\rangle)^\dagger = \langle \psi|U^\dagger}.

To simplify our consideration of (2.8), 
 let us consider an infinitesimal rotation @<m>{\epsilon} about the axis @<m>{\hat{n\}}
 (a unit vector along the desired axis of rotation). 
 In this case we anticipate that @<m>{U} will depart only slightly from the identity operator, 
 so to first order in small quantities we can express @<m>{U} with the first two terms in a Maclaurin series:
//texequation{
U = I - i \frac{\epsilon}{2} \, \hat{n} \cdot \sigma \tag{2.9}
//}
Here @<m>{\sigma} is an arbitrary Hermitian@<fn>{fn-2} vector operator that is yet to be determined. 
 The fact that @<m>{\sigma} is Hermitian along with the coefficient  @<m>{𝑖} on the second term ensures that 
 @<m>{𝑈} is indeed unitary to first order in @<m>{\epsilon}. 
 (We could have absorbed the factor of -1/2 into the so-far-unspecified @<m>{\sigma}, 
 but including it explicitly as shown will lead us to the definition of @<m>{\sigma} that is most commonly used.)
//footnote[fn-2][A Hermitian operator 𝐀 is one for which 𝐀† = 𝐀.]

For the case of a rotation around the z axis, the x component of (2.8) becomes
//texequation{
\left(I + i \frac{\epsilon}{2}\sigma_z\right) A_x \left(I - i \frac{\epsilon}{2}\sigma_z\right)
= A_x - \epsilon A_y \tag{2.10}
//} 
//texequation{
A_x + \frac{i\epsilon}{2}\sigma_z A_x - \frac{i\epsilon}{2}A_x \sigma_z
+ \left(\frac{\epsilon}{2}\right)^2 \sigma_z A_x \sigma_z
= A_x - \epsilon A_y \tag{2.11}
//}
//texequation{
\sigma_z A_x - A_x \sigma_z = 2i A_y \tag{2.12}
//}
On the right-hand side of (2.10), we have used the small angle approximations to the elements of
 @<m>{R ^ c _\text{z\}}: cos 𝜖 ≈ 1, sin 𝜖 ≈ 𝜖. 
 Going from (2.11) to (2.12), we have neglectedterms terms of second order in 𝜖.

Similar calculations for the @<m>{y} and @<m>{z} components of (2.8) lead to
//texequation{
\sigma_z A_y - A_y \sigma_z = -2i A_x \tag{2.13}
//}
//texequation{
\sigma_z A_z - A_z \sigma_z = 0 \tag{2.14}
//}
Now if @<m>{A_m}, @<m>{\sigma_n} were ordinary numbers, equations (2.12)-(2.14) would imply that 
 @<m>{A_x} = @<m>{A_y} = 0, since ordinary numbers commute. 
 However, if these operators are represented by matrices, 
 then more general solutions can exist since matrix multiplication is not commutative. 
 Equations (2.12)-(2.14) are referred to as commutation relations,
 since they specify the difference obtained by reversing the order of the operators. 
 A more compact notation is often used to specify commutation relations:
//texequation{
[A, B] = AB - BA \tag{2.15}
//}
Rotations about the @<m>{x} and @<m>{y} axes lead to additional commutation relations which can be written
//texequation{
[\sigma_x, A_x] = 0, \quad
[\sigma_x, A_y] = i2A_z, \quad
[\sigma_x, A_z] = -i2A_y \tag{2.16}
//}
and
//texequation{
[\sigma_y, A_x] = -i2A_z, \quad
[\sigma_y, A_y] = 0, \quad
[\sigma_y, A_z] = i2A_x \tag{2.17}
//}
Since equations (2.12)-(2.14) were obtained without restrictions on the vector operator @<m>{A}, 
they must also be satisfied if we substitute the vector operator @<m>{A} = @<m>{\sigma}. 
This leads to the commutation relations for the components of @<m>{\sigma}:
//texequation{
[\sigma_x, \sigma_y] = i2\sigma_z
\tag{2.18}
//}
//texequation{
[\sigma_y, \sigma_z] = i2\sigma_x
\tag{2.19}
//}
//texequation{
[\sigma_z, \sigma_x] = i2\sigma_y
\tag{2.20}
//}
We conclude that for Eq. (2.9) to properly rotate a quantum state vector, 
 the components of the vector operator @<m>{\sigma} must satisfy the commutation relations (2.18)-(2.20).
 You can easily verify by direct substitution that the following matrices satisfy these commutation relations:
//texequation{
\sigma_x =
\begin{bmatrix}
0 & 1 \\
1 & 0
\end{bmatrix}, \quad
\sigma_y =
\begin{bmatrix}
0 & -i \\
i & 0
\end{bmatrix}, \quad
\sigma_z =
\begin{bmatrix}
1 & 0 \\
0 & -1
\end{bmatrix}
\tag{2.21}
//}
In physics these matrices are called the Pauli matrices, 
 and they may look vaguely familiar—they are identical to the @<m>{X},@<m>{Y}, @<m>{Z} gate matriceswe 
 encountered in the previous chapter! 
 In quantum computing you will often see these matrices referred to by both notations. 
 The gate notation is commonly used when quantum circuits are being discussed, 
 while the Pauli notation is often used when the Hamiltonian 
 (or operator for the total energy of a system) of a physical system is being constructed.

In general, four parameters are required to uniquely define a @<m>{2 \times 2} matrix. 
 Since the identity matrix along with the three Paulis are linearly independent, 
 we can express any @<m>{2 \times 2} matrix @<m>{A} as
//texequation{
A = a_0 I + a_1 \sigma_x + a_2 \sigma_y + a_3 \sigma_z \tag{2.22}	
//}
So far we have seen how to perform infinitesimal rotations, 
 but what about finite rotations? To make this transition, 
 we note that any two consecutive rotations can be replaced by a single equivalent rotation, 
 as illustrated in Figure 2.2. 
 The figure illustrates rotations about different axes, 
 but let us consider the simpler case of multiple small rotations about the same axis resulting 
 in an equivalent large rotation; 
 in other wordswe apply the rotation operator@<m>{N} times with 𝜖 ≈ 𝜃∕𝑁 to achieve the large rotation 𝜃. 
 The equivalent unitary operator for the total rotation can be approximated
//texequation{
U(\theta) \approx \left( I - i \frac{\theta}{2N} \, \hat{n} \cdot \sigma \right)^N \tag{2.23}
//}
In the limit 𝑁 → ∞, we obtain a closed-form expression for the unitary operator for the 
 rotation of quantum states:
//texequation{
U(\theta) = \lim_{N \to \infty}
\left( I - i \frac{\theta}{2N} \, \hat{n} \cdot \sigma \right)^N \tag{2.24}
//}
//texequation{
= \exp\left( -i \frac{\theta}{2} \, \hat{n} \cdot \sigma \right) \tag{2.25}
//}
It may seem a bit strange to have matrices as arguments to the exponential function,
 but this is simply defined by the conventional Maclaurin series
//texequation{
\exp\left( -i \frac{\theta}{2} \, \hat{n} \cdot \sigma \right)
=
\sum_{k=0}^{\infty}
\frac{\left( -i \frac{\theta}{2} \, \hat{n} \cdot \sigma \right)^k}{k!}
\tag{2.26}
//}
Having written this series, with a little additional work 
 we can obtain an alternative form for @<m>{U} that is often useful in quantum computing. 
//image[fig_2_2][Illustration of how two consecutive rotations can be replaced with a single equivalent rotation.][scale=1.0]{
//}
First, we separate the even and odd terms in the series:
//texequation{
\exp\left(-i \frac{\theta}{2}\hat{n}\cdot\sigma\right)
=
\sum_{p=0}^{\infty}
\frac{(-1)^p \left[\frac{\theta}{2}\hat{n}\cdot\sigma\right]^{2p}}{(2p)!}
- i \sum_{q=0}^{\infty}
\frac{(-1)^q \left[\frac{\theta}{2}\hat{n}\cdot\sigma\right]^{2q+1}}{(2q+1)!}
\tag{2.27}
//}
Herewe have used the observations that @<m>{(-i)^{2p\} = (-1)^p \ \text{and\} \ (-i)^{2q+1\} = -i(-1)^q}. 
 These expressions can be simplified with the aid of the identity
//texequation{
(\mathbf{A}\cdot\sigma)(\mathbf{B}\cdot\sigma)
=
(\mathbf{A}\cdot\mathbf{B}) I
+ i (\mathbf{A}\times\mathbf{B})\cdot\sigma
\tag{2.28}
//}
Setting @<m>{\mathbf{A\} = \mathbf{B\} = \hat{n\}}, and using the facts that @<m>{\hat{n\}} is a unit vector 
 and any vector crossed into itself is zero, 
 we conclude that @<m>{(\hat{n\}\cdot\sigma) ^ {2\} = 𝐼}. 
 It follows that any even power of @<m>{(\hat{n\}\cdot\sigma)} is equal to the identity matrix, 
 and any odd power is simply equal to @<m>{(\hat{n\}\cdot\sigma)}. 
 These conclusions can be expressed
//texequation{
(\hat{n}\cdot\sigma)^{2p} = I,
\quad
(\hat{n}\cdot\sigma)^{2q+1} = (\hat{n}\cdot\sigma)
\tag{2.29}
//}
where 𝑝 and 𝑞 are positive integers. These results can be used to further simplify (2.27):
//texequation{
\exp\left(-i \frac{\theta}{2}\hat{n}\cdot\sigma\right)
=
\sum_{p=0}^{\infty}
\frac{(-1)^p \left(\frac{\theta}{2}\right)^{2p}}{(2p)!}
- i (\hat{n}\cdot\sigma)
\sum_{q=0}^{\infty}
\frac{(-1)^q \left(\frac{\theta}{2}\right)^{2q+1}}{(2q+1)!}
\tag{2.30}
//}
//texequation{
= I \cos\frac{\theta}{2}
- i (\hat{n}\cdot\sigma)\sin\frac{\theta}{2}
\tag{2.31}
//}
In the last step we recognized that the first sum is the Maclaurin series for the cosine,
 and the second sum is the Maclaurin series for the sine function.

Equation (2.31) enables us to easily construct 2x2 matrices for rotations around the principal axes:
//texequation{
R_x(\theta) = e^{-i \frac{\theta}{2}\sigma_x}
=
\begin{bmatrix}
\cos\frac{\theta}{2} & -i\sin\frac{\theta}{2} \\
-i\sin\frac{\theta}{2} & \cos\frac{\theta}{2}
\end{bmatrix}
\tag{2.32}
//}
//texequation{
R_y(\theta) = e^{-i \frac{\theta}{2}\sigma_y}
=
\begin{bmatrix}
\cos\frac{\theta}{2} & -\sin\frac{\theta}{2} \\
\sin\frac{\theta}{2} & \cos\frac{\theta}{2}
\end{bmatrix}
\tag{2.33}
//}
//texequation{
R_z(\theta) = e^{-i \frac{\theta}{2}\sigma_z}
=
\begin{bmatrix}
e^{-i\theta/2} & 0 \\
0 & e^{i\theta/2}
\end{bmatrix}
\tag{2.34}
//}
Note that these have a similar appearance to classical rotation matrices, 
 but the rotation angle enters as 𝜃/2 instead of 𝜃. 
 A consequence of this is that a rotation of 2𝜋 does not return to the same state, 
 but rather the negative of the starting state. 
 However, since the measured expectation values are proportional 
 to the magnitude squared of the state vector amplitude, this sign change has no measurable result.

==== Bloch Sphere
Consider a unit vector pointing along the z axis. 
 The vector can be rotated into any other direction represented by a point on a unit sphere with two rotations:
 first rotate an angle 𝜃 about the y axis, then an angle @<m>{\phi} about the z axis (see Figures 2.2 and 2.3):
//image[fig_2_3][Representation of a single qubit state on the Bloch Sphere (created in part using [2\]).][scale=1.0]{
//}
//texequation{
|\psi'\rangle = R_z(\phi) R_y(\theta) |0\rangle
\tag{2.35}
//}
//texequation{
=
\begin{bmatrix}
e^{-i\phi/2} & 0 \\
0 & e^{i\phi/2}
\end{bmatrix}
\begin{bmatrix}
\cos\frac{\theta}{2} & -\sin\frac{\theta}{2} \\
\sin\frac{\theta}{2} & \cos\frac{\theta}{2}
\end{bmatrix}
\begin{bmatrix}
1 \\
0
\end{bmatrix}
\tag{2.36}
//}
//texequation{
=
\begin{bmatrix}
e^{-i\phi/2}\cos\frac{\theta}{2} \\
e^{i\phi/2}\sin\frac{\theta}{2}
\end{bmatrix}
\tag{2.37}
//}
//texequation{
=
e^{-i\phi/2}\cos\frac{\theta}{2}
\begin{bmatrix}
1 \\
0
\end{bmatrix}
+
e^{i\phi/2}\sin\frac{\theta}{2}
\begin{bmatrix}
0 \\
1
\end{bmatrix}
\tag{2.38}
//}
//texequation{
=
e^{-i\phi/2}
\left(
\cos\frac{\theta}{2}|0\rangle
+
e^{i\phi}\sin\frac{\theta}{2}|1\rangle
\right)
\tag{2.39}
//}
Since an overall phase will not affect a measurement, 
 we can represent any single qubit state @<m>{|\psi\rangle} as
//texequation{
|\psi\rangle =
\cos\frac{\theta}{2}|0\rangle
+
e^{i\phi}\sin\frac{\theta}{2}|1\rangle
\tag{2.40}
//}
The term global phase or overall phase is used to describe a phase that affects both basis states. 
 Two quantum states that differ only by a global phase are indistinguishable. 
 The term local phase or relative phase is used to describe a phase difference between the two basis states. 
 Two quantum states with different local phases are distinctly different states. 
 The usual practice is to associate the phase only with the @<m>{|1\rangle} component, 
 but it’s not a requirement; it’s the difference in phase that is relevant.

The spherical surface onto which the state vector is mapped using (𝜃, 𝜙) as shown
 in Figure 2.3 is called the Bloch Sphere. 
 Any single qubit state can be represented by a unit vector directed from the origin to a point on the sphere,
 and the action of a single qubit gate can be visualized as a rotation of the state along the surface of this 
 sphere.
 You may notice some unexpected aspects of how states are represented on the Bloch Sphere. 
 For example, we know the states @<m>{|0\rangle} and @<m>{|1\rangle} are orthogonal to one another—however, 
 these states are depicted as co-linear on the Bloch Sphere. 
 It is important to keep in mind that this is simply a visualization tool; 
 it is not an accurate depiction of the state vector in a conventional Cartesian vector space.

==== The Most General Unitary
The rotation about @<m>{y} followed by a rotation about @<m>{z} allows you to orient a vector in
 any direction on the Bloch Sphere as we showed in the previous section. 
 However, in mechanics, there are three rotations needed to orient an object arbitrarily, e.g., 
 roll, pitch, and yaw. 
 There are 12 different ways to define the rotations and their order, referred to as Euler angle conventions. 
 In the discussion of Euler angle rotations, 
 it is useful to distinguish between the fixed coordinate system, 
 and a mobile coordinate system defined with respect to the object itself.
 We will use what is referred to as the @<m>{ZYZ} convention. 
 In this convention an arbitrary orientation is achieved by the following steps:
 * First rotate the system by the angle 𝜆 about the @<m>{z} axis of the fixed coordinate system.
 * Next rotate the system by the angle 𝜃 about the @<m>{y} axis of the fixed coordinate system.
 * Finally, rotate the system by the angle 𝜙 once again about the @<m>{z} axis of the fixed
   coordinate system.

The @<m>{ZYZ} convention is particularly attractive for quantum computing because, 
 as we will see, rotations about the @<m>{z} axis can be experimentally performed with essentially
 zero error [4].

Since any possible orientation of the state vector can be achieved with this process,
 the most general unitary operator can be written
//texequation{
U(\phi,\theta,\lambda) = R_z(\phi)R_y(\theta)R_z(\lambda)
\tag{2.41} 
//}
//texequation{
=
e^{-i(\phi+\lambda)/2}
\begin{bmatrix}
\cos\frac{\theta}{2} & -e^{i\lambda}\sin\frac{\theta}{2} \\
e^{i\phi}\sin\frac{\theta}{2} & e^{i(\phi+\lambda)}\cos\frac{\theta}{2}
\end{bmatrix}
\tag{2.42}
//}
Recognizing again that an overall phase factor is not observable,
 we can define the most general unitary operator as@<fn>{fn-3}
//texequation{
u_3(\theta,\phi,\lambda) =
\begin{bmatrix}
\cos\frac{\theta}{2} & -e^{i\lambda}\sin\frac{\theta}{2} \\
e^{i\phi}\sin\frac{\theta}{2} & e^{i(\phi+\lambda)}\cos\frac{\theta}{2}
\end{bmatrix}
\tag{2.43}
//}
Using the appropriate values of (𝜃, 𝜙, 𝜆), 
 it is straightforward to verify that 𝑢3 can reproduce all of the gates encountered so far:
//texequation{
u_3(0,0,0) =
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
= I
\tag{2.44}
//}

//footnote[fn-3][Note that we have listed the angle parameters in a different order from that in which the rotations are applied. This was done so that our definition of u3 agrees with the definition of u3 in the IBM Quantum system.]
//texequation{
u_3(\pi,0,\pi) =
\begin{bmatrix}
0 & 1 \\
1 & 0
\end{bmatrix}
= X
\tag{2.45}
//}
//texequation{
u_3(\pi,\pi/2,\pi/2) =
\begin{bmatrix}
0 & -i \\
i & 0
\end{bmatrix}
= Y
\tag{2.46}
//}
//texequation{
u_3(0,0,\pi) =
\begin{bmatrix}
1 & 0 \\
0 & -1
\end{bmatrix}
= Z
\tag{2.47}
//}
//texequation{
u_3(\pi/2,0,\pi) =
\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 & 1 \\
1 & -1
\end{bmatrix}
= H
\tag{2.48}
//}
IBM Qiskit defines two other unitaries as special cases of 𝑢3:
//texequation{
u_1(\lambda) = u_3(0,0,\lambda) =
\begin{bmatrix}
1 & 0 \\
0 & e^{i\lambda}
\end{bmatrix}
\tag{2.49}
//}
//texequation{
u_2(\phi,\lambda) = u_3(\pi/2,\phi,\lambda) =
\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 & -e^{i\lambda} \\
e^{i\phi} & e^{i(\phi+\lambda)}
\end{bmatrix}
\tag{2.50}
//}
u1 allows application of a quantum phase, whereas u2 enables the creation of superposition states.

=== Two State Systems
As we have commented, a qubit can be represented by any two-state quantum system.
 The simplest two-state system is an electron in a magnetic field. 
 Because the electron has both charge and spin, it also possesses a magnetic moment. 
 So just like a compass in the Earth’s magnetic field, 
 the energy depends on the orientation of the spin with respect to the magnetic field, 
 with the lowest energy occurring when the magnetic moment and the magnetic field are lined up. 
 In the following sections we will gain a deeper understanding of the behavior of the spin 
 and how the spin’s behavior can be manipulated, and relate this back to qubits and gates.

==== Eigenvalues of the Two State Spin System
The expression for the total energy of a system is referred to in physics as the Hamiltonian,
 represented by the symbol @<m>{\mathcal{H\}}. 
 One of the fundamental postulates of quantum mechanics is that the state vector must satisfy 
 the time-dependent Schrödinger equation:
//texequation{
i\hbar \frac{\partial}{\partial t} |\psi\rangle = \mathcal{H} |\psi\rangle
\tag{2.51}
//}
where @<m>{\hbar} is Planck’s constant divided by 2𝜋. 
 For a system in a static electromagnetic field, the time-dependent state vector can be written
//texequation{
|\psi(t)\rangle = e^{-iEt/\hbar} |\psi(0)\rangle
\tag{2.52}
//}
Substituting (2.52) into (2.51) gives the time-independent Schrödinger equation
//texequation{
\mathcal{H} |\psi\rangle = E |\psi\rangle
\tag{2.53}
//}
This is of the form of a standard Eigenvalue equation, where @<m>{|\psi\rangle}
 is an eigenvector associated with the eigenvalue @<m>{\mathcal{E\}}. 
 Multipying from the left by @<m>{\langle\psi|}
 shows that the eigenvalue is the expectation value of the operator @<m>{\mathcal{H\}} 
  associated with the state vector @<m>{|\psi\rangle}:
//texequation{
\mathcal{E} = \frac{\langle \psi | \mathcal{H} | \psi \rangle}{\langle \psi | \psi \rangle}
\tag{2.54}
//}
For a magnetic moment @<m>{\boldsymbol{\mu\}} in a magnetic field @<m>{\mathbf{B\}}, the Hamiltonian is given by
//texequation{
\mathcal{H} = -\mu \cdot \mathbf{B}
\tag{2.55}
//}
As we would expect intuitively, 
 this simply says that the energy will be lowest (most negative) when 𝝁 and @<m>{\mathbf{B\}} are parallel. 
 The energy of a magnetic moment in a magnetic field described by Eq. (2.55) is referred to as the Zeeman energy, 
 named after the Dutch physicist Pieter Zeeman.

If a charged particle were moving in a circle, 
 the motion would give rise to angular momentum given by @<m>{\mathbf{L\} = \mathbf{r\} \times \mathbf{p\}}, 
 where @<m>{\mathbf{r\}} is the position of the particle, 
 and @<m>{\mathbf{p\}} is its momentum. 
 This is referred to as orbital angular momentum. 
 Also, if the particle has charge, then the motion constitutes a current loop resulting in a magnetic moment.
 Since both the angular momentum and the magnetic moment arise from the same particle motion, 
 the magnetic moment and angular momentum are proportional to one another: 
 @<m>{\boldsymbol{\mu\} = \gamma_L \mathbf{L\}}, where @<m>{\gamma_L = q/(2m_q)} is called the gyromagnetic ratio, 
 @<m>{q} is the charge of the particle (negative for an electron), and @<m>{m_q} is the mass of the particle.

The particle may also possess intrinsic angular momentum in addition to that arising from orbital motion. 
 This intrinsic angular momentum is called spin and is denoted  @<m>{\mathbf{S\}}. 
 It behaves similarly to orbital angular momentum, but with several important differences:
 (a) orbital angular momentum can have values of @<m>{n\hbar} where @<m>{n} is an integer (including zero), 
 while spin angular momentum of a single fundamental matter particle can only take on the values 
 @<m>{\pm \frac{\hbar\}{2\}} and cannot be zero; 
 (b) the gyromagnetic ratio for orbital angular momentum is @<m>{\gamma_L = q/(2m_q)}, 
 while that for spin is @<m>{\gamma_S = q/m_q}; and (c) while orbital angular momentum can be quantitatively explained 
 by a circular motion of the particle, no non-relativistic motion can quantitatively explain spin. 
 Consequently it is viewed as an intrinsic property of the particle, 
 just as mass and charge are intrinsic properties.

Although in general the total angular momentum of a particle can have both orbital and spin contributions, 
 for simplicity we consider the case when there is only spin angular momentum, and the charge is positive (e.g., for a proton). 
 With these observations in mind, the Hamiltonian (2.55) can be written
//texequation{
\mathcal{H} = -\gamma_s \mathbf{S} \cdot \mathbf{B}
= -\frac{q}{m_q} \mathbf{S} \cdot \mathbf{B}
\tag{2.56}
//}
where the spin operator @<m>{\mathbf{S\}} is given by
//texequation{
\mathbf{S} = \frac{\hbar}{2}\boldsymbol{\sigma}
\tag{2.57}
//}
@<m>{\boldsymbol{\sigma\}} is the Pauli vector we previously encountered:
//texequation{
\boldsymbol{\sigma} = \hat{x}\sigma_x + \hat{y}\sigma_y + \hat{z}\sigma_z
\tag{2.58}
//}
and @<m>{\sigma_j} are Pauli matrices given by Eq. (2.21).

Consider the case with the magnetic field directed along the @<m>{z} axis, or @<m>{\mathbf{B\} = \hat{z\} B_0}. 
 The Hamiltonian can be written
//texequation{
\mathcal{H}_0 = -\frac{1}{2}\hbar\omega_0\sigma_z
\tag{2.59}
//}
where
//texequation{
\omega_0 = \frac{q}{m_q}B_0
\tag{2.60}
//}
Using this form of the spin Hamiltonian, the time-independent Schrödinger equation (2.53) becomes
//texequation{
\begin{bmatrix}
\hbar\omega_0/2 + \mathcal{E} & 0 \\
0 & \hbar\omega_0/2 - \mathcal{E}
\end{bmatrix}
|\psi\rangle = 0
\tag{2.61}
//}
Setting the determinant equal to zero gives the characteristic equation
//texequation{
\left(\frac{\hbar\omega_0}{2} + \mathcal{E}\right)
\left(\frac{\hbar\omega_0}{2} - \mathcal{E}\right) = 0
\tag{2.62}
//}
which has solutions
//texequation{
\mathcal{E} = \pm \frac{\hbar\omega_0}{2}
\tag{2.63}
//}
It is easy to verify that the eigenvector for the eigenvalue @<m>{\mathcal{E\}\ = -\frac{\hbar \omega_0\}{2\}} is 
 @<m>{|0\rangle}, 
 and the eigenvector for the eigenvalue @<m>{\mathcal{E\} = +\frac{\hbar \omega_0\}{2\}} is @<m>{|1\rangle}.

==== Larmor Precession
Using the basic form from Eq. (2.52), we can write the general solution to the timevarying Schrödinger equation as
//texequation{
|\psi(t)\rangle =
c_0 e^{i\omega_0 t/2}|0\rangle +
c_1 e^{-i\omega_0 t/2}|1\rangle
\tag{2.64}
//}
//texequation{
= c_0 |\psi_0(t)\rangle + c_1 |\psi_1(t)\rangle
\tag{2.65}
//}
A particularly interesting case results when we choose @<m>{c_0 = \cos(\theta/2),\ c_1 = \sin(\theta/2)}:
//texequation{
|\psi(t)\rangle =
\cos\frac{\theta}{2} e^{i\omega_0 t/2}|0\rangle
+
\sin\frac{\theta}{2} e^{-i\omega_0 t/2}|1\rangle
\tag{2.66}
//}
To interpret this state, let us first find the expectation value@<fn>{fn-4} of the @<m>{x}component of the spin operator
 @<m>{S_x = \frac{\hbar \sigma_x\}{2\}}:

//footnote[fn-4][The notation ⟨𝐴⟩ represents the expectation value of an operator 𝐴. If we want to describe the expectation with respect to a specific state |𝜓⟩, we often write ⟨𝐴⟩𝜓 = ⟨𝜓|𝐴|𝜓⟩.]

//texequation{
\langle S_x \rangle = \langle \psi(t) | \frac{\hbar}{2}\sigma_x | \psi(t) \rangle
\tag{2.67}
//}
//texequation{
= \frac{\hbar}{2}
\left(
\cos\frac{\theta}{2} e^{-i\omega_0 t/2}\langle 0|
+
\sin\frac{\theta}{2} e^{i\omega_0 t/2}\langle 1|
\right)
\tag{2.68}
//}
//texequation{
\quad \times
\sigma_x
\left(
\cos\frac{\theta}{2} e^{i\omega_0 t/2}|0\rangle
+
\sin\frac{\theta}{2} e^{-i\omega_0 t/2}|1\rangle
\right)
\tag{2.69}
//}
Multiplying this expression out and using the relations @<m>{\sigma_x |0\rangle = |1\rangle},
 @<m>{\sigma_x |1\rangle = |0\rangle}, 
 and @<m>{\langle m|n\rangle = \delta_{mn\}} where @<m>{\delta_{mn\}} is the Kronecker delta 
 and is equal to 1 if @<m>{m = n} and 0 otherwise, 
 we obtain
//texequation{
 \langle S_x \rangle = \frac{\hbar}{2}\sin\theta \cos(\omega_0 t)
\tag{2.70}
//}
Calculating the expectation values of @<m>{S_y} and @<m>{S_z} in a similar way gives
//texequation{
\langle S_y \rangle = -\frac{\hbar}{2}\sin\theta \sin(\omega_0 t)
\tag{2.71}
//}
and
//texequation{
\langle S_z \rangle = \frac{\hbar}{2}\cos\theta
\tag{2.72}
//}
These equations describe a vector making an angle 𝜃 with the z axis,
 and precessing about it with an angular velocity @<m>{𝜔_0}, as shown in Figure 2.4. 
 This motion is known as Larmor Precession. 
 It is analogous to the motion of a spinning top in the earth’s gravitational field owing to the angular momentum of the top.

From our previous discussion, we know that there must be some analogous rotation of the state vector 
 that gives rise to the precession of the expectation of the spin vector.
 With this in mind, note that Eq. (2.66) is identical with Eq. (2.39) with @<m>{\phi = -\omega_0 t}.

==== Coupled Qubit States
When a two-level system is coupled to a driving field at precisely the frequency corresponding to the energy difference
 between the states, 
 the system will oscillate between the two states at a frequency determined by the strength of the driving field. 
 These oscillations are called Rabi oscillations and are the basic mechanism underlying rotations on the Bloch Sphere. 
 In this section we will examine these oscillations and show how they can be used to realize the basic gates 
 used in quantum computing.

Without such a coupling field, the states @<m>{|\psi_0(t)\rangle} and @<m>{|\psi_1(t)\rangle} are orthogonal eigenvectors 
 of the Hamiltonian, as we have seen. 
 For the case of a relatively weak interaction
 (i.e., the interaction energy much smaller than the energy difference between the states), 
 we can approach this as a perturbation to the uncoupled system. 
 With this approach, the general state vector is always a superposition of @<m>{|\psi_0(t)\rangle} 
 and @<m>{|\psi_1(t)\rangle},
 but the precise mixture varies slowly in time on the scale of 1/𝜔0. 
 The time-varying coefficients can be found by solving a set of coupled Schrödinger equations:
//image[fig_2_4][Precession of spin vector for a particle with positive charge in a z-directed magnetic field.][scale=1.0]{
//}
//texequation{
\begin{aligned}
i\hbar \partial_t \big(c_0(t)|\psi_0(t)\rangle\big)
= \mathcal{H}_0 c_0(t)|\psi_0(t)\rangle
+ V_{01}|0\rangle\langle 1|\, c_1(t)|\psi_1(t)\rangle \\
i\hbar \partial_t \big(c_1(t)|\psi_1(t)\rangle\big)
= \mathcal{H}_0 c_1(t)|\psi_1(t)\rangle
+ V_{10}|1\rangle\langle 0|\, c_0(t)|\psi_0(t)\rangle
\end{aligned}\tag{2.73}
//}
Here @<m>{V_{01\}\,|0\rangle\langle 1|} represents the coupling from state @<m>{|0\rangle} to state @<m>{|1\rangle}, 
 @<m>{V_{10\}\,|1\rangle\langle 0|} represents the coupling from state @<m>{|1\rangle} to state @<m>{|0\rangle}, 
 and we have introduced the short-hand notation
@<m>{\partial_t \equiv \frac{\partial\}{\partial t\}}.

Recalling that @<m>{|\psi_0\rangle = e^{i\omega_0 t/2\}|0\rangle} 
 and @<m>{|\psi_1\rangle = e^{-i\omega_0 t/2\}|1\rangle}, the top equation in (2.73), 
 can be written in the somewhat simplified form
//texequation{
i\hbar \partial_t \big(c_0(t)|\psi_0(t)\rangle\big)
= \mathcal{H}_0 c_0(t)|\psi_0(t)\rangle
+ V_{01} c_1(t) e^{-i\omega_0 t/2}|0\rangle
\tag{2.74}
//}
Expanding the derivative on the left-hand-side gives
//texequation{
i\hbar c_0(t)\partial_t |\psi_0(t)\rangle
+ i\hbar |\psi_0(t)\rangle \partial_t c_0(t)
=
\mathcal{H}_0 c_0(t)|\psi_0(t)\rangle
+ V_{01} c_1(t)e^{-i\omega_0 t/2}|0\rangle
\tag{2.75}
//}
Recognizing that the first terms on both sides of the equation are equal owing to the unperturbed Schrödinger equation,
 and multiplying from the left by @<m>{\langle 0|} gives
//texequation{
\partial_t c_0 = -i \frac{V_{01}}{\hbar} e^{-i\omega_0 t} c_1
\tag{2.76}
//}
Following a similar procedure with the second equation leads to
//texequation{
\partial_t c_1 = -i \frac{V_{10}}{\hbar} e^{i\omega_0 t} c_0
\tag{2.77}
//}
These represent two coupled equations that must be solved simultaneously.

Up to this point, we have not put any constraints on @<m>{V_{01\}} and @<m>{V_{10\}}. To explore the relationship 
 between these two quantities, 
 recall that the sum of the probabilities that the system is in one state or the other must sum to 1:
//texequation{
c_0^* c_0 + c_1^* c_1 = 1
\tag{2.78}
//}
It follows that the time derivative of this expression must be zero:
//texequation{
\partial_t (c_0^* c_0 + c_1^* c_1) = 0
\tag{2.79}
//}
or
//texequation{
c_0^* \partial_t c_0 + c_0 \partial_t c_0^*
+ c_1^* \partial_t c_1 + c_1 \partial_t c_1^* = 0
\tag{2.80}
//}
This can be interpreted as requiring “conservation of probability” in the system.
 Substituting expressions for the derivatives from (2.76) and (2.77) and simplifying gives
//texequation{
i c_0 c_1^* e^{i\omega_0 t}(V_{01} - V_{10}) + \text{c.c.} = 0
\tag{2.81}
//}
where @<m>{\text{c.c.\}} represents the complex conjugate of the first term.
 We see then that imposing the conservation of probability condition requires @<m>{V_{01\} = V_{10\} ≡ V}. 
 With this condition, the Hamiltonian represented by the right-hand-side of Eq. (2.73) can be written
//texequation{
\mathcal{H} = -\frac{1}{2}\hbar\omega_0 \sigma_z + V\sigma_x
= \mathcal{H}_0 + \mathcal{V}
\tag{2.82}
//}

=== Creating Rotations: Rabi Oscillations

==== Rotation Operator Approach
Suppose we consider a time-varying coupling term of the form
//texequation{
V(t) = \hbar \Omega_R \cos(\omega_d t - \gamma)
\tag{2.83}
//}
where @<m>{\omega_d} and @<m>{\gamma} are the amplitude and phase, respectively, 
 of an RF drive signal applied to couple the qubit states. 
 The Hamiltonian (2.82) then becomes
//texequation{
\mathcal{H} = -\frac{\hbar \omega_0}{2}\sigma_z
+ \hbar \Omega_R \cos(\omega_d t - \gamma)\sigma_x
\tag{2.84}
//}
Recall from our previous discussion that the state vector of a superposition state precesses
 in a CW direction when viewed from the positive z axis. 
 It is convenient to introduce a coordinate system rotating with the state vector so that the vector appears
 fixed in the rotating system. 
 We know that the state vector can be rotated about the z axis using the unitary @<m>{R_z(\phi)}(2.34). 
 This is sometimes called an active rotation. 
 To rotate the coordinate system instead, we use the inverse unitary, 
 effectively cancelling the apparent rotation of the state. 
 This is referred to as a passive rotation. 
 The state vector in the rotating system can therefore be written
//texequation{
|\psi(t)\rangle_r = R_z^\dagger(\phi)|\psi(t)\rangle
\tag{2.85}
//}
Since Schrödinger’s equation must also be satisfied in the rotating frame, 
 let us multiply by @<m>{i\hbar} and take the time derivative:
//texequation{
\begin{aligned}
i\hbar \partial_t |\psi(t)\rangle_r
&= i\hbar \partial_t \big(R_z^\dagger(t)\,|\psi(t)\rangle\big) \\
&= i\hbar (\partial_t R_z^\dagger(t))\,|\psi(t)\rangle
+ i\hbar R_z^\dagger(t)\,\partial_t |\psi(t)\rangle \\
&= i\hbar (\partial_t R_z^\dagger(t))\,|\psi(t)\rangle
+ R_z^\dagger(t)\,\mathcal{H}\,|\psi(t)\rangle \\
&= i\hbar (\partial_t R_z^\dagger(t))\,R_z(t)\,|\psi(t)\rangle_r
+ R_z^\dagger(t)\,\mathcal{H}\,R_z(t)\,|\psi(t)\rangle_r \\
&= \left[
i\hbar (\partial_t R_z^\dagger(t))\,R_z(t)
+ R_z^\dagger(t)\,\mathcal{H}\,R_z(t)
\right] |\psi(t)\rangle_r \\
&= \mathcal{H}_r\,|\psi(t)\rangle_r
\end{aligned}
\tag{2.86}
//}
where
//texequation{
\mathcal{H}_r = i\hbar (\partial_t R_z^\dagger)R_z
+ R_z^\dagger \mathcal{H} R_z
\tag{2.87}
//}
In the above calculations we have used the property @<m>{R_z R_z^\dagger = 1}, 
 and the fact that @<m>{|\psi\rangle} satisfies the Schrödinger equation in the laboratory frame. 
 Since the state vector rotation is given by @<m>{\quad \phi = -\omega_0 t},
//texequation{
R_z^\dagger(-\omega_0 t) = R_z(\omega_0 t)
= e^{-i \frac{\omega_0 t}{2}\sigma_z}
\tag{2.88}
//}
The first term of the Hamiltonian in the rotating frame (2.87) can now be written
//texequation{
i\hbar (\partial_t R_z^\dagger)R_z
= i\hbar \left(-i \frac{\omega_0}{2}\sigma_z\right) R_z^\dagger R_z
= \frac{\hbar \omega_0}{2}\sigma_z
\tag{2.89}
//}
To evaluate the remaining terms in the rotating frame Hamiltonian, we have
//texequation{
R_z^\dagger(-\omega_0 t)\,\sigma_z\,R_z(-\omega_0 t) = \sigma_z
\tag{2.90}
//}
and
//texequation{
R_z^\dagger(-\omega_0 t)\,\sigma_x\,R_z(-\omega_0 t)
=
\begin{bmatrix}
0 & e^{-i\omega_0 t} \\
e^{i\omega_0 t} & 0
\end{bmatrix}
\tag{2.91}
//}
Putting the pieces of the rotating frame Hamiltonian (2.87) together gives
//texequation{
\begin{aligned}
\mathcal{H}_r
&= \frac{\hbar\omega_0}{2}\sigma_z - \frac{\hbar\omega_0}{2}\sigma_z
+ \hbar\Omega_R \cos(\omega_d t - \gamma)
\begin{bmatrix}
0 & e^{-i\omega_0 t} \\
e^{i\omega_0 t} & 0
\end{bmatrix} \\
&= \frac{\hbar\Omega_R}{2}
\begin{bmatrix}
0 &
e^{i(\omega_d-\omega_0)t-i\gamma}
+ e^{-i(\omega_d+\omega_0)t+i\gamma} \\
e^{-i(\omega_d-\omega_0)t+i\gamma}
+ e^{i(\omega_d+\omega_0)t-i\gamma}
& 0
\end{bmatrix}
\end{aligned}
\tag{2.92}
//}
Normally the drive frequency @<m>{\omega_d} will be close to the resonant frequency @<m>{\omega_0}.
 Consequently this Hamiltonian expression contains frequencies close to zero, 
 and frequencies on the order of twice @<m>{\omega_0}. 
 The high frequency oscillations will tend to average out on the scale of a gate operation, 
 so we neglect these terms going forward. 
 This is called therotating wave approximation. 
 Making this approximation and manipulating the form gives
//texequation{
\mathcal{H}_r =
\frac{\hbar\Omega_R}{2}
\begin{bmatrix}
0 & e^{i(\Delta t - \gamma)} \\
e^{-i(\Delta t - \gamma)} & 0
\end{bmatrix}
\tag{2.93}
//}
where Δ = @<m>{\omega_d - \omega_0}. If the drive frequency equals the qubit resonant frequency, 
 then we have
//texequation{
\begin{aligned}
\mathcal{H}_r
&= \frac{\hbar\Omega_R}{2}
\begin{bmatrix}
0 & e^{-i\gamma} \\
e^{i\gamma} & 0
\end{bmatrix} \\
&= \frac{\hbar\Omega_R}{2}
\left(\cos\gamma\,\sigma_x + \sin\gamma\,\sigma_y\right) \\
&= \frac{\hbar\Omega_R}{2}\,\hat{\mathbf{n}}\cdot\boldsymbol{\sigma}
\end{aligned}
\tag{2.94}
//}
where
//texequation{
\hat{\mathbf{n}} = \hat{x}\cos\gamma + \hat{y}\sin\gamma
\tag{2.95}
//}
The time evolution of the state vector in the rotating frame is therefore
//texequation{
|\psi(t)\rangle_r
= e^{-i\mathcal{H}_r t/\hbar} |\psi(0)\rangle_r
= e^{-i \frac{\Omega_R t}{2}\hat{\mathbf{n}}\cdot\boldsymbol{\sigma}} |\psi(0)\rangle_r
\tag{2.96}
//}
We see that the unitary operator describing the time evolution is simply a rotation 
 through the angle @<m>{\Omega_R t} about the axis @<m>{\hat{\mathbf{n\}\}}. 
 As an example, for rotations about the @<m>{x} axis, the matrix form of the unitary is
//texequation{
e^{-i \frac{\Omega_R t}{2}\sigma_x}
=
\begin{bmatrix}
\cos(\Omega_R t/2) & -i\sin(\Omega_R t/2) \\
-i\sin(\Omega_R t/2) & \cos(\Omega_R t/2)
\end{bmatrix}
\tag{2.97}
//}
If we start in the ground state @<m>{|0\rangle}, 
 the time evolution of the coefficients of the two states is given by
//texequation{
\begin{bmatrix}
c_0(t) \\
c_1(t)
\end{bmatrix}
=
\begin{bmatrix}
\cos(\Omega_R t/2) & -i\sin(\Omega_R t/2) \\
-i\sin(\Omega_R t/2) & \cos(\Omega_R t/2)
\end{bmatrix}
\begin{bmatrix}
1 \\
0
\end{bmatrix}
=
\begin{bmatrix}
\cos(\Omega_R t/2) \\
-i\sin(\Omega_R t/2)
\end{bmatrix}
\tag{2.98}
//}
It follows that the probability of measuring the qubit in one state or the other is given by (upper graph in Figure 2.5):
//texequation{
\begin{aligned}
P_0 = |c_0(t)|^2 = \left(\cos\frac{\Omega_R t}{2}\right)^2
= \frac{1}{2}\left(1 + \cos(\Omega_R t)\right) \\
P_1 = |c_1(t)|^2 = \left(\sin\frac{\Omega_R t}{2}\right)^2
= \frac{1}{2}\left(1 - \cos(\Omega_R t)\right)
\end{aligned}
\tag{2.99}
//}

==== Rotations about z
Rotations about @<m>{z} are different from the rotations about @<m>{x}, @<m>{y} owing to the relationship
 between the rotating frame and the precession. 
 One way that a @<m>{z} rotation could be realized is to simply detune @<m>{\omega_d} from @<m>{\omega_0} by a small amount. 
 This would cause a relative shift between the state vector and the rotating frame thatwould increase in time. 
 When the desired phase shift is accumulated, then control pulses return to the condition @<m>{\omega_d = \omega_0}.

However, a more precise way to realize a @<m>{z} rotation is simply to control the phase of the generator.
 We see from (2.94) that the drive signal phase @<m>{\gamma} enables the placement of the axis of rotation for 
 the Rabi oscillation anywhere in the @<m>{x-y} plane. 
 This effectively implements an arbitrary @<m>{z} rotation. 
 With modern signal generators, the phase can be changed essentially instantaneously and with negligible error [4].

==== Coupled-Mode Theory Approach
Let us return to the coupled equations (2.76) and (2.77), 
 and consider solving them directly as an alternate way to obtain the behavior of the system. 
 Substituting the driving term (2.83) into the first coupled equation (2.76) gives
//texequation{
\begin{aligned}
\partial_t c_0
&= -i\Omega_R \cos(\omega_d t - \gamma)\,e^{-i\omega_0 t} c_1 \\
&= -i\frac{\Omega_R}{2}
\left(e^{i(\omega_d t-\gamma)} + e^{-i(\omega_d t-\gamma)}\right)
e^{-i\omega_0 t} c_1 \\
&= -i\frac{\Omega_R}{2}
\left(
e^{i(\omega_d-\omega_0)t - i\gamma}
+ e^{-i(\omega_d+\omega_0)t + i\gamma}
\right)c_1
\end{aligned}
\tag{2.100}
//}
Noting that on the scale of a cycle of @<m>{\omega_d - \omega_0} the high frequency oscillations fromthe last
 term in (2.100) will approximately average to zero,
 we can once again apply the rotating wave approximation and neglect the high frequency term. 
 The coupled equation (2.100) can then be approximated by
//texequation{
\partial_t c_0
= -i\frac{\Omega_R}{2}
e^{i\Delta t - i\gamma}\,c_1
\tag{2.101}
//}
where Δ = @<m>{\omega_d - \omega_0}. Following a similar procedure,
 Eq. (2.77) in the rotating wave approximation becomes
//texequation{
\partial_t c_1
= -i\frac{\Omega_R}{2}
e^{-i\Delta t + i\gamma}\,c_0
\tag{2.102}
//}
Equations (2.101) and (2.102) can be written as the coupled-mode equations@<fn>{fn-5}
//footnote[fn-5][TResearchersworking with integrated optical devices or microwave circuits and devices may recognize (2.101) and (2.102) from coupled-mode theory; e.g., see 5-7.]

//texequation{
\partial_t c_0 = \kappa_{01} c_1 e^{i\Delta t}, \quad
\tag{2.103}
//}
//texequation{
\partial_t c_1 = \kappa_{10} c_0 e^{-i\Delta t}
\tag{2.104}
//}
where
//texequation{
\kappa_{01} = -i\frac{\Omega_R}{2} e^{-i\gamma} = -\kappa_{10}^*
\tag{2.105}
//}
Solving (2.103) for @<m>{c_1} and substituting into (2.104) gives a second-order differential equation for @<m>{c_0}:
//texequation{
\ddot{c}_0 - i\Delta \dot{c}_0 + |\kappa|^2 c_0 = 0
\tag{2.106}
//}
where @<m>{|\kappa_{01\}| = |\kappa_{10\}| = |\kappa|}, and @<m>{\quad |\kappa| = \frac{\Omega_R\}{2\}}.

Exponential solutions of (2.106) can be obtained from the roots of the corresponding
 characteristic equation
//texequation{
r^2 - i\Delta r + |\kappa|^2 = 0
\tag{2.107}
//}
The roots of this equation are
//texequation{
r_{a,b} = i\frac{\Delta \pm \sqrt{\Delta^2 + 4|\kappa|^2}}{2}
= i\frac{\Delta \pm \Omega}{2}
\tag{2.108}
//}
where
//texequation{
\Omega = \sqrt{\Delta^2 + 4|\kappa|^2}
= \sqrt{\Delta^2 + \Omega_R^2}
\tag{2.109}
//}
Two independent exponential solutions are therefore
//texequation{
c_{0a} = e^{i(\Delta/2)t + i\Omega t/2}, \quad
c_{0b} = e^{i(\Delta/2)t - i\Omega t/2}
\tag{2.110}
//}
Taking the sum and difference of these expressions allows us to obtain alternate
 independent solutions as
//texequation{
c_{0a} = e^{i(\Delta/2)t}\cos(\Omega t/2), \quad
c_{0b} = e^{i(\Delta/2)t}\sin(\Omega t/2)
\tag{2.111}
//}
The general solution can be expressed as an arbitrary linear combination of these two
 independent solutions. 
 Consequently we can write
//texequation{
c_0(t) = e^{i(\Delta/2)t}
\left(A\cos(\Omega t/2) + B\sin(\Omega t/2)\right)
\tag{2.112}
//}
The general expression for @<m>{c_1} can be obtained from (2.103). 
 After some straightforward algebra, the solutions can be expressed in terms of the initial values at @<m>{t = 0}:
//texequation{
c_0(t) = e^{i(\Delta/2)t}
\left[
c_0(0)\cos(\Omega t/2)
+ \frac{2\kappa_{01}c_1(0) - i\Delta c_0(0)}{\Omega}\sin(\Omega t/2)
\right]
\tag{2.113}
//}
//texequation{
c_1(t) = e^{-i(\Delta/2)t}
\left[
c_1(0)\cos(\Omega t/2)
+ \frac{2\kappa_{10}c_0(0) + i\Delta c_1(0)}{\Omega}\sin(\Omega t/2)
\right]
\tag{2.114}
//}
//image[fig_2_5][Solutions to the coupled mode equations for Δ = 0 and Δ∕𝜅 = 3. For the case of Rabi oscillations, |𝜅t| = ΩRt/2.][scale=0.8]{
//}
As an example, consider the case @<m>{c_0(0) = 1} and @<m>{c_1(0) = 0}. The probabilities of obtaining the states are
//texequation{
|c_0(t)|^2
= \cos^2(\Omega t/2)
+ \left(\frac{\Delta}{\Omega}\right)^2 \sin^2(\Omega t/2)
\tag{2.115}
//}
//texequation{
|c_1(t)|^2
= \left(\frac{2|\kappa|}{\Omega}\right)^2 \sin^2(\Omega t/2)
\tag{2.116}
//}
These solutions are plotted for the two cases @<m>{\Delta = 0} and @<m>{\Delta/\kappa = 3} in Figure 2.5. 
 Note that significant coupling only occurs when @<m>{\Delta \approx 0}.

== Quantum State Tomography
Supposewe have executed several rotation commands on a qubit by applying the appropriate RF pulses.
 How can we verify if we obtained the state we intended? Referring to Figure 2.3, 
 we could determine the state @<m>{|\psi\rangle} if we could measure the projection of the state on each axis. 
 As we have discussed, 
 making a measurement on the state will collapse the state onto either @<m>{|0⟩} or @<m>{|1⟩} with probabilities determined 
 by the squares of the magnitudes of the amplitudes of these components of the state. 
 To estimate these probabilities, we need to prepare and measure the same state a large number of times. 
 The percentage of times we obtain @<m>{|0⟩} allows us to estimate this probability, and similarly for @<m>{|1⟩}. 
 This suggests that we could obtain the angle @<m>{\theta} from the calculation
//texequation{
\cos\theta = P_0(|\psi\rangle) - P_1(|\psi\rangle)
\tag{2.117}
//} 
where @<m>{P_0(|\psi\rangle)} is the probability of obtaining |0⟩ and @<m>{P_1(|\psi\rangle)} is the probability of obtaining
 @<m>{|1⟩} when the state @<m>{|\psi\rangle} is measured. 
 But ifwe can only measure the projections along the @<m>{z} axis, 
 how do we determine the projections along @<m>{x} and @<m>{y}?We can do this by rotating
 the state vector so that the component we want to measure is along @<m>{z}. 
 For example, consider a rotation of 𝜋 around the axis @<m>{\hat{n\} = (\hat{x\} + \hat{y\})/\sqrt{2\}}, as shown in Figure 2.6(a).
//image[fig_2_6][Rotations enabling measurement of the projections of the state vector along the x and y axes. (a) The Hadamard gate corresponds to rotation of the state vector around an axis in the x–z plane making a 45o angle with the z axis. This rotates the x component to z axis. (b) z rotation of −90o followed by a Hadamard rotation to estimate the projection along y.][scale=0.8]{
//}

From (2.31) we have
//texequation{
\begin{aligned}
U_{\hat{n}}(\pi)
&= I\cos\frac{\pi}{2}
- i\frac{1}{\sqrt{2}}(\sigma_x + \sigma_z)\sin\frac{\pi}{2} \\
&= -i\frac{1}{\sqrt{2}}(\sigma_x + \sigma_z) \\
&= -i\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 & 1 \\
1 & -1
\end{bmatrix} \\
&= -iH
\end{aligned}
\tag{2.118}
//}
Apart from a global phase, we see that this rotation is represented simply by the Hadamard gate.
 To see why this rotation is of interest, recall that the state represented 
 by a vector along @<m>{x} is @<m>{|+\rangle = (|0 \rangle + |1\rangle)/\sqrt{2\}}, 
 and the state represented by a vector along
 @<m>{-x} is @<m>{|-\rangle = (|0\rangle - |1\rangle)/\sqrt{2\}}. 
 Applying a Hadamard gate to these states gives
//texequation{
\begin{aligned}
H|+\rangle
&= \frac{1}{\sqrt{2}}
\begin{bmatrix}
1 & 1 \\
1 & -1
\end{bmatrix}
\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 \\
1
\end{bmatrix} \\
&=
\begin{bmatrix}
1 \\
0
\end{bmatrix}
= |0\rangle
\end{aligned}
\tag{2.119}
//}
and
//texequation{
\begin{aligned}
H|-\rangle
&= \frac{1}{\sqrt{2}}
\begin{bmatrix}
1 & 1 \\
1 & -1
\end{bmatrix}
\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 \\
-1
\end{bmatrix} \\
&=
\begin{bmatrix}
0 \\
1
\end{bmatrix}
= |1\rangle
\end{aligned}
\tag{2.120}
//}
We see then that the Hadamard gate rotates the state vector so that its @<m>{x} component lies along the @<m>{z} axis. 
 Subsequently making measurements enables the component of the state vector along @<m>{x} to be estimated. 
 Thus we can write
//texequation{
\sin\theta \cos\phi
= P_0(H|\psi\rangle) - P_1(H|\psi\rangle)
\tag{2.121}
//}
Finally, we can estimate the projection along the @<m>{y} axis by first rotating the @<m>{y} axis
 into the @<m>{x} axis using a @<m>{z} rotation of −𝜋∕2, 
 followed by a Hadamard gate to again rotate @<m>{x} into @<m>{z} as shown in Figure 2.6(b). 
 Note that the @<m>{z} rotation operator can be written
//texequation{
R_z(\phi)
= e^{-i\phi/2}
\begin{bmatrix}
1 & 0 \\
0 & e^{i\phi}
\end{bmatrix}
\equiv e^{-i\phi/2} P(\phi)
\tag{2.122}
//}
where @<m>{P(\phi)} is called a phase gate, and introduces a phase shift of 𝜙 between the states |0⟩ and |1⟩.@<fn>{fn-6}
 When written this way it is easy to see that a @<m>{Z} gate is created by a rotation of 𝜋 (cf. (2.47)). 
 At this point it is convenient to introduce another gate, @<m>{S = Z^{1/2\}}:

//footnote[fn-6][For a single qubit operation, the difference between 𝑅𝑧 and 𝑃 is a global phase, and is inconsequential. However, in multi-qubit states, 𝑅𝑧 and 𝑃 may not be equivalent.]

//texequation{
S =
\begin{bmatrix}
1 & 0 \\
0 & i
\end{bmatrix}
\tag{2.123}
//}
In terms of this gate, we see that a @<m>{Z} rotation of −𝜋∕2 is represented by @<m>{S^\dagger}:
//texequation{
P(-\pi/2) =
\begin{bmatrix}
1 & 0 \\
0 & -i
\end{bmatrix}
= S^\dagger
\tag{2.124}
//}
We conclude that to estimate the projection along the @<m>{y} axis,
 we apply the operator@<m>{H S^\dagger} followed by a measurement. 
 Similar to before we can therefore write
//texequation{
\sin\theta \sin\phi
=
P_0(HS^\dagger|\psi\rangle)
-
P_1(HS^\dagger|\psi\rangle)
\tag{2.125}
//}
and the azimuth angle 𝜙 on the Bloch sphere can be estimated from@<fn>{fn-7}

//footnote[fn-7][FNote that a 4-quadrant arctangent function should be used to invert this relation, in general.]
//texequation{
\tan\phi
=
\frac{
P_0(HS^\dagger|\psi\rangle)
-
P_1(HS^\dagger|\psi\rangle)
}{
P_0(H|\psi\rangle)
-
P_1(H|\psi\rangle)
}
\tag{2.126}
//}
Having estimated both @<m>{\theta} and @<m>{\phi} enables us to locate the state vector on the Block sphere,
 and we can express the state vector in the @<m>{z} basis using (2.40).

== Expectation Values and the Pauli Operators

In Section 2.2.2.2 we considered the case where the state vector represented the spin of a particle.
 To find the expectation values of the@<m>{𝑥},@<m>{𝑦},@<m>{z} components of the spin, 
 we applied the relevant Pauli operator to the state vector. 
 In other words, to obtain the expected value of the @<m>{x} component 
 we calculated @<m>{\langle\psi| \sigma_x |\psi\rangle}, and similarly for @<m>{y} and @<m>{z}.

Based on this, one might think that to construct a quantum circuit to measure the @<m>{x} component of a qubit state vector,
 it would be necessary to apply @<m>{\sigma_x} (i.e., an @<m>{X} gate) to the qubit of interest prior to measurement. 
 However, from the previous section we see that simply preparing a state multiple times 
 and taking the average of the measurements yields an estimate for the @<m>{z} component. 
 Similarly, to estimate the @<m>{x} or @<m>{y} components, 
 it is simply necessary to perform suitable rotations to align the desired component with the @<m>{z} axis, 
 then again prepare and measure the state multiple times to estimate the average. 
 Said differently, @<m>{\langle\psi| \sigma_x |\psi\rangle} represents mathematical operations 
 that yield the expected value of the @<m>{x} component of spin—or more generally of the state vector. 
 But by definition, (an approximation to) the expectation value is obtained
 by taking a large number of measurements of the @<m>{x} component and averaging them.
 Since in quantum computing we actually take measurements, we obtain estimates of
 the state vector components by taking the averages of large numbers of measurements,
 rather than doing calculations involving the Pauli matrices.

As an example, suppose we prepared and measured an identical state @<m>{N} times (each time is referred to as a “shot”). 
 Out of these shots, @<m>{|0\rangle} is measured @<m>{N_0} times, and @<m>{|1\rangle} is measured @<m>{N_1} times, 
 where @<m>{N_0 + N_1 = N}. We obtain an estimate of the @<m>{z} component of the state as follows:
//texequation{
\langle \psi | \sigma_z | \psi \rangle
= \cos\theta
= P_0(|\psi\rangle) - P_1(|\psi\rangle)
\approx \frac{N_0 - N_1}{N}
\tag{2.127}
//}
Clearly the more shots we execute (larger @<m>{N}), the better estimate of the @<m>{z} component we obtain. 
 To make this more quantitative, we note that by the Central Limit Theorem, as@<m>{N} becomes large, 
 the variance of the estimate is @<m>{\sigma^2/N}, where the variance of an individual measurement is @<m>{\sigma^2}. 
 Since the measurement can only yield ±1, we can estimate an upper limit on the error
 as the sample standard deviation @<m>{1/\sqrt{N\}}. 
 These ideas are explored in more detail in Exercise 2.1.

== Density Matrix

Before we move to more complex qubit interactions, it is useful to introduce another representation of a quantum state, 
 known as a density matrix or density operator.@<fn>{fn-8} 
 The density matrix is a generalization of the state vector representation. 
 It can represent a larger set of possible quantum states, 
 including those that do not lie on the surface of the Bloch sphere.

//footnote[fn-8][Density operator is a more general term, as the density matrix depends on the choice of basis vectors for the state space. Since we restrict ourselves to the standard basis, we will use the terms interchangeably.]

Until now, we have only considered states that lie on the surface of the Bloch sphere, so let’s begin there.
 Such a state is known as a pure state. 
 Aswe know, it can be precisely represented as a two-element state vector @<m>{|\psi\rangle}, 
 and the density matrix @<m>{\rho} is defined as:
//texequation{
\rho \equiv |\psi\rangle \langle \psi |
\tag{2.128}
//}
Rather than a two-element vector, 𝜌 is a 2 × 2-element matrix.
 Following the definition, here are the density matrices for some states that we have encountered before:
//texequation{
|0\rangle\langle 0|
=
\begin{bmatrix}
1 \\
0
\end{bmatrix}
\begin{bmatrix}
1 & 0
\end{bmatrix}
=
\begin{bmatrix}
1 & 0 \\
0 & 0
\end{bmatrix}
\tag{2.129}
//}
//texequation{
|1\rangle\langle 1|
=
\begin{bmatrix}
0 \\
1
\end{bmatrix}
\begin{bmatrix}
0 & 1
\end{bmatrix}
=
\begin{bmatrix}
0 & 0 \\
0 & 1
\end{bmatrix}
\tag{2.130}
//}
//texequation{
|+\rangle\langle +|
=
\left(
\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 \\
1
\end{bmatrix}
\right)
\left(
\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 & 1
\end{bmatrix}
\right)
=
\frac{1}{2}
\begin{bmatrix}
1 & 1 \\
1 & 1
\end{bmatrix}
\tag{2.131}
//}
//texequation{
|-\rangle\langle -|
=
\left(
\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 \\
-1
\end{bmatrix}
\right)
\left(
\frac{1}{\sqrt{2}}
\begin{bmatrix}
1 & -1
\end{bmatrix}
\right)
=
\frac{1}{2}
\begin{bmatrix}
1 & -1 \\
-1 & 1
\end{bmatrix}
\tag{2.132}
//}
Note that basis states (@<m>{|0\rangle} and @<m>{|1\rangle}) have no off-diagonal entries, 
 but superposition states (@<m>{|+\rangle} and @<m>{|-\rangle}) do.
 Also note that the diagonal entries @<m>{\rho_{jj\}} represent the probability of 
 measuring state @<m>{|j\rangle} in the standard basis. 
 Therefore the sum of the diagonal entries, also known as the trace of the matrix, will always be 1.
//texequation{
\mathrm{Tr}(\rho) = \sum_j \rho_{jj} = 1
\tag{2.133}
//}
For a general state @<m>{|\psi\rangle = \cos\frac{\theta\}{2\} + e^{i\phi\}\sin\frac{\theta\}{2\}},
//texequation{
|\psi\rangle\langle\psi|
=
\begin{bmatrix}
\cos^2\frac{\theta}{2}
&
e^{-i\phi}\sin\frac{\theta}{2}\cos\frac{\theta}{2}
\\
e^{i\phi}\sin\frac{\theta}{2}\cos\frac{\theta}{2}
&
\sin^2\frac{\theta}{2}
\end{bmatrix}
\tag{2.134}
//}
One feature of the density matrix is that it can also represent quantum states that are not on the surface of the Bloch sphere,
 and thus cannot be defined by a state vector.
 Such states are known as mixed states. 
 One example of a mixed state is the description of the state of one qubit that is part of an entangled group of qubits. 
 We will defer that discussion until after we discuss two-qubit states and gates in more detail.

The second example is when the state is described as a probabilistic ensemble of pure states, 
 each with a specified probability. 
 For example, suppose we prepare a qubit in the |0⟩ state, but there is a 10% probability that our preparation is faulty, 
 and the qubit actually ends up in the |1⟩ state. 
 (This is very bad hardware that should probably be retired.) 
 If we want to model the uncertainty in that qubit’s state, 
 we use the following definition of the density matrix:
//texequation{
\rho \equiv \sum_i p_i |\psi_i\rangle \langle \psi_i |
\tag{2.135}
//}
where @<m>{p_i} is the probability of being in state @<m>{|\psi_i\rangle}. For our particular example,
//texequation{
|\psi_0\rangle = |0\rangle,\quad p_0 = 0.90
\tag{2.136}
//}
//texequation{
|\psi_1\rangle = |1\rangle,\quad p_1 = 0.10
\tag{2.137}
//}
@<m>{\rho = 0.90 |0\rangle\langle 0| + 0.10 |1\rangle\langle 1|}
//texequation{
\begin{aligned}
\rho
&= 0.90\,|0\rangle\langle 0| + 0.10\,|1\rangle\langle 1| \\
&=
\begin{bmatrix}
0.90 & 0 \\
0 & 0.10
\end{bmatrix}
\end{aligned}
\tag{2.138}
//}
We can distinguish a pure state from a mixed state using the trace of @<m>{ \rho^2 }:
//texequation{
\mathrm{Tr}(\rho^2) =
\begin{cases}
1 & \text{(pure state)} \\
< 1 & \text{(mixed state)}
\end{cases}
\tag{2.139}
//}
You can verify that this is true for the pure and mixed states shown above.

With respect to the Bloch sphere, a mixed state lies inside the surface; a vector from
 the origin to the point representing the mixed state is not a unit vector. 
 Any density matrix can be written in the following form:

//image[fig_2_7][(a) Bloch sphere representation of a mixed state, and (b) the result of applying a Hadamard gate (H) to the mixed state. Plots generated using Qiskit [2.][scale=1.0]{
//}

//texequation{
\rho
=
\frac{1}{2}
\begin{bmatrix}
1 + z & x - i y \\
x + i y & 1 - z
\end{bmatrix}
\tag{2.140}
//}
//texequation{
\rho
=
\frac{1}{2}
\left(
I + x\sigma_x + y\sigma_y + z\sigma_z
\right)
\tag{2.141}
//}
where @<m>{x}, @<m>{y}, and @<m>{z} are the Cartesian coordinates in the Bloch sphere representation.
 (For the proof, see Rieffel and Polak [8], Section 10.1.3.) 
 Using our simple mixed-state example above, the Bloch vector coordinates are (0, 0, 0.8), 
 shown in Figure 2.7, which is clearly not a unit vector.

How does the density matrix change when a unitary@<m>{U} is applied to a quantum state?
 Each state @<m>{|\psi_i\rangle} in the ensemble becomes @<m>{U|\psi_i\rangle}, so the new density matrix is
//texequation{
\rho'
=
\sum_i p_i\,U|\psi_i\rangle\langle\psi_i|U^\dagger
=
U\rho U^\dagger
\tag{2.142}
//}
As with the state vector, the unitary does not change the length of the Bloch vector associated with the state, 
 only its orientation.
To illustrate, let’s apply the Hadamard gate to our example mixed state, recalling that @<m>{H = H^\dagger}.
//texequation{
\begin{aligned}
\rho'
&= H\rho H \\
&=
\frac{1}{2}
\begin{bmatrix}
1 & 1 \\
1 & -1
\end{bmatrix}
\begin{bmatrix}
0.90 & 0 \\
0 & 0.10
\end{bmatrix}
\begin{bmatrix}
1 & 1 \\
1 & -1
\end{bmatrix} \\
&=
\frac{1}{2}
\begin{bmatrix}
1 & 1 \\
1 & -1
\end{bmatrix}
\begin{bmatrix}
0.90 & 0.90 \\
0.10 & -0.10
\end{bmatrix} \\
&=
\frac{1}{2}
\begin{bmatrix}
1 & 0.8 \\
0.8 & 1
\end{bmatrix} \\
&=
\begin{bmatrix}
0.5 & 0.4 \\
0.4 & 0.5
\end{bmatrix}
\end{aligned}
\tag{2.143}
//}
The Bloch coordinates for @<m>{\rho'} are (0.8, 0, 0)—the @<m>{x} and @<m>{z} coordinates have been swapped, as expected.

Finally, we want to be clear to distinguish a mixed state from a pure superposition state.
 Because the notion of probabilities factors into both, there can be some confusion.
 The following example illustrates the difference.

First, consider a pure state defined by a state vector:
//texequation{
|\psi\rangle = \frac{1}{\sqrt{2}} |0\rangle + \frac{1}{\sqrt{2}} |1\rangle. 
\tag{2.144}
//}
Next, consider the state represented by a density matrix:
//texequation{
\begin{aligned}
\rho &= \frac{1}{2} |0\rangle \langle 0| + \frac{1}{2} |1\rangle \langle 1| \\
&= \begin{bmatrix} 0.5 & 0 \\ 0 & 0.5 \end{bmatrix}. 
\end{aligned} \tag{2.145}
//}
If we measure @<m>{|\psi\rangle}, we have a 50% probability of observing @<m>{|0\rangle}
 and a 50% chance of observing @<m>{|1\rangle}.
 The same is true if we measure @<m>{\rho}: 50% @<m>{|0\rangle} and 50% @<m>{|1\rangle}. So are the two states the same?

Suppose we use state tomography (Section 2.3) to learn more about the state.
 We measure @<m>{|\psi\rangle} in the @<m>{x} basis by first computing @<m>{H|\psi\rangle}. 
 This time we observe @<m>{|0\rangle} 100% of the time, because @<m>{H|\psi\rangle = |0\rangle}. 
 Then we measure @<m>{H\rho H}, and we see 50% @<m>{|0\rangle} and 50% @<m>{|1\rangle}. 
 Why? First, we observe that @<m>{H\rho H = \rho}, so the state has not changed. 
 Second, we consider that the mixed state is @<m>{|0\rangle} 
 with 50% probability—measuring @<m>{H|0\rangle = |+\rangle} will yield 50% @<m>{|0\rangle} and 50% @<m>{|1\rangle}. 
 With 50% probability, the mixed state is @<m>{|1\rangle}, and measuring
 @<m>{H|1\rangle = |-\rangle} will also yield 50% @<m>{|0\rangle} and 50% @<m>{|1\rangle}. 
 Since this result is very different, it is clear that the two states are not the same.

We can also compute the Bloch sphere coordinates for each state, which again makes it clear that these are very different.
 The coordinates for |𝜓⟩ are (1, 0, 0), while the coordinates for @<m>{\rho} are (0, 0, 0).
 Note that any rotation of @<m>{\rho} will not change its coordinates,
 so measuring in any basis will result in the same 50-50 distribution of results. 
 This is known as a maximally mixed state, because we have no information about the state along any axis. 
 As a matter of fact, there are a number of different ensembles of pure states that can lead to the same density matrix, 
 which will be made clear in Exercise 2.5.

While there is uncertainty in the measurement of either state, the kinds of uncertainty are different.
 Measurement of @<m>{|\psi\rangle} exhibits quantum uncertainty; 
 we are uncertain of the result because of the intrinsic nature of the quantum state and the nature of measurement. 
 The density matrix, however, represents classical uncertainty about which quantum state was prepared.

== Exercises

2.1 In this exercise we explore the statistics of the expected value obtained by executing
 a large number of “shots” on a quantum circuit. 
 We note that the result of a measurement is either @<m>{|0\rangle} or @<m>{|1\rangle}, 
 which we can represent by +1 and -1, respectively. 
 A random variable @<m>{Z} with two possible values is an example of a random variable with a two-point distribution, 
 and the value of @<m>{Z} from the @<m>{i}th measurement we denote @<m>{z}. 
 According to the Central Limit Theorem, thedistribution of @<m>{\sum_{i=1\}^N z_i/N} tends 
 toward a Gaussian (Normal) distribution for large @<m>{N}, 
 with variance @<m>{\sigma^2/N}, where @<m>{\sigma^2} is the variance of @<m>{Z}. 
 In this exercisewe will find an upper bound on the value of @<m>{\sigma^2}, 
 and hence an upper bound on the standard deviation estimate @<m>{\sigma/\sqrt{N\}}.

 (a) Let Pr(@<m>{Z = 1}) = @<m>{p}, and Pr(@<m>{Z = -1}) = 1 - @<m>{p}. 
 Find E[@<m>{Z^2}] and E[@<m>{Z}].

 (b) Find the variance Var[@<m>{Z}] = E[@<m>{Z^2}] - E[@<m>{Z}]^2.

 (c) Show that the maximum value of the variance of @<m>{Z} is 1, so an upper bound on the standard deviation 
 of @<m>{\sum_{i=1\}^N z_i/N} is @<m>{\sigma \leq 1/\sqrt{N\}}.

2.2 A particular state |𝜓⟩ has been prepared a large number of times,
 and the following estimated probabilities are obtained from measurements: 
 @<m>{P_0(|\psi\rangle) = 0.8}, @<m>{P_1(|\psi\rangle) = 0.2}, @<m>{P_0(H |\psi\rangle) = 0.7}, @<m>{P_1(H |\psi\rangle) = 0.3}, @<m>{P_0(HS^\dagger |\psi\rangle) = 0.6},
 @<m>{P_1(HS^\dagger |\psi\rangle) = 0.4}. 
 Find estimates of the angles @<m>{\theta}, @<m>{\phi} locating the state on the Bloch Sphere.

2.3 Show that @<m>{X Y X = -Y} and use this to prove that @<m>{X R_y(\theta) X = R_y(-\theta)} [9].

2.4 Consider the following definitions:

 @<m>{A ≡ R_z(\phi)R_y(\theta/2)}

 @<m>{B ≡ R_y(-\theta/2)R_z(-(\lambda + \phi)/2)}

 @<m>{C ≡ R_z((\lambda - \phi)/2)}

 (a) Show that @<m>{ABC = I}.

 (b) Show that @<m>{AXBXC = R_z(\phi)R_y(\theta)R_z(\lambda)}. 
  The purpose of this exercise is to show that any single-qubit 
  unitary @<m>{U} can be implemented using @<m>{AXBXC} with appropriate choices of 
  @<m>{\phi}, @<m>{\theta}, and @<m>{\lambda}, up to a global phase.

2.5 Consider these two pure states:
//texequation{
|a\rangle = \sqrt{0.90} |0\rangle + \sqrt{0.10} |1\rangle, \quad |b\rangle = \sqrt{0.90} |0\rangle - \sqrt{0.10} |1\rangle
//}
 Compute the density matrix @<m>{\rho = \frac{1\}{2\} |a\rangle \langle a| + \frac{1\}{2\} |b\rangle \langle b|}. 
 Compare to Eq. (2.138). 
 Does a density matrix uniquely correspond to a particular ensemble of pure states?

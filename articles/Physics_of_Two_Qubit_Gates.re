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
 a set of gates capable of doing any arbitrary quantum computation@<fn>{fn-1} [10]. 
 Further, it turns out that any two-qubit entangling gate along with single-qubit gates is universal [11]. 
 Consequently a number of entangling schemes have been proposed.We will concentrate on two: 
 (1) coupled qubits that have the same frequency, 
 and (2) coupled qubits with different frequencies where a signal at the frequency of one is applied to the other. 
 This latter scheme is referred to as cross-resonant entanglement.

//footnote[fn-1][Since any quantum computation can be represented by a unitary matrix, an equivalent definition of a universal gate set is a set capable of representing any arbitrary unitary matrix.]

== @<m>{\sqrt{\text{iSWAP\}\}} Gate
It is helpful to begin this discussion by defining theSWAP gate and two of its cousins.
 As the name implies, a SWAP gate simply interchanges the states on two qubits. 
 In other words, it makes the following transformations: 
 @<m>{|00 \rangle} →  @<m>{|00\rangle},  @<m>{|01\rangle} →  @<m>{|10\rangle}, 
 @<m>{|10\rangle} → @<m>{|01\rangle}, and @<m>{|11\rangle} → @<m>{|11\rangle}. 
 It is represented by the matrix
//texequation{
\mathrm{SWAP} =
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 0 & 1 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 0 & 1
\end{bmatrix}
\tag{3.1}
//}
 The @<m>{\text{i\}}SWAPgate is similar, except when the qubit states are different: 
 @<m>{|01\rangle} → @<m>{i |10\rangle}, @<m>{|10\rangle} → @<m>{i |01\rangle}. 
 Its matrix representation is
//texequation{
\mathrm{iSWAP} =
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 0 & i & 0 \\
0 & i & 0 & 0 \\
0 & 0 & 0 & 1
\end{bmatrix}
\tag{3.2}
//}
The reason for introducing √ the SWAP and @<m>{\text{i\}}SWAP gates is really to motivate the
@<m>{\sqrt{\text{iSWAP\}\}} gate:
//texequation{
\sqrt{\mathrm{iSWAP}} =
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & \frac{1}{\sqrt{2}} & \frac{i}{\sqrt{2}} & 0 \\
0 & \frac{i}{\sqrt{2}} & \frac{1}{\sqrt{2}} & 0 \\
0 & 0 & 0 & 1
\end{bmatrix}
\tag{3.3}
//}
 As the name implies, it is straightforward to verify that
@<m>{\sqrt{\mathrm{iSWAP\}\} \cdot \sqrt{\mathrm{iSWAP\}\} = \mathrm{iSWAP\}}.
 The common symbols for these gates are shown in Figure 3.1.

As it turns out, a two-qubit gate very similar to the @<m>{\text{i\}}SWAP occurs naturally when
 two superconducting qubits are coupled with a capacitor [12]. 
 This “natural” gate is the same as the @<m>{\text{i\}}SWAP except for 
 the sign on the @<m>{\text{i\}} terms.@<fn>{fn-2}
 We will call this gate @<m>{\text{i\}}SWAP′.

//footnote[fn-2][Some authors, in fact, define the 𝑖SWAP with the negative signs in 𝑖; e.g., see (12, 13).]

Its square root is given by
//texequation{
\sqrt{\mathrm{iSWAP}'} =
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & \frac{1}{\sqrt{2}} & -\frac{i}{\sqrt{2}} & 0 \\
0 & -\frac{i}{\sqrt{2}} & \frac{1}{\sqrt{2}} & 0 \\
0 & 0 & 0 & 1
\end{bmatrix}
\tag{3.4}
//}
This is an entangling gate, since if we start off with either |01⟩ or |10⟩, 
 we end up with a superposition of the two states: a Bell state. 
 It’s not pretty, but the @<m>{\sqrt{\mathrm{iSWAP\}'\}} can be transformed 
 into a CNOT (within an irrelevant phase factor) by the following operations (see Exercise 3.1):

//image[fig_3_1][Common symbols for the SWAP, 𝑖SWAP, and√𝑖SWAP two-qubit gates.][scale=1.0]{
//}
//image[fig_3_2][Operations needed to convert a √𝑖SWAP′ gate to a CNOT.][scale=1.0]{
//}
//texequation{
\mathrm{CNOT}
=
\left[ I \otimes R_y(-\pi/2) \right]
\left[ R_x(-\pi/2) \otimes R_x(\pi/2) \right]
\sqrt{\mathrm{iSWAP}'}
\left[ I \otimes R_x(\pi) \right]
\sqrt{\mathrm{iSWAP}'}
\left[ I \otimes R_y(\pi/2) \right]
\tag{3.5}
//}
 The corresponding circuit is shown in Figure 3.2.Note that the order of the operations is
 opposite that shown in (3.5) since mathematically the operations begin by applying the
 right-most operator to the state vector, while in the circuit the first operation appears
 on the left with time increasing to the right.

== Coupled Tunable Qubits
We now turn our attention to the physics leading to the@<m>{\sqrt{\mathrm{iSWAP\}'\}} gate.
 We begin by considering the case of two coupled qubits with different frequencies, 
 but that can be tuned to the same frequency.@<fn>{fn-3}
 We will see that this systemnaturally generates entangled states 
 that can realize the @<m>{\sqrt{\mathrm{iSWAP\}'\}} gate [12].

//footnote[fn-3][We will see in Section 8.3 that tuning can be realized by applying a magnetic field to a qubit made using two Josephson junctions configured as a superconducting quantum interference device (SQUID).]

If the qubits are uncoupled, 
 then the system state is simply represented by the product of the single-qubit states:
//texequation{
|\psi\rangle_2 = |\psi_A\rangle \otimes |\psi_B\rangle
\tag{3.6}
//}
where @<m>{|\psi_A\rangle} and @<m>{|\psi_B\rangle} satisfy
//texequation{
i\hbar \partial_t |\psi_{A,B}\rangle = \mathcal{H}_{A,B} |\psi_{A,B}\rangle
\tag{3.7}
//}
and the single-qubit Hamiltonians are
//texequation{
\mathcal{H}_{A,B} = -\frac{1}{2}\hbar \omega_{0\,A,B} \sigma_z
\tag{3.8}
//}
Because the qubits are uncoupled, we could (for example) put qubit A in the state @<m>{|1\rangle}
 and qubit B in the state @<m>{|0\rangle} or vice versa, 
 and the system would remain in this state forall time.

Now consider what would happen if there were some mechanism coupling the two qubits. 
 If the frequencies were very different, 
 then energy conservation would keep them in the initial states regardless of the coupling.@<fn>{fn-4}

//footnote[fn-4][Here we are neglecting transitions owing to radiation or any other mechanism. If the only states available have energies ℏ𝜔𝐴 and ℏ𝜔𝐵, then we would have to either create or dispose of energy to make the transition if 𝜔𝐴 ≠ 𝜔𝐵.]

Onthe other hand, if the frequencieswere equal,
 then there is no fundamental reason why a photon on qubit A could not make a transition to qubit B 
 (assuming B is in the ground state) in the presence of some coupling mechanism. 
 In contrast, if both qubits were in the ground state or both were in the excited state, 
 then the states would again remain stationary in time. 
 In the first case there would be no energy to transfer,
 and in the second case one might consider an exchange of photons, 
 but since photons are indistinguishable, the state must remain the same.
 We can summarize the possible transitions as follows:
//texequation{
|\psi_{00}\rangle \to |\psi_{00}\rangle,\quad
|\psi_{01}\rangle \leftrightarrow |\psi_{10}\rangle,\quad
|\psi_{11}\rangle \to |\psi_{11}\rangle
\tag{3.9}
//}
where we have introduced the shorthand 
 @<m>{|\psi_0\rangle \otimes |\psi_1\rangle = |\psi_{01\}\rangle} with the state of qubit
 A on the left and qubit B on the right. 
 Since the states @<m>{|\psi_{00\}\rangle} and @<m>{|\psi_{11\}\rangle} don’t really do anything interesting, 
 let’s concentrate on what happens to states @<m>{|\psi_{01\}\rangle} and @<m>{|\psi_{10\}\rangle}.

Taking the energies of the states @<m>{|\psi_0\rangle} and @<m>{|\psi_1\rangle} 
 to be @<m>{-\frac{1\}{2\}\hbar \omega} and @<m>{\frac{1\}{2\}\hbar \omega}, respectively,
 the state @<m>{|\psi_{01\}\rangle} must satisfy the Schrödinger equation
//texequation{
i\hbar \partial_t |\psi_{01}\rangle
=
\left[\mathcal{H}_A \otimes I + I \otimes \mathcal{H}_B\right] |\psi_{01}\rangle
=
\frac{\hbar}{2}(-\omega_A + \omega_B)\,|\psi_{01}\rangle
\tag{3.10}
//}
while the state @<m>{|\psi_{10\}\rangle} must satisfy
//texequation{
i\hbar \partial_t |\psi_{10}\rangle
=
\frac{\hbar}{2}(\omega_A - \omega_B)\,|\psi_{10}\rangle
\tag{3.11}
//}
In the presence of coupling, the state vector will not satisfy either of these equations,
 but instead an equation with a Hamiltonian modified by an interaction term.

If the coupling is weak, it is reasonable to guess that the state at an arbitrary time
 will look like a combination of these two uncoupled states.
 Since we suspect that the system may transition between the states 
 @<m>{|\psi_{10\}\rangle} and @<m>{|\psi_{01\}\rangle}, 
 let’s make an educated guess that an approximation to the state might look like a sum of these states 
 with time-varying coefficients, 
 similar to what we did when describing Rabi oscillations in Section 2.2.2.3:
//texequation{
|\psi\rangle = c_{01}(t)\,|\psi_{01}\rangle + c_{10}(t)\,|\psi_{10}\rangle
\tag{3.12}
//}
 In this case the two Schrödinger equations need to be modified by adding terms that
 couple the equations:
//texequation{
i\hbar \partial_t \big(c_{01}(t)|\psi_{01}\rangle\big)
=
\frac{\hbar}{2}(-\omega_A + \omega_B)c_{01}(t)|\psi_{01}\rangle
+ \kappa\,|01\rangle\langle 10|\,c_{10}(t)|\psi_{10}\rangle
\tag{3.13}
//}
//texequation{
i\hbar \partial_t \big(c_{10}(t)|\psi_{10}\rangle\big)
=
\frac{\hbar}{2}(\omega_A - \omega_B)c_{10}(t)|\psi_{10}\rangle
+ \kappa\,|10\rangle\langle 01|\,c_{01}(t)|\psi_{01}\rangle
\tag{3.14}
//}
 Here we have introduced 𝜅 as a phenomenological constant to describe the coupling.

Proceeding as we did in Section 2.2.2.3,
 we see that applying the product rule to the time derivative on the left-hand-side generates two terms, 
 one of which cancels the first term on the right-hand-side. 
 This leaves
//texequation{
i\hbar \partial_t \big(c_{01}(t)\big)|\psi_{01}\rangle
=
\kappa\,c_{10}(t)\,|01\rangle\langle 10|\,|\psi_{10}\rangle
\tag{3.15}
//}
//texequation{
i\hbar \partial_t \big(c_{10}(t)\big)|\psi_{10}\rangle
=
\kappa\,c_{01}(t)\,|10\rangle\langle 01|\,|\psi_{01}\rangle
\tag{3.16}
//}
 Recall that
//texequation{
|\psi_{01}\rangle = e^{\,i\hbar(\omega_A - \omega_B)t/2}\,|01\rangle
//}
 and
//texequation{
|\psi_{10}\rangle = e^{-\,i\hbar(\omega_A - \omega_B)t/2}\,|10\rangle
//}
 Making this substitution and multiplying the first and second equations from the left by @<m>{\langle 01|} and @<m>{\langle 10|},
 respectively, 
 leads to
//texequation{
i \hbar \partial_t c_{01}(t) = \kappa c_{10}(t) e^{+i \Delta t}  
\tag{3.17}
//}
//texequation{
i \hbar \partial_t c_{10}(t) = \kappa c_{01}(t) e^{-i \Delta t} 
\tag{3.18}
//}
 where @<m>{\Delta = \omega_B - \omega_A}. 
 The coefficient @<m>{\kappa} will be determined by the details of the coupling.
 In Chapter 6 we show that for qubits consisting of nonlinear LC circuits coupled by a capacitor, 
 @<m>{\kappa = -i g} with @<m>{g > 0} (see (6.142) and (6.143)). 
 These equations are then identical in form to the coupled qubit states (2.103) and (2.104)! 
 It follows that the solutions are also given by (2.114) with @<m>{c_0 \to c_{01\}} and @<m>{c_1 \to c_{10\}}. 
 Referring to Figure 2.5 we see that significant state conversion only occurs when @<m>{\Delta \approx 0}, 
 or in other words when the qubit frequencies are matched. 
 In this case, the probability amplitudes evolve as (see (2.113) and (2.114)):
//texequation{
\begin{aligned}
c_{01}(t) &= c_{01}(0) \cos gt - i c_{10}(0) \sin gt \\
c_{10}(t) &= -i c_{01}(0) \sin gt + c_{10}(0) \cos gt
\end{aligned}
\tag{3.19} 
//}
 This can be conveniently written in matrix form:
//texequation{
\begin{bmatrix}
c_{01}(t) \\
c_{10}(t)
\end{bmatrix} = 
\begin{bmatrix}
\cos gt & -i \sin gt \\
-i \sin gt & \cos gt
\end{bmatrix}
\begin{bmatrix}
c_{01}(0) \\
c_{10}(0)
\end{bmatrix} \tag{3.20}
//}
 Making use of the fact that the states @<m>{|\psi_{00\}\rangle} and @<m>{|\psi_{11\}\rangle} do not change with time, 
 the evolution of the entire 2-qubit system can be written as the @<m>{4 \times 4} matrix [12]:
//texequation{
\begin{bmatrix}
c_{00}(t) \\
c_{01}(t) \\
c_{10}(t) \\
c_{11}(t)
\end{bmatrix} = 
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & \cos gt & -i \sin gt & 0 \\
0 & -i \sin gt & \cos gt & 0 \\
0 & 0 & 0 & 1
\end{bmatrix}
\begin{bmatrix}
c_{00}(0) \\
c_{01}(0) \\
c_{10}(0) \\
c_{11}(0)
\end{bmatrix} \tag{3.21}
//}
 We see that for @<m>{gt = \pi/4} this matrix corresponds to the @<m>{\sqrt{iSWAP'\}} gate.5 
 The coupling can be effectively turned off by detuning the qubits. 
 So the @<m>{\sqrt{iSWAP'\}} gate is formed by tuning the qubits to the same frequency, 
 leaving them tuned for a time @<m>{t = \pi/(4g)}, and then detuning them again.

The analysis showing how the coupling terms we have assumed arise from
 capacitively-coupled superconducting qubits is presented in Sections 6.4.6 and 6.4.7.

== Cross Resonance Scheme
Turning on and off the interaction by tuning the qubits requires tuning control lines in addition to the RF signal lines.
 This additional complexity impacts the scalability of the system. 
 In contrast, the cross-resonance scheme uses fixed-frequency qubits with fixed coupling, 
 and controls the interaction with RF signals—simplifying qubit control [14, 15]. 
 The key idea is that the frequency of qubit 2 is applied to qubit 1, or vice versa.
 Owing to the coupling, qubit 2 exhibits Rabi oscillations as expected, 
 but it also acquires a phase that depends on the state of qubit 1. 
 This provides the basic mechanism for entanglement. 
 This interaction can be controlled simply by varying the amplitude of the applied drive field.

The approximate Hamiltonian for this system with the drive signal applied to qubit 1 is (see (2.84) and (6.155))
//texequation{
\mathcal{H} = -\frac{1}{2}\hbar\omega_1\sigma_1^z + \hbar\Omega_1 \cos(\omega_d t) \sigma_1^x 
 - \frac{1}{2}\hbar\omega_2\sigma_2^z + \frac{1}{2}\hbar\omega_{xx}\sigma_2^x\sigma_1^x. 
\tag{3.22}
//}
 Here we have also made the substitution @<m>{g = \omega_{xx\}/2} to facilitate comparison with the
 literature [14].

It is worthwhile to pause for a moment to comment on various notations that are in use. 
 Equation (3.22) uses a shorthand for the Pauli operators. 
 Written explicitly in terms of tensor products this becomes
//texequation{
\begin{aligned}
\mathcal{H} &= -\frac{1}{2}\hbar\omega_1 I \otimes \sigma_z + \hbar\Omega_1 \cos(\omega_d t) I \otimes \sigma_x \\
&\quad - \frac{1}{2}\hbar\omega_2 \sigma_z \otimes I + \frac{1}{2}\hbar\omega_{xx} \sigma_x \otimes \sigma_x.
\end{aligned} 
\tag{3.23}
//}
 Yet anotherway of writing this when the connection back to gates is desired is to replace
 the Paulis with @<m>{X},@<m>{Y}, @<m>{Z} (Recall from Chapter 1 that in our notation @<m>{X} = @<m>{\sigma_x}, etc.). 
 Inaddition, the tensor product symbol is often omitted, so the Hamiltonian can also be written
//texequation{
\mathcal{H} = -\frac{1}{2}\hbar\omega_1 IZ + \hbar\Omega_1 \cos(\omega_d t) IX 
 - \frac{1}{2}\hbar\omega_2 ZI + \frac{1}{2}\hbar\omega_{xx} XX. \tag{3.24}
//}
 Setting @<m>{\omega_d = \omega_2}, making a series of unitary transformations, and applying the rotating wave approximation [14], 
 the effective Hamiltonian can be written
//texequation{
\mathcal{H}^{\text{eff}} = \frac{\hbar\omega_{xx}}{4} \frac{1}{1 + (\Delta/\Omega_1)^2} \left( XX 
 + \frac{\Delta}{\Omega_1} XZ \right) \tag{3.25}
//}
 where @<m>{\Delta = |\omega_1 - \omega_2|}. 
 If the qubits are sufficiently detuned so that @<m>{\Omega_1 \ll \Delta}, we then have
//texequation{
\mathcal{H}^{\text{eff}} \approx \frac{\Omega_1 \hbar \omega_{xx}}{4\Delta} XZ \tag{3.26}
//}
 From Schrödinger’s equation, the time evolution of the state vector is given by
//texequation{
\begin{aligned}
|\psi(t)\rangle &= e^{-i\mathcal{H}t/\hbar} |\psi(0)\rangle \\
&= \exp(-i\Omega_1\omega_{xx}tXZ/(4\Delta)) |\psi(0)\rangle  \\
&\equiv \exp(-i\beta\pi XZ/2) |\psi(0)\rangle
\end{aligned}
\tag{3.27}
//}
 where we have introduced the parameter @<m>{\beta = \Omega_1 \omega_{xx\} t/(2\pi \Delta)}. 
 Using (2.31) to expand the unitary operator, we have
//texequation{
|\psi(t)\rangle = [I \cos(\beta\pi/2) - iXZ \sin(\beta\pi/2)] |\psi(0)\rangle \tag{3.28}
//}
It is clear that if @<m>{\beta = 1}, then
//texequation{
e^{-i\mathcal{H}t/\hbar} = -iXZ \tag{3.29}
//}
or for a general value of @<m>{\beta}:
//texequation{
e^{-i\mathcal{H}t/\hbar} = (-iXZ)^\beta = e^{-i\pi\beta/2}(XZ)^\beta \tag{3.30}
//}
 This is significant, since @<m>{(XZ)^\beta} along with the one-qubit unitaries comprises 
 a universal gate set for quantum computing [14].
 In particular, for @<m>{\beta = 1/2}, we have @<m>{(XZ)^{1/2\}} to within a global phase factor, 
 and this unitary can be used to generate a CNOT [14, 16]:
//texequation{
\text{CNOT} = (IZ)^{-1/2} (XZ)^{1/2} (XI)^{-1/2} \tag{3.31}
//}
Alternatively, this can be written in terms of single-qubit rotations as
//texequation{
\text{CNOT} = [I \otimes R_z(-\pi/2)] [XZ]^{1/2} [R_x(-\pi/2) \otimes I] \tag{3.32}
//}
 To generate @<m>{(XZ)^{1/2\}}, we simply need to apply the excitation to qubit 1 for a time duration of
//texequation{
t = \frac{\pi \Delta}{\Omega_1 \omega_{xx}} \tag{3.33}
//}
 We see that increasing the coupling 𝜔𝑥𝑥 or drive amplitude Ω1 shortens the time interval needed, 
 while increasing the frequency separation of the qubits increases the time interval needed.

== Other Controlled Gates
The CNOT is a fundamental two-qubit gate and is necessary for universal quantum computing.
 It plays a large role in the logic of quantum algorithms, 
 and it often creates entangled states, as we saw with the Bell states in Section 1.6 and Exercise 1.2.

It is often convenient to add a control signal to some other gate, such as controlled-@<m>{Z},
 controlled-@<m>{H}, and so forth. 
 We can do this with any single-qubit gate, as shown in Figure 3.3. 
 The matrix describing a controlled-@<m>{U} or CU gate is shown below; 
 the subscripts indicate the control qubit followed by the target qubit, 
 while @<m>{U_{jk\}} indicates the matrix element (@<m>{j}, @<m>{k}) of @<m>{𝑈}.
//texequation{
\text{CU}_{0,1} = 
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & U_{00} & 0 & U_{01} \\
0 & 0 & 1 & 0 \\
0 & U_{10} & 0 & U_{11}
\end{bmatrix} \tag{3.34}
//}

We can implement a controlled-@<m>{U} gate using CNOT and single-qubit gates, 
 using a decomposition that is described in 2.4. 
 First, recall the @<m>{ZYZ} decomposition of a unitary @<m>{U}:
//texequation{
U = e^{i\alpha} R_z(\phi) R_y(\theta) R_z(\lambda) \tag{3.35}
//}
//image[fig_3_3][Controlled-U gate. If the control qubit is |1⟩,the U gate is applied to the target qubit. Otherwise, the gate is not applied.][scale=1.0]{
//}

We then define unitaries @<m>{A}, @<m>{B}, and @<m>{C}:
//texequation{
\begin{aligned}
A &\equiv R_z(\phi)R_y(\theta/2) \\
B &\equiv R_y(-\theta/2)R_z(-(\lambda-\phi)/2) \\
C &\equiv R_z((\lambda+\phi)/2)
\end{aligned}
\tag{3.36} 
//}
 which leads to the following relationships:
//texequation{
ABC = I \tag{3.37}
//}
//texequation{
AXBXC = R_z(\phi)R_y(\theta)R_z(\lambda) \tag{3.38}
//}
//texequation{
U = e^{i\alpha} AXBXC \tag{3.39}
//}
 First, consider how to add a global phase @<m>{\alpha} only if the control bit is |1⟩. 
 The unitary for the global phase is
//texequation{
U_\alpha = e^{i\alpha} I = \begin{bmatrix} e^{i\alpha} & 0 \\ 0 & e^{i\alpha} \end{bmatrix} \tag{3.40}
//}
and the matrix for the controlled version is
//texequation{
\begin{aligned}
\text{CU}_\alpha &= \begin{bmatrix} 1 & 0 & 0 & 0 \\ 0 & e^{i\alpha} & 0 & 0 \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & e^{i\alpha} \end{bmatrix} \\
&= \begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix} \otimes \begin{bmatrix} 1 & 0 \\ 0 & e^{i\alpha} \end{bmatrix} \\
&= I \otimes u1(\alpha)
\end{aligned}
\tag{3.41} 
//}
 In other words, we can perform a controlled global phase by simply applying a @<m>{u1} gate (Section 2.2.1.4) to the control qubit.
 This seems odd, but it does what we want: if the control qubit is @<m>{|0\rangle}, nothing happens; 
 when the control qubit is @<m>{|1\rangle} the phase is applied,
 keeping in mind that the phase affects the entire two-qubit state, not just the control qubit.

Then we use Eq. (3.39) and implement the controlled-@<m>{U} using the circuit shown in Figure 3.4.
 If the control qubit is @<m>{|0\rangle}, then the CNOT gates are not applied and @<m>{ABC} = @<m>{I}, so nothing happens. 
 If the control qubit is @<m>{|1\rangle}, then @<m>{U} is applied to the target qubit.
//image[fig_3_4][Implementation of controlled-U gate using Eq. (3.39).][scale=1.0]{
//}

== Two-Qubit States and the Density Matrix
We are now ready to resume our discussion of the density matrix as a representation of a quantum state.
 The definition of the density matrix remains the same as before:
//texequation{
\rho = \sum_j p_j \, |\psi_j\rangle \langle \psi_j|
\tag{3.42}
//}
 If @<m>{\psi_j} is a two-qubit state, then it is a four-element state vector and @<m>{\rho} is a @<m>{4 \times 4}-element matrix.
 We do have to review our definition of pure vs. mixed state, 
 because our previous definition involves the surface of the Bloch sphere. 
 There is no Bloch sphere for a twoqubit state, 
 so a pure state is one that can be described as a linear superposition of two-qubit state vectors. 
 A mixed state is, again, an ensemble of pure states, each with a probability. 
 In other words, a pure state will only have one term in Eq. (3.42).

Ifwe know the density matrices of each of the two qubits, 
 they can be combined using the tensor product to produce a combined density matrix. 
 In the following equations, we use @<m>{\rho_A} to denote the density matrix of qubit @<m>{A}, 
 and we use @<m>{\rho_{AB\}} to denote the density matrix of the two-qubit state involving qubits @<m>{A} and @<m>{B}.
//texequation{
\rho^{AB} = \rho^A \otimes \rho^B
\tag{3.43}
//}
 As an example, suppose qubit A is @<m>{|1\rangle} and qubit B is @<m>{|+\rangle}. 
 We can find the density matrix @<m>{\rho_{AB\}} in two ways:
//texequation{
\begin{aligned}
\rho^{AB} = |1+\rangle \langle 1+| \\
&= \begin{bmatrix}
0 \\ 0 \\ \frac{1}{\sqrt{2}} \\ \frac{1}{\sqrt{2}}
\end{bmatrix}
\begin{bmatrix}
0 & 0 & \frac{1}{\sqrt{2}} & \frac{1}{\sqrt{2}}
\end{bmatrix} \\
&=
\begin{bmatrix}
0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 \\
0 & 0 & \frac{1}{2} & \frac{1}{2} \\
0 & 0 & \frac{1}{2} & \frac{1}{2}
\end{bmatrix}
\end{aligned}
\tag{3.44}
//}
//texequation{
\begin{aligned}
\rho^{AB} = \rho_0 \otimes \rho_1 \\
&=
\begin{bmatrix}
0 & 0 \\
0 & 1
\end{bmatrix}
\otimes
\frac{1}{2}
\begin{bmatrix}
1 & 1 \\
1 & 1
\end{bmatrix} \\
&=
\begin{bmatrix}
0 & 0 & 0 & 0 \\
0 & 0 & 0 & 0 \\
0 & 0 & \frac{1}{2} & \frac{1}{2} \\
0 & 0 & \frac{1}{2} & \frac{1}{2}
\end{bmatrix}
\end{aligned}
\tag{3.45}
//}
 Note that Tr(@<m>{\rho_{AB\}}) = 1, and Tr((@<m>{\rho_{AB\}})2) = 1, which means it’s a pure state.

Now let’s consider one of the Bell states: @<m>{|\Psi^+\rangle} = @<m>{\frac{1\}{\sqrt{2\}\}(|01\rangle + |10\rangle)}. 
 The density matrix is:
//texequation{
\begin{aligned}
\rho^{AB}
&= \left( \frac{|01\rangle + |10\rangle}{\sqrt{2}} \right)
   \left( \frac{\langle 01| + \langle 10|}{\sqrt{2}} \right) \\
&= \frac{
|01\rangle\langle01|
+ |01\rangle\langle10|
+ |10\rangle\langle01|
+ |10\rangle\langle10|
}{2} \\
&= \frac{1}{2}
\begin{bmatrix}
0 & 0 & 0 & 0 \\
0 & 1 & 1 & 0 \\
0 & 1 & 1 & 0 \\
0 & 0 & 0 & 0
\end{bmatrix}
\end{aligned}
\tag{3.46}
//}
 This is also a pure state, because Tr((@<m>{\rho_{AB\}})2) = 1. 
 But it is not a product state—it cannot be decomposed into a tensor product of two state vectors 
 or a tensor product of two density matrices.

However, the advantage of the density matrix representation is that we can compute the density matrix of each qubit, 
 even when the total state is not a product state.
 We do this using an operation called a partial trace [17, 18]. 
 To recover the state of qubit @<m>{A}, 
 we “trace out” qubit @<m>{B} from the two-qubit density matrix:
//texequation{
\rho^{A} = \mathrm{Tr}_B(\rho^{AB})
\tag{3.47}
//}
 For our purposes, we will assume that the density matrix @<m>{\rho_{AB\}} is built using the standard
 basis states (@<m>{|0\rangle} and @<m>{|1\rangle}) for both qubits @<m>{A} and @<m>{B}. Then the density matrix can be decomposed as
//texequation{
\rho^{AB}
=
\sum_{i,j,k,l}
c_{ik,jl}
\,
|i\rangle \langle j|
\otimes
|k\rangle \langle l|
\tag{3.48}
//}
 where @<m>{i}, @<m>{j}, @<m>{k}, @<m>{l} ∈ {0, 1}, @<m>{i}, and @<m>{j} represent states of @<m>{A}, 
 and @<m>{k} and @<m>{l} are states of @<m>{B}. 
 In this notation, @<m>{ik} means a concatenation of the one-bit numbers @<m>{i} and @<m>{k}. 
 When written as a matrix, constant @<m>{c_{ik,jl\}} will appear in row @<m>{ik} and column @<m>{jl}.
//texequation{
\rho^{AB} =
\begin{bmatrix}
c_{00,00} & c_{00,01} & c_{00,10} & c_{00,11} \\
c_{01,00} & c_{01,01} & c_{01,10} & c_{01,11} \\
c_{10,00} & c_{10,01} & c_{10,10} & c_{10,11} \\
c_{11,00} & c_{11,01} & c_{11,10} & c_{11,11}
\end{bmatrix}
\tag{3.49}
//}
 To perform the partial trace Tr@<m>{B(\rho^{AB\}}), 
 we trace only the part of the matrix that is relevant to qubit @<m>{B}. 
 This leaves behind the density matrix associated with only qubit @<m>{A}.
//texequation{
\begin{aligned}
\rho^{A} = \mathrm{Tr}_B(\rho^{AB}) \\
&= \sum_{i,j,k,l}
c_{ik,jl}
\,
|i\rangle \langle j|
\,
\mathrm{Tr}(|k\rangle \langle l|) \\
&= \sum_{i,j,k,l}
c_{ik,jl}
\,
|i\rangle \langle j|
\,
\langle l | k \rangle \\
&= \sum_{i,j,k}
c_{ik,jk}
\,
|i\rangle \langle j|
\end{aligned}
\tag{3.50--3.52}
//}
 Equation (3.51) exploits the fact that Tr @<m>{|\alpha\rangle\langle\beta| = \langle\beta|\alpha\rangle} for two states. 
 Since the states @<m>{|k\rangle} and @<m>{|l\rangle} in this equation are basis states, they are orthogonal, 
 meaning that @<m>{\langle l | k \rangle} = 1 if @<m>{k = l}, and zero otherwise, leading to (3.52).

 Therefore, element @<m>{a_{ij\}} of @<m>{\rho^A} is given by:
//texequation{
a_{i,j} = \sum_k c_{ik,jk}
\tag{3.53}
//}
 leading to the following definition of @<m>{\rho^A}:
//texequation{
\rho^{A}
=
\mathrm{Tr}_B(\rho^{AB})
=
\begin{bmatrix}
c_{00,00} + c_{01,01} & c_{10,00} + c_{11,01} \\
c_{00,10} + c_{01,11} & c_{10,10} + c_{11,11}
\end{bmatrix}
\tag{3.54}
//}
 Performing a partial trace of @<m>{A} to recover @<m>{\rho^B} follows an equivalent path:
//texequation{
\begin{aligned}
\rho^{B} = \mathrm{Tr}_A(\rho^{AB}) \\
&= \sum_{i,j,k,l}
c_{ik,jl}
\,
\mathrm{Tr}(|i\rangle \langle j|)
\, |k\rangle \langle l| \\
&= \sum_{i,j,k,l}
c_{ik,jl}
\,
\langle j | i \rangle
\, |k\rangle \langle l| \\
&= \sum_{i,k,l}
c_{ik,il}
\, |k\rangle \langle l| \\
&=
\begin{bmatrix}
c_{00,00} + c_{10,10} & c_{01,00} + c_{11,10} \\
c_{00,01} + c_{10,11} & c_{01,01} + c_{11,11}
\end{bmatrix}
\end{aligned}
\tag{3.55--3.58}
//}
 Returning to the Bell state example (3.46),
//texequation{
\rho^{A}
=
\frac{1}{2}
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix},
\quad
\rho^{B}
=
\frac{1}{2}
\begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}
\tag{3.59}
//}
 You may recognize this as the density matrix of a maximally mixed state (Section 2.5).
 This is very interesting—the two-qubit state is pure, but the state of each qubit on its own is mixed. 
 Even though we know everything about the two-qubit system, 
 we can say nothing about the individual qubits within that system.

The density matrix and partial trace approach can easily be extended to more than two qubits.
 Instead of qubit @<m>{A} and qubit @<m>{B}, we can have 𝑛-qubit system @<m>{A} and 𝑚-qubit system @<m>{B}, 
 and we can extract the density matrix of either system from the joint density matrix @<m>{\rho^{AB\}}. 
 The only change is that @<m>{i} and @<m>{j} become @<m>{n}-bit values, 
 while @<m>{k} and @<m>{l} become @<m>{m}-bit values.
 We can also use any basis sets {@<m>{a_i}} and {@<m>{b_i}} for @<m>{A} and @<m>{B}, even different ones for each system. 
 The partial trace approach is very powerful, 
 and is particularly useful when describing the interaction of a quantum mechanical system with the surrounding environment.

== Exercises
3.1 Verify by direct computation that to within a global phase factor, the following relation is true:
//texequation{
\begin{aligned}
\mathrm{CNOT}
&=
\left[ I \otimes R_y\left(-\frac{\pi}{2}\right) \right]
\left[ R_x\left(-\frac{\pi}{2}\right) \otimes R_x\left(\frac{\pi}{2}\right) \right]
\sqrt{i\mathrm{SWAP}'} \\
&\quad \cdot
\left[ I \otimes R_x(\pi) \right]
\sqrt{i\mathrm{SWAP}'}
\left[ I \otimes R_y\left(\frac{\pi}{2}\right) \right]
\end{aligned}
//}

3.2 Given that
//texequation{
I \cos\left(\frac{\beta \pi}{2}\right)
- i XZ \sin\left(\frac{\beta \pi}{2}\right)
=
e^{-i\pi\beta/2 \, (XZ)^{\beta}}
//}
find @<m>{(XZ)^{1/2\}}.

3.3 Verify by direct computation that to within a global phase factor, the following relation is true:
//texequation{
\mathrm{CNOT}
=
(IZ)^{-1/2}
(XZ)^{1/2}
(XI)^{-1/2}
//}

3.4 Using the approach in Figure 3.4, create a quantum circuit to implement a controlled-@<m>{H} gate.
 (Hint: Eq. (2.48) will be helpful.)

3.5 Consider the following 3-qubit state:
//texequation{
|Q\rangle = |q_2 q_1 q_0\rangle
=
\frac{
|000\rangle + |001\rangle + |010\rangle + |111\rangle
}{2}
//}
What is the density matrix for qubit @<m>{q_2}?
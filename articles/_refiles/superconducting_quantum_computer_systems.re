= Superconducting Quantum Computer Systems

With the high-level description in Section 1.10 as motivation, 
 in this chapter we consider the components of the superconducting quantum computer system and their operation in more detail. 
 At RF and microwave frequencies, care must be taken about how components are connected. 
 In particular, when the wavelength of the signal is comparable to circuit/system dimensions, 
 familiar low-frequency circuit concepts such as Kirchoff’s voltage law no longer hold. 
 Instead, we must look at the connections between all of the components as transmission lines and ensure 
 that we are treating the signals conveyed by these transmission lines correctly. 
 Consequently we begin our in-depth consideration of the system components with transmission lines.

== Transmission Lines

=== General Transmission Line Equations
One type of transmission line that can be used at radio frequencies is the “ladder line” shown in Figure 4.1. 
 In this type of line, the conductor distance is maintained by insulating spacers placed at regular intervals. 
 As suggested in the diagram, currents flow in the conductors when signals are traveling along the line. 
 These currents create magnetic fields encircling the wires resulting in a small amount of inductance per unit length. 
 Since real, normal metals also have some small electrical resistance, the currents also see a small resistance per unit length. 
 Similarly, the two conductors may have different potentials at a given location along the line, 
 so that electric fields originate on one wire and terminate on the other. 
 The charge separation associated with this potential difference results in a small capacitance per unit length, 
 and if the insulators are not perfect, small leakage currents result in an equivalent conductance per unit length between the wires.

These observations suggest the equivalent circuit model shown in Figure 4.2. 
 As suggested by part (a) of the figure, lumped elements can be used to represent the series resistance, series inductance, 
 shunt leakage conductance, and shut capacitance, 
 provided the distance @<m>{\Delta z} is small compared to the distance that the signal propagates during one period of oscillation.

To analyze how the voltage and current change along the length of the line, 
 consider one section of the line as shown in Figure 4.2(b). 
 Applying Kirchoff’s voltage lawaround the outer loop gives

//image[fig_4_1][Ladder line used for radio frequency transmission.][scale=0.8]{
//}
//image[fig_4_2][Equivalent circuit for a transmission line. (a) Lumped elements can be used so long as the distance Δz is small compared to the distance traveled during a period of the signal. (b) Single section along the line for analysis.][scale=0.8]{
//}
//texequation{
v(z,t)
- i(z,t)\,R'\,\Delta z
- L'\,\Delta z\,\frac{\partial i(z,t)}{\partial t}
- v(z+\Delta z, t)
= 0
\tag{4.1}
//}
 This can be rearranged to obtain
//texequation{
\begin{aligned}
\frac{v(z+\Delta z, t) - v(z,t)}{\Delta z}
&=
- i(z,t)\,R'
- L'\,\frac{\partial i(z,t)}{\partial t}
\end{aligned}
\tag{4.2}
//}
 If we now take the limit as @<m>{\Delta z} → 0, 
 we have a differential equation relating the voltage @<m>{v(z, t)} and the current @<m>{i(z, t)}:
//texequation{
\frac{\partial v}{\partial z}
=
- i\,R'
- L'\,\frac{\partial i}{\partial t}
\tag{4.3}
//}
 Next, consider Kirchoff’s current law applied to node A in Figure 4.2(b):
//texequation{
i(z,t)
=
i(z+\Delta z, t)
+
G'\,\Delta z\, v(z+\Delta z, t)
+
C'\,\Delta z\,\frac{\partial v(z+\Delta z, t)}{\partial t}
\tag{4.4}
//}
 Rearranging this and taking the limit as before gives a second differential equation
 relating the current and voltage:
//texequation{
\begin{aligned}
\frac{i(z+\Delta z, t) - i(z,t)}{\Delta z}
&=
- G'\,v(z+\Delta z, t)
- C'\,\frac{\partial v(z+\Delta z, t)}{\partial t} \\
\Rightarrow \quad
\frac{\partial i}{\partial z}
&=
- G'\,v
- C'\,\frac{\partial v}{\partial t}
\end{aligned}
\tag{4.5}
//}
 Obtaining the general solution to Eqs. (4.3) and (4.5) is, unfortunately, rather complicated.
 However, solutions can be obtained easily for two important cases: lossless lines,
 and the sinusoidal steady state. 
 These will be considered in the next sections.

=== Lossless Transmission Lines
Since the loss is represented by the series resistance @<m>{R'} 
 and the parallel conductance @<m>{G'}, 
 we need only to set these quantities 
 to zero to obtain the equations for a lossless transmission line. 
 Equations (4.3) and (4.5) become
//texequation{
\frac{\partial v}{\partial z}
=
- L'\,\frac{\partial i}{\partial t}
\tag{4.6}
//}
 and
//texequation{
\frac{\partial i}{\partial z}
=
- C'\,\frac{\partial v}{\partial t}
\tag{4.7}
//}
 To solve these equations, we need to combine them to either eliminate @<m>{i} or @<m>{v}. 
 As an example, let us eliminate @<m>{v}. 
 The first step is to differentiate both sides of Eq. (4.6) with respect to @<m>{t}, 
 and both sides of Eq. (4.7) with respect to @<m>{z}:
//texequation{
\frac{\partial^2 v}{\partial t\,\partial z}
=
- L'\,\frac{\partial^2 i}{\partial t^2}
\tag{4.8}
//}
//texequation{
\begin{aligned}
\frac{\partial^2 i}{\partial z^2}
&=
- C'\,\frac{\partial^2 v}{\partial z\,\partial t} \\
&=
- C'\,\frac{\partial^2 v}{\partial t\,\partial z}
\end{aligned}
\tag{4.9}
//}
 In writing the last line of Eq. (4.9), 
 we have made use of the fact that @<m>{z} and @<m>{t} are independent variables, 
 so the order of differentiation does not matter. 
 The voltage @<m>{v} can now be eliminated from Eqs. (4.8) and (4.9) to obtain
//texequation{
\frac{\partial^2 i}{\partial t^2}
=
\frac{1}{L' C'}\,\frac{\partial^2 i}{\partial z^2}
\tag{4.10}
//}
 If we do a similar manipulation to eliminate @<m>{i} instead of @<m>{v},
 we will find that the equation for @<m>{v} is identical to Eq. (4.10). 
 This is called the wave equation, 
 for reasons that will become clear as we discuss its properties.

It is straightforward to show that any function of the form @<m>{f(z \pm ut)} 
 is a solution to Eq. (4.10). 
 To see this, let @<m>{s = z \pm ut} and substitute @<m>{f(s)} into Eq. (4.10). 
 Using @<m>{\partial s/\partial z = 1} and @<m>{\partial s/\partial t = \pm u}, we obtain
//texequation{
u^2 \frac{\partial^2 f}{\partial s^2}
= \frac{1}{L' C'} \frac{\partial^2 f}{\partial s^2}
\tag{4.11}
//}
 We conclude that @<m>{f(z \pm ut)} is a solution to the wave equation provided
//texequation{
u = \frac{1}{\sqrt{L' C'}}
\tag{4.12}
//}
 To interpret this,we note that @<m>{f(s) = f(z \pm ut)} represents an arbitrarywaveform 
 moving along the @<m>{z} axis. 
 To follow a particular point on the curve to see how fast it is moving,
 we hold the argument @<m>{s} constant. 
 Taking the time derivative of @<m>{s} and setting it to zero gives
//texequation{
\frac{ds}{dt} = \frac{dz}{dt} \pm u = 0
\tag{4.13}
//}
 or
//texequation{
\frac{dz}{dt} = \mp u
\tag{4.14}
//}

Consequently, the rate at which @<m>{z} must change to follow a constant point on the curve is given by @<m>{u}.
 We call @<m>{u} the phase velocity of the waveform. 
 The choice of sign simply means that the waveform can travel in either direction along the @<m>{z} axis.

Another important property of the signal that travels along the transmission line can
 be obtained by using what we have now learned with one of the original lossless transmission
 line equations, say Eq. (4.6). 
 If both @<m>{i} and @<m>{v} have solutions of the form @<m>{f(z \pm ut)} 
 so that @<m>{i = i_0 f(z \pm ut)} and @<m>{v = v_0 f(z \pm ut)} then Eq. (4.6) can be written
//texequation{
v_0 \frac{\partial f}{\partial s}
= \pm L' u\, i_0 \frac{\partial f}{\partial s}
\tag{4.15}
//}
 Solving for the ratio @<m>{v_0/i_0} gives
//texequation{
\begin{aligned}
\frac{v_0}{i_0}
&= \pm L' u \\
&= \pm L' \frac{1}{\sqrt{L' C'}} \\
&= \pm \sqrt{\frac{L'}{C'}}
\end{aligned}
\tag{4.16}
//}
 Since the ratio of voltage to current has dimensions of impedance, 
 we define the characteristic impedance @<m>{Z_c} of the transmission line as:
//texequation{
Z_c = \sqrt{\frac{L'}{C'}}
\tag{4.17}
//}
 We see, then, that if an arbitrary pulse shape is transmitted along a lossless transmission line,
 the pulse will propagate without distortion at the speed @<m>{1∕\sqrt{L' C'\}}, and at each point, 
 the ratio of the voltage to the current is given by the characteristic impedance (4.17). 
 When loss is present, both of these observations will need to be modified.

=== Transmission Lines with Loss

==== Sinusoidal Steady State
As indicated earlier, the presence of loss makes the general solution of the transmission
 line equations much more difficult, 
 but we can solve them fairly easily for the sinusoidal steady state. 
 In this case we can write@<fn>{fn-1}

//footnote[fn-1][Here we use the electrical engineering convention for time-dependence exp(𝑗𝜔𝑡), while in quantum mechanics and quantum computing it is more common to use the convention exp(−𝑖𝜔𝑡). So to avoid confusion, in this book we use the convention 𝑗 = −𝑖.]

//texequation{
\begin{aligned}
i(z,t) &= \mathrm{Re}\{ I(z)e^{j\omega t} \} \\
v(z,t) &= \mathrm{Re}\{ V(z)e^{j\omega t} \}
\end{aligned}
\tag{4.18}
//}
 where @<m>{I(z)} and @<m>{V(z)} are complex amplitudes that represent the magnitude and phase of
 the steady state signal as a function of position along the line. 
 In terms of these complex amplitudes, the transmission line Eqs. (4.3) and (4.5) become
//texequation{
\frac{\partial V}{\partial z} = -(R' + j\omega L')\, I
\tag{4.19}
//}
//texequation{
\frac{\partial I}{\partial z} = -(G' + j\omega C')\, V
\tag{4.20}
//}
 As in the lossless case, we proceed to eliminate either @<m>{I} or @<m>{V} to obtain a single differential equation. 
 For example, solving Eq. (4.19) for @<m>{I} and substituting the result into Eq. (4.20) gives
//texequation{
\frac{\partial}{\partial z}
\left(
-\frac{1}{R' + j\omega L'} \frac{\partial V}{\partial z}
\right)
= -(G' + j\omega C')V
//}
//texequation{
\frac{\partial^2 V}{\partial z^2}
= (R' + j\omega L')(G' + j\omega C')V
\tag{4.21}
//}
 where we define
//texequation{
\gamma^2 = (R' + j\omega L')(G' + j\omega C')
\tag{4.22}
//}
 Following a similar procedure to eliminate @<m>{V} results in an equation of the same form for @<m>{I}:
//texequation{
\frac{\partial^2 I}{\partial z^2} = \gamma^2 I
\tag{4.23}
//}
 You can easily verify that solutions to Eqs. (4.21) and (4.23) are of the form
//texequation{
V(z) = V_0^+ e^{-\gamma z} + V_0^- e^{\gamma z}
\tag{4.24}
//}
 and
//texequation{
I(z) = I_0^+ e^{-\gamma z} + I_0^- e^{\gamma z}
\tag{4.25}
//}
 where we define @<m>{\gamma} as the positive square root of Eq. (4.22):
//texequation{
\gamma = \sqrt{(R' + j\omega L')(G' + j\omega C')} = \alpha + j\beta
\tag{4.26}
//}
 The parameter @<m>{\gamma} is sometimes referred to as the propagation constant, 
 since it describes how the waves change as they move along the @<m>{z} direction. 
 (Note however that while @<m>{\gamma} is a constant with respect to position and time, it does vary with frequency.)

The coefficients of the terms on the right-hand side of Eqs. (4.24) and (4.25) can be
 related with the aid of Eq. (4.19):
//texequation{
\begin{aligned}
I(z)
&= -\frac{1}{R' + j\omega L'} \frac{\partial V}{\partial z} \\
&= -\frac{\gamma}{R' + j\omega L'} \left(-V_0^+ e^{-\gamma z} + V_0^- e^{\gamma z}\right) \\
&= \frac{\gamma}{R' + j\omega L'} \left(V_0^+ e^{-\gamma z} - V_0^- e^{\gamma z}\right)
\end{aligned}
\tag{4.27}
//}
 Comparing Eqs. (4.27) and (4.25), we see that
//texequation{
\frac{V_0^+}{I_0^+} = -\frac{V_0^-}{I_0^-} = \frac{R' + j\omega L'}{\gamma}
\tag{4.28}
//}
 This suggests that we define the characteristic impedance for the lossy line as
//texequation{
\begin{aligned}
Z_c
&= \frac{R' + j\omega L'}{\gamma} \\
&= \frac{R' + j\omega L'}{\sqrt{(R' + j\omega L')(G' + j\omega C')}} \\
&= \sqrt{\frac{R' + j\omega L'}{G' + j\omega C'}}
\end{aligned}
\tag{4.29}
//}
 Note that this reduces to the lossless expression (4.17) when @<m>{R' = G' = 0}.

Returning to the time domain, we have
//texequation{
\begin{aligned}
v(z,t)
&= \mathrm{Re}\{ V_0^+ e^{-\gamma z + j\omega t} + V_0^- e^{\gamma z + j\omega t} \} \\
&= \mathrm{Re}\{ |V_0^+| e^{-\alpha z - j\beta z + j\omega t + j\phi^+}
+ |V_0^-| e^{\alpha z + j\beta z + j\omega t + j\phi^-} \} \\
&= |V_0^+| e^{-\alpha z}
\underbrace{\cos(\omega t - \beta z + \phi^+)}_{\text{wave traveling in } +z \text{ direction}} \\
&\quad + |V_0^-| e^{\alpha z}
\underbrace{\cos(\omega t + \beta z + \phi^-)}_{\text{wave traveling in } -z \text{ direction}}
\end{aligned}
\tag{4.30}
//}
 To see why the first and second terms describe waves traveling in the positive and negative @<m>{z} directions, 
 respectively, consider what the value of @<m>{z} must do for the arguments
 of the cosines to remain constant. 
 For the first term, the value of @<m>{z} must increase as @<m>{t} increases, 
 so the constant point on the wave moves in the positive @<m>{z} direction. 
 Similarly, @<m>{z} must decrease as @<m>{t} increases in the second term for the argument of the cosine to remain constant. 
 To find the speed with which the constant point moves, 
 we set the arguments equal to a constant, solve for @<m>{z}, then differentiate with respect to time. 
 For example, from the argument of the cosine in the first term we have
//texequation{
\begin{aligned}
\omega t - \beta z + \phi^+ &= \text{const} \\
z &= \frac{\omega}{\beta} t + \frac{\phi^+ - \text{const}}{\beta} \\
u &= \frac{dz}{dt} = \frac{\omega}{\beta}
\end{aligned}
\tag{4.31}
//}
 Signals that have the form of sinusoidal variations moving along a particular direction are referred to as waves. 
 In the presence of loss, the sinusoids also decrease in amplitude as they move, or propagate, 
 according to the factors exp(±𝛼𝑧) in Eq. (4.30). 
 Solutions of this type are referred to as damped waves, and the decrease in amplitude caused by
 the loss is referred to as attenuation.

The attenuation of a transmission line is often described in terms of decibels per unit length, 
 or dB/m. 
 The attenuation of a cable in dB is obtained from the ratio of the voltage
 (or current) magnitude after propagating a distance @<m>{L}, 
 to the voltage (or current) magnitude at the input to the line:
//texequation{
\begin{aligned}
dB
&= -20\log_{10}\left(\frac{v(L)}{v(0)}\right) \\
&= -20\log_{10}\left(\frac{e^{-\alpha L}}{e^0}\right) \\
&= 20\alpha L \log_{10} e \\
&= 8.69\,\alpha L
\end{aligned}
\tag{4.32}
//}
 The attenuation per unit length is therefore
//texequation{
\frac{dB}{m} = 8.69\,\alpha
\tag{4.33}
//}
 An important parameter of a wave is the distance required to obtain a phase shift of @<m>{2\pi},
 called the wavelength. 
 To find this distance, we take the difference between the values
 of the argument of one of the cosines in Eq. (4.30) at two difference positions, 
 set this difference equal to @<m>{2\pi}, and solve for the necessary separation. 
 For example, for thewave traveling in the @<m>{+z} direction:
//texequation{
\begin{aligned}
[\omega t - \beta (z - \lambda) + \phi^+]
- [\omega t - \beta z + \phi^+]
&= 2\pi \\
\beta \lambda &= 2\pi \\
\lambda &= \frac{2\pi}{\beta}
\end{aligned}
\tag{4.34}
//}
 Since @<m>{\beta = 2\pi/\lambda} can be interpreted as the number of wavelengths in a distance of @<m>{2\pi} meters, 
 @<m>{\beta} is referred to as the wave number.@<fn>{fn-2} 
 These general results for velocity and wavelength can be easily reduced to the lossless case. 
 From Eq. (4.22) with @<m>{R' = G' = 0},

//footnote[fn-2][In some contexts, the quantity 1∕𝜆 is referred to as the “wave number.” In this case it represents the number of wavelengths per meter, as opposed to the number per 2𝜋 meters. This alternate definition is sometimes used in optics.]

//texequation{
\gamma
= \sqrt{j\omega L'\, j\omega C'}
= \sqrt{-\omega^2 L' C'}
= j\omega \sqrt{L' C'}
= j\beta
\tag{4.35}
//}
 and
//texequation{
\beta = \omega \sqrt{L' C'}
\tag{4.36}
//}
 The phase velocity is therefore
//texequation{
u = \frac{\omega}{\beta} = \frac{1}{\sqrt{L' C'}}
\tag{4.37}
//}
 as before. 
 The wavelength in the lossless case is
//texequation{
\begin{aligned}
\lambda
&= \frac{2\pi}{\beta} \\
&= \frac{2\pi}{\omega \sqrt{L' C'}} \\
\lambda
&= \frac{1}{f \sqrt{L' C'}}
\end{aligned}
\tag{4.38}
//}
 Equations (4.36) and (4.38) relating the angular frequency to the wave number or the
 frequency to the wavelength are referred to as dispersion relations.

==== Low Loss Transmission Lines
In many practical situations, the loss (or attenuation) of a transmission line is small but not negligible.
 For this reason it is useful to examine the expressions for the transmission
 line parameters and find approximations that are valid in the small-loss limit. 
 In making these approximations, 
 we will keep only the lowest-order non-vanishing terms for the parameters 
 @<m>{Z_c}, @<m>{\alpha}, @<m>{\beta}, and @<m>{\lambda}.

Let us first consider the characteristic impedance given by Eq. (4.29).
 The conditions for low loss are
//texequation{
\begin{aligned}
R' \ll \omega L' \\
G' \ll \omega C'
\end{aligned}
\tag{4.39}
//}
 With this limit in mind, we can write the characteristic impedance as
//texequation{
Z_c
= \sqrt{
\frac{
j\omega L'\left(1 + \frac{R'}{j\omega L'}\right)
}{
j\omega C'\left(1 + \frac{G'}{j\omega C'}\right)
}
}
\tag{4.40}
//}
 Now if the conditions given by (4.39) are satisfied, 
 then the terms inside the parentheses in both the numerator and denominator are approximately equal to unity, 
 and the characteristic impedance is well-approximated to lowest-order by that of a lossless line:
//texequation{
Z_c \approx \sqrt{\frac{L'}{C'}}
\tag{4.41}
//}
 Next consider the propagation constant 𝛾, from which we can obtain 𝛼 and 𝛽. 
 From Eq. (4.22) and anticipating the limit (4.39), the propagation constant can be written
//texequation{
\begin{aligned}
\gamma
&= \sqrt{
-\omega^2 L' C'
\left[
1 - \frac{R'G'}{\omega^2 L' C'}
- j\omega \left(\frac{L'G' + R'C'}{\omega^2 L' C'}\right)
\right]
} \\
&= j\omega \sqrt{L' C'}
\sqrt{
1 - \frac{R'G'}{\omega^2 L' C'}
- j\left(\frac{G'}{\omega C'} + \frac{R'}{\omega L'}\right)
}
\end{aligned}
\tag{4.42}
//}

Now consider the terms in the square root carefully. 
 In view of the assumptions (4.39), the third term is linear in small quantities 
 while the second term is quadratic in small quantities. 
 We conclude that to lowest order, the second term can be neglected.
 Further, we note that
//texequation{
\sqrt{1 + x} \approx 1 + \frac{x}{2}
\tag{4.43}
//}
if @<m>{|x| \ll 1}. Making these two approximations, Eq. (4.42) can be written
//texequation{
\begin{aligned}
\gamma 
&\approx j\omega \sqrt{L' C'} \left[ 1 - \frac{j}{2} \left( \frac{G'}{\omega C'} + \frac{R'}{\omega L'} \right) \right] \\
&= j\omega \sqrt{L' C'} 
+ \frac{1}{2} \left( G' \sqrt{\frac{L'}{C'}} + R' \sqrt{\frac{C'}{L'}} \right) \\
&\approx j\omega \sqrt{L' C'} 
+ \frac{1}{2} \left( G' Z_c + \frac{R'}{Z_c} \right)
\end{aligned}
\tag{4.44}
//}
 Here we have also used the approximation (4.41) for @<m>{Z_c} in the last step. 
 Equating the real part of this expression with @<m>{\alpha} and the imaginary part with @<m>{\beta} gives
//texequation{
\alpha \approx \frac{1}{2} \left( G' Z_c + \frac{R'}{Z_c} \right)
\tag{4.45}
//}
//texequation{
\beta \approx \omega \sqrt{L' C'}
\tag{4.46}
//}
 It follows that @<m>{u} and @<m>{\lambda} are also approximated by their lossless values to lowest order:
//texequation{
u = \frac{\omega}{\beta} \approx \frac{1}{\sqrt{L' C'}}
\tag{4.47}
//}
//texequation{
\lambda = \frac{2\pi}{\beta} \approx \frac{1}{f\sqrt{L' C'}}
\tag{4.48}
//}
 We conclude that in the low loss limit we can approximate the attenuation constant @<m>{\alpha} with (4.45), 
 and the remainder of the parameters with their lossless expressions.

== Terminated Lossless Line
Since the whole point of a transmission line is to carry signals from one place to another,
 it is critical that we understand what happens when we connect something (like a qubit!) 
 to the end of the transmission line. 
 The thing connected to the end of the transmission line is called the load. 
 As we will see, the amount of power delivered to the load depends critically 
 on how the load impedance compares with the characteristic impedance of the transmission line. 
 For simplicity, we will assume the line is lossless.

=== Reflection Coefficient
To begin the discussion, consider the geometry shown in Figure 4.3.
 Atransmission line with characteristic impedance @<m>{𝑍𝑐} andwave number @<m>{𝛽} is 
 terminated with the impedance @<m>{𝑍𝐿}. 
 In the most general case, we imagine that we can have waves traveling both to the 
 right (incident on the load) and to the left (reflected from the load). 
 In this case, general expressions for the voltage and current along the line are
//image[fig_4_3][transmission line terminated with a load impedance. Note that two coordinate systems have their origins at the load location: the coordinate z increases to the right, and the coordinate l increases to the left.][scale=0.8]{
//}
//texequation{
\begin{aligned}
V(z) &= V_0^+ e^{-j\beta z} + V_0^- e^{j\beta z}
\end{aligned}
\tag{4.49}
//}
//texequation{
\begin{aligned}
I(z) 
&= I_0^+ e^{-j\beta z} + I_0^- e^{j\beta z} \\
&= \frac{V_0^+}{Z_c} e^{-j\beta z} - \frac{V_0^-}{Z_c} e^{j\beta z}
\end{aligned}
\tag{4.50}
//}
 where we have used (4.27) and (4.28) to relate the currents and voltages of the incident
 and reflected waves in terms of the characteristic impedance. 
 In particular, note that the sign of the reflected wave term in the expression for current (4.50) has changed.

At the load, the total voltage and current must be related by Ohm’s law:
//texequation{
\begin{aligned}
Z_L 
&= \frac{V_L}{I_L}
= \frac{V(0)}{I(0)} \\
&= \frac{V_0^+ + V_0^-}{\frac{V_0^+}{Z_c} - \frac{V_0^-}{Z_c}} \\
&= Z_c \frac{V_0^+ + V_0^-}{V_0^+ - V_0^-} \\
&= Z_c \frac{1 + \frac{V_0^-}{V_0^+}}{1 - \frac{V_0^-}{V_0^+}} \\
&= Z_c \frac{1 + \Gamma}{1 - \Gamma}
\end{aligned}
\tag{4.51}
//}
 Here we have defined the voltage reflection coefficient
//texequation{
\begin{aligned}
\Gamma \equiv \frac{V_0^-}{V_0^+}
\end{aligned}
\tag{4.52}
//}
 Equation (4.51) can be solved for the reflection coefficient in terms of the impedances:
//texequation{
\begin{aligned}
\Gamma = \frac{Z_L - Z_c}{Z_L + Z_c}
\end{aligned}
\tag{4.53}
//}
 It is important to note that the only way to prevent some portion of the incident
 wave from being reflected is for the load impedance to exactly equal the characteristic  impedance of the line. 
 This is referred to as a matched load. 
 In practice, the load is almost never perfectly matched, 
 so some portion of the incident signal will be reflected from the load.

=== Power (Flow of Energy) and Return Loss
Recall that one of the convenient things about phasor (complex) notation is that the
 time average of the product of two quantities is easily obtained by multiplying one
 quantity by the complex conjugate of the other, 
 then taking half the real part of the result. 
 With this tool in hand, let us consider the time averaged power (flow of energy)
 in the incident and reflected waves on the transmission line. 
 The time averaged power in the incident wave is
//texequation{
\begin{aligned}
\langle P_{\mathrm{inc}} \rangle 
&= \frac{1}{2} \mathrm{Re}\left\{ V_0^+ (I_0^+)^* \right\} \\
&= \frac{1}{2} \mathrm{Re}\left\{ V_0^+ \left( \frac{V_0^+}{Z_c} \right)^* \right\} \\
&= \frac{|V_0^+|^2}{2 Z_c}
\end{aligned}
\tag{4.54}
//}
 T his is the power incident on the load. 
 However, not all of the incident power is absorbed by the load in general. 
 The power of the wave reflected from the load is
//texequation{
\begin{aligned}
\langle P_{\mathrm{ref}} \rangle 
&= \frac{1}{2} \mathrm{Re}\left\{ V_0^- (I_0^-)^* \right\} \\
&= \frac{1}{2} \mathrm{Re}\left\{ V_0^- \left( -\frac{V_0^-}{Z_c} \right)^* \right\} \\
&= -\frac{|V_0^-|^2}{2 Z_c}
\end{aligned}
\tag{4.55}
//}
 The minus sign on the reflected power indicates that the energy is actually flowing to the left, 
 away from the load. 
 The ratio of the reflected to incident power in magnitude is given conveniently 
 in terms of the reflection coefficient:
//texequation{
\begin{aligned}
\left| \frac{\langle P_{\mathrm{ref}} \rangle}{\langle P_{\mathrm{inc}} \rangle} \right|
&= \left| \frac{V_0^-}{V_0^+} \right|^2 \\
&= |\Gamma|^2
\end{aligned}
\tag{4.56}
//}
 The fraction of power that is reflected is referred to as the return loss and is usually
 expressed in dB:
//texequation{
\begin{aligned}
RL 
&= -10 \log_{10} \left| \frac{\langle P_{\mathrm{ref}} \rangle}{\langle P_{\mathrm{inc}} \rangle} \right| \\
&= -10 \log_{10} |\Gamma|^2 \\
&= -20 \log_{10} |\Gamma|
\end{aligned}
\tag{4.57}
//}
 Note that since @<m>{|\Gamma| ≤ 1}, the minus sign ensures that the return loss is always positive.
 There is a common temptation to want to make the “loss” negative 
 (i.e., to say, “the return loss is -10 dB”), but this would result in a double negative; 
 a negative loss would be the same as gain!

In practice, it is commonly assumed that the match is acceptable if at least 90% of the
 incident power is absorbed by the load. 
 This corresponds to a return loss of 10 dB.

=== Standing Wave Ratio (SWR)
Another common way of quantifying the degree of mismatch between a load and a line is the standing wave ratio. 
 Since the incident and reflected waves are traveling in opposite directions, 
 they go in and out of phase with each other as you move along the line. 
 Consequently, at some points they add constructively to give a total voltage higher than that of the incident wave, 
 and at other points they add destructively to give a total voltage lower than that of the incident wave. 
 The ratio of the largest value of the voltage magnitude to that of the smallest value 
 is called the voltage standing wave ratio, or VSWR. 
 (You sometimes hear people try to pronounce this acronym, 
 resulting in something that sounds like, “viz-wahr.”) 
 It turns out that the magnitude of the current fluctuates in a similar manner, 
 and if you take the ratio of the maximum to minimum values 
 you will get the identical numerical result for a lossless line. 
 Consequently it is not really necessary to add the qualifier, “voltage,” 
 and it is also common to simply call this ratio the standing wave ratio, 
 or SWR (not usually pronounced!). 
 The SWR can be obtained from the reflection coefficient as follows:
//texequation{
\begin{aligned}
VSWR = SWR 
&= \frac{|V|_{\max}}{|V|_{\min}} \\
&= \frac{|V_0^+| + |V_0^-|}{|V_0^+| - |V_0^-|} \\
&= \frac{1 + |V_0^-|/|V_0^+|}{1 - |V_0^-|/|V_0^+|} \\
&= \frac{1 + |\Gamma|}{1 - |\Gamma|}
\end{aligned}
\tag{4.58}
//}
 If the line is perfectly matched, @<m>{|\Gamma| = 0}, and the SWR is 1 (or 1:1). 
 On the other hand, if all of the power is reflected, @<m>{|\Gamma| = 1} and the SWR→ ∞. 
 As mentioned previously, a match is usually considered acceptable if 90% of the power is delivered to the load,
 and this occurs when the Return Loss is 10 dB. 
 This situation corresponds to an SWR of about 2 (or 2:1).

It is also convenient to express the magnitude of the reflection coefficient in terms of the SWR:
//texequation{
\begin{aligned}
|\Gamma| = \frac{SWR - 1}{SWR + 1}
\end{aligned}
\tag{4.59}
//}
 It is instructive to consider the shape of the voltage waveform along the line in a bit more detail. 
 Referring to the coordinate systems shown in Figure 4.3, the voltage at a
 distance @<m>{l} to the left of the load is obtained by setting @<m>{z = -l} in Eq. (4.49). 
 Expressed in terms of the reflection coefficient, we obtain
//texequation{
\begin{aligned}
V(-l) 
&= V_0^+ \left[ e^{j\beta l} + \Gamma e^{-j\beta l} \right] \\
&= V_0^+ e^{j\beta l} \left[ 1 + \Gamma e^{-j2\beta l} \right]
\end{aligned}
\tag{4.60}
//}
 Next, let us explicitly show the magnitude and phase of the reflection coefficient,
 @<m>{\Gamma = |\Gamma| e^{j\theta}}. 
 Substituting this into Eq. (4.60) and taking the magnitude of the entire expression gives
//texequation{
\begin{aligned}
|V(-l)| = |V_0^+| \left| 1 + |\Gamma| e^{j(\theta - 2\beta l)} \right|
\end{aligned}
\tag{4.61}
//}
 An example of the voltage magnitude described by this equation is shown in Figure 4.4.
 Although the wave patterns for the incident and reflected waves move to the right and left, 
 respectively, the pattern for the total voltage magnitude is stationary. 
 This voltage pattern is called the standing wave pattern or envelope.

=== Impedance as a Function of Position
Although the current pattern has peaks and valleys just like the voltage pattern, 
 the peaks and valleys do not occur at the same locations. 
 As a result, the ratio of voltage to current varies continuously along the line. 
 If the line were cut at some point a distance @<m>{l} from the load as shown in Figure 4.5, 
 the input impedance seen looking into the line 
 at that point would be the ratio of the voltage to current at that distance from the load:

//image[fig_4_4][Voltage standing wave pattern along a transmission line with a mismatched load.][scale=0.8]{
//}
//image[fig_4_5][Impedance looking into a terminated transmission line of length l.][scale=0.8]{
//}
//texequation{
\begin{aligned}
Z_{\mathrm{in}} 
&= \frac{V(-l)}{I(-l)} \\
&= \frac{V_0^+ \left[ e^{j\beta l} + \Gamma e^{-j\beta l} \right]}
{\frac{V_0^+}{Z_c} \left[ e^{j\beta l} - \Gamma e^{-j\beta l} \right]} \\
&= Z_c
\frac{e^{j\beta l} + \Gamma e^{-j\beta l}}
{e^{j\beta l} - \Gamma e^{-j\beta l}}
\end{aligned}
\tag{4.62}
//}
 This can be expressed entirely in terms of the impedances using Eq. (4.53). 
 Making the substitution for Γ and simplifying gives
//texequation{
\begin{aligned}
Z_{\mathrm{in}} 
&= Z_c
\frac{(Z_L + Z_c)e^{j\beta l} + (Z_L - Z_c)e^{-j\beta l}}
{(Z_L + Z_c)e^{j\beta l} - (Z_L - Z_c)e^{-j\beta l}} \\
&= Z_c
\frac{
Z_L (e^{j\beta l} + e^{-j\beta l})
+ Z_c (e^{j\beta l} - e^{-j\beta l})
}{
Z_L (e^{j\beta l} - e^{-j\beta l})
+ Z_c (e^{j\beta l} + e^{-j\beta l})
} \\
&= Z_c
\frac{
Z_L \cos \beta l + j Z_c \sin \beta l
}{
j Z_L \sin \beta l + Z_c \cos \beta l
} \\
&= Z_c
\frac{
Z_L + j Z_c \tan \beta l
}{
Z_c + j Z_L \tan \beta l
}
\end{aligned}
\tag{4.63}
//}

Since the tangent is periodic in 𝜋 rather than 2𝜋, the impedance is periodic
 in distances of half a wavelength rather than a wavelength.

Three limiting cases give some insight into the behavior of the impedance function (4.63).
 In the case of a short circuit, @<m>{Z_L = 0} and the input impedance becomes
//texequation{
\begin{aligned}
Z_{\mathrm{sc}} = j Z_c \tan \beta l
\end{aligned}
\tag{4.64}
//}
However, if the line is open circuited so that @<m>{Z_L \to \infty}, the input impedance becomes
//texequation{
\begin{aligned}
Z_{\mathrm{oc}} = -j Z_c \cot \beta l
\end{aligned}
\tag{4.65}
//}
It is interesting to note the relationship
//texequation{
\begin{aligned}
Z_{\mathrm{sc}} Z_{\mathrm{oc}} = Z_c^2
\end{aligned}
\tag{4.66}
//}
 This suggests an experimental technique for measuring the characteristic impedance of a transmission line!

If the line is electrically short, 𝛽𝑙 ≪ 1, the tangent can be approximated by its argument
 and the cotangent by the inverse of its argument. 
 Comparing with the circuit equations @<m>{X_L = 𝑗𝜔𝐿} and @<m>{X_C = −𝑗∕𝜔𝐶}, 
 we see that an electrically short length of short-circuited transmission line acts like an inductor 
 whose inductance is proportional to length, 
 and a short length of open-circuited transmission line acts like a capacitor 
 whose capacitance is proportional to length.

Finally, if the line is terminated in the characteristic impedance of the line, i.e.,
 @<m>{Z_L = Z_c}, then the input impedance is simply equal to the characteristic impedance regardless
 of the length of the transmission line.

=== Quarter Wave Transformer
From the previous discussions, we see that it is generally desirable for a transmission
 line to be terminated in a matched impedance; i.e., 
 a real impedance equal to the characteristic impedance of the line. Under these conditions, 
 the reflection coefficient will be zero, indicating that all of the incident power is absorbed by the load. 
 Further, the input impedance of the line will simply be equal to the characteristic impedance
 regardless of the length.

The quarter wave transformer is a common and effective technique used for impedance matching.
 Consider the transmission line circuit terminated in a real impedance @<m>{R_L} illustrated in Figure 4.6.

For a quarter wavelength section of transmission line, the argument to the tangent functions 
 in Eq. (4.63) is @<m>{\beta l = (2\pi/\lambda)(\lambda/4) = \pi/2}. 
 Since the tangent increases without bounds as the argument approaches @<m>{\pi/2}, 
 the tangent terms dominate the numerator and denominator of the expression for the input impedance (4.63), 
 and we find
//image[fig_4_6][A real impedance can be matched to a lossless transmission line using a quarter wavelength line whose impedance is the geometric mean of the load and line to be matched. This is referred to as a quarter wave matching transformer.][scale=0.8]{
//}
//texequation{
\begin{equation*}
\lim_{\beta l \to \pi/2} Z_{\mathrm{in}}
=
\frac{Z_1^2}{R_L}.
\tag{4.67}
\end{equation*}
//}
 If we want to eliminate reflections (i.e., Γ = 0), then we want @<m>{Z_{\mathrm{in\}\} = Z_c}.
 Imposing this condition on Eq. (4.67) leads to
//texequation{
\begin{equation*}
Z_c
=
\frac{Z_1^2}{R_L}.
\tag{4.68}
\end{equation*}
//}
 Consequently we see that we can match any real load @<m>{R_L} to a line with impedance @<m>{Z_c} provided 
 we use a quarter-wavelength segment of transmission line whose characteristic
 impedance is the geometric mean of @<m>{R_L} and @<m>{Z_c}:
//texequation{
\begin{equation*}
Z_1
=
\sqrt{Z_c R_L}.
\tag{4.69}
\end{equation*}
//}
 It is important to keep in mind, however, that this match will only be perfect at the
 single frequency where @<m>{l = \lambda/4}. 
 At other frequencies there will be some reflections from the load. 
 The bandwidth over which the SWR is 2:1 or less depends on the degree of mismatch 
 between the load and the line to be matched. 
 For example, if a 122 Ω line is used to match a 300 Ω load to a 50 Ω line, 
 the impedance bandwidth for an SWR < 2:1 is about ±20%. 
 It is also important to keep in mind that this technique only works for real load impedances. 
 However, any load impedance can be transformed into a real impedance at a given frequency 
 by adding the appropriate lumped capacitance or inductance in series or parallel with the load. 
 Further, since short segments of transmission line can be made to look like either inductors or capacitors, 
 any load impedance can be transformed to a purely real impedance by putting another appropriate segment
 of transmission line in series or parallel with the load.

=== Coaxial, Microstrip, and Coplanar Lines
Although the ladder line is conceptually convenient since the geometry resembles its lumped-circuit model,
 it is mainly used as a low-loss feed line for high-frequency (i.e., below 30 MHz) antennas. 
 It is not of interest for superconducting quantum computing systems owing to the lack of shielding 
 and incompatibility with nanofabrication methods. 
 Instead, coaxial lines (or coax for short) are used to convey signals between component blocks, 
 and coplanar transmission lines are typically used to convey signals on quantum computing chips. 
 The simpler microstrip lines are used in some components of interest for superconducting computer 
 control and readout systems.

The detailed analysis of the fields and modes of these transmission lines are beyond the scope of our present
 discussion, but expressions for the characteristic impedance @<m>{Z_𝑐}
 and effective relative permittivity @<m>{\epsilon_e} are summarized below. 
 In all cases, thewavelength along the line is given by where @<m>{\lambda_0} is the wavelength in free space.
//texequation{
\begin{equation*}
\lambda
=
\frac{\lambda_0}{\sqrt{\epsilon_e}}.
\tag{4.70}
\end{equation*}
//}
//image[fig_4_7][Some commonly-used types of transmission lines. Since there are multiple ways to drive the coplanar guide, the most common source connection is explicitly shown. All of the dielectric materials are assumed to be nonmagnetic for our purposes.][scale=0.8]{
//}

==== Coaxial Lines
The field structure and parameters for coaxial transmission lines are discussed in
 most introductory texts on electromagnetics, e.g., [19]. 
 Referring to Figure 4.7(a), the characteristic impedance is
//texequation{
\begin{equation*}
Z_c
=
\frac{1}{2\pi}
\sqrt{\frac{\mu_0}{\epsilon_0 \epsilon_r}}
\ln(b/a).
\tag{4.71}
\end{equation*}
//}
 In this case 𝜖𝑒 = 𝜖𝑟 since the coax is uniformly filled with dielectric.

==== Microstrip Lines
RF and microwave components such as filters, power dividers, and quadrature hybrids
 are often made using metallized substrates with transmission line patterns etched
 on one side using a process similar to that used to make printed circuit boards.
 Figure 4.7(b) describes the geometry and key dimensions. 
 Unlike coax, simple and accurate analytical expressions are not available, 
 and instead expressions are obtained by fitting approximate analytical expressions 
 to the results of numerical modeling. 
 In the common case of RF and microwave components described above, 
 the conductor thickness @<m>{t} is much less than either the conductor width @<m>{w} 
 or the substrate thickness @<m>{h} and can be neglected. 
 Under this assumption, models for the key parameters have been discussed 
 by a number of authors [20–24]. 
 Here we quote the expressions for characteristic impedance given by Pozar [21]:
//texequation{
\begin{equation*}
Z_c
=
\begin{cases}
\displaystyle
\frac{60}{\sqrt{\epsilon_e}}
\ln\left(
\frac{8h}{w}
+
\frac{w}{4h}
\right)
& \text{for } w/h \leq 1
\\[12pt]
\displaystyle
\frac{120\pi}
{\sqrt{\epsilon_e}
\left[
w/h + 1.393 + 0.667\ln(w/h + 1.444)
\right]}
& \text{for } w/h \geq 1
\end{cases}\
\end{equation*}
\tag{4.72}
//}
 and the effective relative dielectric constant is approximated by
//texequation{
\begin{equation*}
\epsilon_e
=
\frac{\epsilon_r + 1}{2}
+
\frac{\epsilon_r - 1}{2}
\frac{1}{\sqrt{1 + 12h/w}}.
\tag{4.73}
\end{equation*}
//}

==== Coplanar Waveguide
Microstrip lines require metallization on both sides of the circuit substrate. 
 A geometry that is more compatible with nanofabrication techniques is the coplanar waveguide
 (CPW) shown in Figure 4.7(c). 
 For example, the bottom dielectric could be a silicon substrate, 
 and the top dielectric could be an oxide layer grown on the silicon. 
 The planar metallization pattern could then be formed using conventional photolithographic techniques 
 (similar to those used to make printed circuit boards). 
 In such a case the substrate thickness is so much larger than the oxide thickness 
 and the lateral dimensions of the transmission line that it can be considered infinite. 
 Consequently only the thickness of the top dielectric layer 
 (oxide in our silicon example) affects the transmission line properties.

We have shown the usual excitation connections for this transmission line, 
 since three conductors permit excitation to be applied in multiple ways.

When the conductor thickness @<m>{t} can be neglected,
 analytical expressions for the characteristic impedance can be obtained using a mathematical technique 
 called conformal mapping [25-27]. 
 The result is
//texequation{
\begin{equation*}
Z_c
=
4 \epsilon_0 \epsilon_e
\frac{K(k_0)}{K(k_0')}.
\tag{4.74}
\end{equation*}
//}
 Here @<m>{K} is the complete elliptic integral of the first kind, and its arguments are defined as 
//texequation{
\begin{equation*}
k_0
=
\frac{w}{w+2s},
\qquad
k_0'
=
\sqrt{1-k_0^2}.
\tag{4.75}
\end{equation*}
//}
 The effective relative permittivity is
//texequation{
\begin{equation*}
\epsilon_e
=
1
+
\frac{1}{2}(\epsilon_{r1}-1)
+
q(\epsilon_{r2}-\epsilon_{r1}).
\tag{4.76}
\end{equation*}
//}
 where
//texequation{
\begin{equation*}
q
=
\frac{1}{2}
\frac{K(k)\,K(k_0')}
{K(k')\,K(k_0)}.
\tag{4.77}
\end{equation*}
//}
 and
//texequation{
\begin{equation*}
k
=
\frac{
\sinh\left(\frac{\pi w}{4h}\right)
}{
\sinh\left(\frac{\pi (w+2s)}{4h}\right)
},
\qquad
k'
=
\sqrt{1-k^2}.
\tag{4.78}
\end{equation*}
//}

As an example, [26] analyzed a coplanar waveguide with @<m>{w} = 10 𝜇m, 
 @<m>{s} = 6.6 𝜇m,@<m>{h} = 550 nm, and @<m>{t} = 200 nm. 
 The line was fabricated on a high-resistivity silicon wafer with thickness 500 𝜇. 
 The substrate thickness is clearly much larger than the other transmission line dimensions, 
 justifying the assumption of infinite thickness. 
 In contrast, the conductor thickness in this case is not negligible, 
 and the authors found that for their geometry, 
 available analytic expressions such as Eq. (4.76) for the effective 
 relative permittivity were inaccurate. 
 For such geometries, the effective permittivity must be calculated numerically 
 using tools such as the finite element method.

The impedance expression (4.74) is based on the magnetic contributions to the inductance per unit length, i.e.,
 the conventional inductance resulting from magnetic flux linking the current. 
 However, in Chapter 7, we will see that in superconducting currents there is a kinetic contribution 
 to the inductance associated with the inertia of charge carriers as well. 
 This kinetic contribution to the inductance of superconducting coplanar waveguides has been considered 
 by [26, 28], and is negligible when the temperature is significantly below the superconducting transition 
 temperature, as is the case in quantum computing. 
 Consequently, this kinetic contribution can be neglected in our cases of interest.

== @<m>{S} Parameters
Because voltages and currents vary with position,
 it is often more convenient to characterize devices and circuits in a language that is more consistent 
 with the notions of incident, reflected, and transmitted waves. 
 Consider the two-port circuit shown in Figure 4.8. 
 The incoming wave voltage amplitudes are denoted by a “+” superscript,
 and the outgoingwave voltage amplitudes are denoted by a “−” superscript. 
 For a linear circuit, the incoming and outgoing waves are related by
//texequation{
\begin{equation}
\begin{bmatrix}
V_1^{-} \\
V_2^{-}
\end{bmatrix}
=
\begin{bmatrix}
S_{11} & S_{12} \\
S_{21} & S_{22}
\end{bmatrix}
\begin{bmatrix}
V_1^{+} \\
V_2^{+}
\end{bmatrix},
\tag{4.79}
\end{equation}
//}
 or
//texequation{
\begin{equation}
V^{-} = SV^{+}
\tag{4.80}
\end{equation}
//}
 The elements of the 𝑆 matrix are called 𝑆 parameters and are defined as follows:
//texequation{
\begin{equation}
\begin{aligned}
S_{11} &= \left. \frac{V_1^{-}}{V_1^{+}} \right|_{V_2^{+}=0}
= \text{reflection coefficient from port 1 } (\Gamma_1), \\
S_{21} &= \left. \frac{V_2^{-}}{V_1^{+}} \right|_{V_2^{+}=0}
= \text{transmission coefficient from port 1 to port 2}, \\
S_{12} &= \left. \frac{V_1^{-}}{V_2^{+}} \right|_{V_1^{+}=0}
= \text{transmission coefficient from port 2 to port 1}, \\
S_{22} &= \left. \frac{V_2^{-}}{V_2^{+}} \right|_{V_1^{+}=0}
= \text{reflection coefficient from port 2 } (\Gamma_2).
\end{aligned}
\tag{4.81}
\end{equation}
//}
//image[fig_4_8][Incoming and outgoing wave amplitudes used in the definitions of S parameters.][scale=0.8]{
//}

=== Lossless Condition
For a lossless network, all the power that goes in must come out.
 For example, assuming all ports have the characteristic impedance @<m>{Z_{𝑐'\}}, we require
//texequation{
\begin{equation}
\frac{|V_1^{+}|^2}{2Z_c}
+
\frac{|V_2^{+}|^2}{2Z_c}
-
\frac{|V_1^{-}|^2}{2Z_c}
-
\frac{|V_2^{-}|^2}{2Z_c}
= 0.
\tag{4.82}
\end{equation}
//}
 Equivalently, this can be expressed
//texequation{
\begin{equation}
(V^{+})^{\dagger}V^{+}
-
(V^{-})^{\dagger}V^{-}
= 0,
\tag{4.83}
\end{equation}
//}
where the superscript @<m>{\dagger} represents the transpose complex conjugate.
 We can use the @<m>{S} matrix to express this entirely in terms of the incident wave voltage amplitudes:
//texequation{
\begin{equation}
\begin{aligned}
(V^{+})^{\dagger}V^{+}
-
(SV^{+})^{\dagger}SV^{+}
&= 0, \\
(V^{+})^{\dagger}V^{+}
-
(V^{+})^{\dagger}S^{\dagger}SV^{+}
&= 0, \\
(V^{+})^{\dagger}(I - S^{\dagger}S)V^{+}
&= 0.
\end{aligned}
\tag{4.84}
\end{equation}
//}
 From this we conclude that
//texequation{
\begin{equation}
S^{\dagger}S = I
\tag{4.85}
\end{equation}
//}
 and the @<m>{S} matrix of a lossless network must be unitary.

=== Reciprocity
A microwave network is said to be reciprocal if the transmission from port @<m>{i} to port @<m>{j} is
 the same as from @<m>{j} to @<m>{i}. In other words, 
 a reciprocal network will work the same if the input and output are interchanged. 
 In terms of @<m>{S} parameters we require @<m>{S_{ij\} = S_{ji\}} . 
 We conclude that the @<m>{S} matrix of a reciprocal network is symmetric.

== Transmission (ABCD) Matrices
In many cases, microwave networks consist of a cascade of 2-port components.
 It is therefore useful to define a @<m>{2 \times 2} transmission matrix 
 that can be used to obtain the voltage at the output port from that of the input port. 
 Transmission through a cascade of 2-ports can then be obtained by multiplying the transmission matrices. 
 These matrices are also called ABCD matrices owing to the common symbols used for the matrix elements.

Unlike 𝑆 parameters, the ABCD matrix for a 2-port is defined in terms of the total
 voltages and currents as defined in Figure 4.9.Note that the sign convention for current
 is directed in on the input, and out on the output. 
 This ensures consistent definitions when multiple two-ports are cascaded. 
 In terms of these quantities, the ABCD matrixis defined as
//texequation{
\begin{equation}
\begin{bmatrix}
V_1 \\
I_1
\end{bmatrix}
=
\begin{bmatrix}
A & B \\
C & D
\end{bmatrix}
\begin{bmatrix}
V_2 \\
I_2
\end{bmatrix}.
\tag{4.86}
\end{equation}
//}
//image[fig_4_9][Definition of voltages and currents for the ABCD transmission matrix.][scale=0.8]{
//}
 From this equation we obtain the definitions of the matrix components as
//texequation{
\begin{equation}
\begin{aligned}
A \quad &= \left. \frac{V_1}{V_2} \right|{I_2=0}, \\
B \quad &= \left. \frac{V_1}{I_2} \right|{V_2=0}, \\
C \quad &= \left. \frac{I_1}{V_2} \right|{I_2=0}, \\
D \quad &= \left. \frac{I_1}{I_2} \right|{V_2=0}.
\end{aligned}
\tag{4.87–4.90}
\end{equation}
//}
 As an example of the construction of an ABCD matrix, 
 consider the length of lossless transmission line shown in Figure 4.10. 
 The total voltage and current as functions of position along the line are given by
//texequation{
\begin{equation}
V(z) = V_0^{+}\left(e^{-j\beta z} + \Gamma e^{j\beta z}\right),
\tag{4.91}
\end{equation}
//}
//texequation{
\begin{equation}
I(z) = \frac{V_0^{+}}{Z_c}\left(e^{-j\beta z} - \Gamma e^{j\beta z}\right),
\tag{4.92}
\end{equation}
//}
 where @<m>{\Gamma} is the reflection coefficient at port 2, 
 and @<m>{V_0^{+\}} is the amplitude of the wave incident wave from the left.

The voltages and currents at the ports are given by
//texequation{
\begin{equation}
V_1 = V(-l) = V_0^{+}\left(e^{j\beta l} + \Gamma e^{-j\beta l}\right),
\tag{4.93}
\end{equation}
//}
//texequation{
\begin{equation}
I_1 = I(-l) = \frac{V_0^{+}}{Z_c}\left(e^{j\beta l} - \Gamma e^{-j\beta l}\right),
\tag{4.94}
\end{equation}
//}
//texequation{
\begin{equation}
V_2 = V(0) = V_0^{+}(1 + \Gamma),
\tag{4.95}
\end{equation}
//}
//texequation{
\begin{equation}
I_2 = I(0) = \frac{V_0^{+}}{Z_c}(1 - \Gamma).
\tag{4.96}
\end{equation}
//}
//image[fig_4_10][Definitions for constructing the ABCD matrix of a section of transmission line.][scale=0.8]{
//}
 Referring to Eqs. (4.87) and (4.89), we see that @<m>{A} and @<m>{C} are calculated with @<m>{I_2 = 0}. 
 This implies an open circuit at port 2, for which @<m>{\Gamma = +1} from Eq. (4.96). 
 This gives
//texequation{
\begin{equation}
\begin{aligned}
A
&= \left. \frac{V_1}{V_2} \right|_{I_2=0} \
&= \frac{e^{j\beta l} + e^{-j\beta l}}{2} \
&= \cos \beta l,
\end{aligned}
\tag{4.97}
\end{equation}
//}
 and
//texequation{
\begin{equation}
\begin{aligned}
C
&= \left. \frac{I_1}{V_2} \right|_{I_2=0} \
&= \frac{e^{j\beta l} - e^{-j\beta l}}{2Z_c} \\
&= j\frac{1}{Z_c}\sin \beta l \
&= jY_c \sin \beta l.
\end{aligned}
\tag{4.98}
\end{equation}
//}
 Similarly, the definitions of @<m>{B} and @<m>{D} from Eqs. (4.88) and (4.90) require @<m>{V_2 = 0},
 implying a short circuit at port 2, and @<m>{\Gamma = -1} from Eq. (4.95). It follows that
//texequation{
\begin{equation}
\begin{aligned}
B
&= \left. \frac{V_1}{I_2} \right|_{V_2=0} \
&= \frac{e^{j\beta l} - e^{-j\beta l}}{2/Z_c} \\
&= jZ_c \sin \beta l,
\end{aligned}
\tag{4.99}
\end{equation}
//}
 and
//texequation{
\begin{equation}
\begin{aligned}
D
&= \left. \frac{I_1}{I_2} \right|_{V_2=0} \
&= \frac{e^{j\beta l} + e^{-j\beta l}}{2} \\
&= \cos \beta l.
\end{aligned}
\tag{4.100}
\end{equation}
//}
 The ABCD matrix for the section of transmission line is therefore
//texequation{
\begin{equation}
\begin{bmatrix}
A & B \\
C & D
=
\end{bmatrix}
\begin{bmatrix}
\cos \beta l & jZ_c \sin \beta l \\
jY_c \sin \beta l & \cos \beta l
\end{bmatrix}.
\tag{4.101}
\end{equation}
//}
 The ABCD matrices for several useful 2-ports are given in Table 4.1.
//imgtable[tblimg_4_1][Useful ABCD matrices.][scale=0.8]{
//}

As mentioned above, the input voltages and currents of a series of cascaded two-ports
 are obtained by simply multiplying the ABCD matrices of the two-ports. 
 For example, the voltage and current at the input to two cascaded two-ports can be obtained in terms
 of the voltage and current at the output as follows:
//texequation{
\begin{equation}
\begin{bmatrix}
V_1 \\
I_1
\end{bmatrix}
=
\begin{bmatrix}
A_1 & B_1 \\
C_1 & D_1
\end{bmatrix}
\begin{bmatrix}
A_2 & B_2 \\
C_2 & D_2
\end{bmatrix}
\begin{bmatrix}
V_3 \\
I_3
\end{bmatrix}.
\tag{4.102}
\end{equation}
//}

Although ABCD matrices are convenient for analyzing cascaded networks,
 ultimately one is often interested in the @<m>{S} parameters of the equivalent 2-port. 
 As an example, consider @<m>{S_{11\}} for the general case of a terminated transmission line of
 impedance @<m>{Z_1} connected to port 1, and a terminated transmission line of impedance
 @<m>{Z_2} connected to port 2 [29]. 
 The voltage at port 2 will be related to the current as @<m>{I_2 = V_2/Z_2}:
//texequation{
\begin{equation}
\begin{aligned}
\begin{bmatrix}
V_1 \\
I_1
\end{bmatrix}
&=
\begin{bmatrix}
A & B \\
C & D
\end{bmatrix}
\begin{bmatrix}
1 \\
1/Z_2
\end{bmatrix}
V_2 \
&=
\begin{bmatrix}
A + B/Z_2 \\
C + D/Z_2
\end{bmatrix}
V_2.
\end{aligned}
\tag{4.103}
\end{equation}
//}
 The impedance @<m>{Z_{in1\}} looking into port 1 is then
//texequation{
\begin{equation}
Z_{\mathrm{in1}}
=
\frac{V_1}{I_1}
=
\frac{A + B/Z_2}{C + D/Z_2}.
\tag{4.104}
\end{equation}
//}
 Since @<m>{S_{11\}} is equal to the reflection coefficient @<m>{\Gamma}, we have
//texequation{
\begin{equation}
S_{11}
=
\Gamma
=
\frac{Z_{\mathrm{in1}} - Z_1}{Z_{\mathrm{in1}} + Z_1}.
\tag{4.105}
\end{equation}
//}
 Substituting (4.104) into (4.105) and simplifying gives
//texequation{
\begin{equation}
S_{11}
=
\frac{
A + B/Z_2 - CZ_1 - DZ_1/Z_2
}{
A + B/Z_2 + CZ_1 + DZ_1/Z_2
}.
\tag{4.106}
\end{equation}
//}

To obtain @<m>{S_{21\}}, we now return to the top equation in (4.103):
//texequation{
\begin{equation}
V_1
=
(1 + S_{11})V_1^{+}
=
(A + B/Z_2)V_2.
\tag{4.107}
\end{equation}
//}
 Solving for @<m>{V_2/V_1^+} , substituting in for @<m>{S_{11\}}, and simplifying gives
//texequation{
\begin{equation}
S_{21}
=
\frac{
2
}{
A + B/Z_2 + CZ_1 + DZ_1/Z_2
}.
\tag{4.108}
\end{equation}
//}
 To obtain @<m>{S_{22\}}, we first invert the ABCD matrix to obtain
//texequation{
\begin{equation}
\begin{bmatrix}
V_2 \\
I_2
\end{bmatrix}
=
\frac{1}{AD - BC}
\begin{bmatrix}
D & -B \\
-C & A
\end{bmatrix}
\begin{bmatrix}
V_1 \\
I_1
\end{bmatrix}.
\tag{4.109}
\end{equation}
//}
 However, referring to Figure 4.9, @<m>{I_1} is pointing into the network and @<m>{I_2} is pointing out
 of the network. 
 To consider @<m>{S_{22\}} we need to reverse these directions, so we introduce 
 @<m>{I'_1 = -I_1} and @<m>{I'_2 = -I_2}, with @<m>{Z_{in2\} = V_2/I'_2} and @<m>{Z_1 = V_1/I'_1}. 
 The inverted ABCD matrix equation then becomes
//texequation{
\begin{equation}
\begin{aligned}
\begin{bmatrix}
V_2 \\
-I_2'
\end{bmatrix}
=
\frac{1}{AD - BC}
\begin{bmatrix}
D & -B \\
-C & A
\end{bmatrix}
\begin{bmatrix}
1 \\
-1/Z_1
\end{bmatrix}
V_1 \
=
\frac{1}{AD - BC}
\begin{bmatrix}
D + B/Z_1 \\
-C - A/Z_1
\end{bmatrix}
V_1 .
\end{aligned}
\tag{4.110}
\end{equation}
//}
 The impedance @<m>{Z_{\mathrm{in2\}\}} looking into port 2 is then
//texequation{
\begin{equation}
Z_{\mathrm{in2}} \
=
\frac{V_2}{I_2'}
=
\frac{D + B/Z_1}{C + A/Z_1}.
\tag{4.111}
\end{equation}
//}
 Similar to before, @<m>{S_{22\}} is given by
//texequation{
\begin{equation}
\begin{aligned}
S_{22}
=
\frac{Z_{\mathrm{in2}} - Z_2}{Z_{\mathrm{in2}} + Z_2} \
=
\frac{
D + B/Z_1 - CZ_2 - AZ_2/Z_1
}{
D + B/Z_1 + CZ_2 + AZ_2/Z_1
}.
\end{aligned}
\tag{4.112}
\end{equation}
//}

Finally, to obtain @<m>{S_{12\}}, we return to the top equation in (4.110):
//texequation{
\begin{equation}
V_2^{+}(1 + S_{22})
=
\frac{D + B/Z_1}{AD - BC}V_1 .
\tag{4.113}
\end{equation}
//}
 Solving for @<m>{V_1/V_2^+} , substituting for @<m>{S_{22\}}, and simplifying leads to
//texequation{
\begin{equation}
S_{12}
=
\frac{
2(AD - BC)(Z_1/Z_2)
}{
A + B/Z_2 + CZ_1 + DZ_1/Z_2
}.
\tag{4.114}
\end{equation}
//}

In the most common case of @<m>{Z_1 = Z_2 \equiv Z_c}, the equations relating @<m>{S} parameters to
 the ABCD matrix reduce to the following:
//texequation{
\begin{equation}
S_{11}
=
\frac{
A + B/Z_c - CZ_c - D
}{
A + B/Z_c + CZ_c + D
},
\tag{4.115}
\end{equation}
//}
//texequation{
\begin{equation}
S_{22}
=
\frac{
-A + B/Z_c - CZ_c + D
}{
A + B/Z_c + CZ_c + D
},
\tag{4.116}
\end{equation}
//}
 and for reciprocal networks,
//texequation{
\begin{equation}
S_{12}
=
S_{21}
=
\frac{
2
}{
A + B/Z_c + CZ_c + D
}.
\tag{4.117}
\end{equation}
//}
 In obtaining this expression, we see that we must require @<m>{AD - BC = 1} for reciprocal
networks with the same impedance at each port.

== Attenuators
Attenuators are reciprocal components that are used to reduce the amplitude of a signal on a transmission line.
 Ideally, we would like to do this without creating reflections along the line. 
 This means, of course, that we want both ports to be matched to the characteristic impedance of the line. 
 It follows from reciprocity that the attenuator has the same behavior regardless of which port is used 
 as the input and which is used as the output.
//image[fig_4_11][Circuit for an attenuator.][scale=0.8]{
//}

One way to realize such a component is with a symmetric lumped-element circuit as shown in Figure 4.11.
 The equivalent ABCD matrix for this circuit can be obtained by multiplying three matrices: 
 the first for a series impedance of @<m>{R_1}, the second for a shunt impedance of @<m>{R_2}, 
 and the third for another series impedance of @<m>{R_1}. 
 Referring to Table 4.1 we have:
//texequation{
\begin{equation}
\begin{bmatrix}
1 & R_1 \\
0 & 1
\end{bmatrix}
\begin{bmatrix}
1 & 0 \\
1/R_2 & 1
\end{bmatrix}
\begin{bmatrix}
1 & R_1 \\
0 & 1
\end{bmatrix}
=
\begin{bmatrix}
1 + R_1/R_2 &
R_1(1 + +R_1/R_2) \\
1/R_2 &
1 + R_1/R_2
\end{bmatrix}.
\tag{4.118}
\end{equation}
//}
 First, let us consider the conditions that provide matched ports. 
 In terms of @<m>{S} parameters, this implies @<m>{S_{11\} = S_{22\} = 0}. 
 From Eq. (4.115), this implies @<m>{A + B/Z_c = C/Z_c + D}, or @<m>{B/Z_c = C/Z_c} since @<m>{A = D} (see Eq. (4.118)).
 We have then,
//texequation{
\begin{equation}
\begin{aligned}
\frac{1}{Z_c}
\left(
R_1 + \frac{R_1^2}{R_2}
\right)
=
\frac{Z_c}{R_2}, \\
\frac{R_2}{Z_c}
\left(
\frac{R_1}{R_2} + \frac{R_1^2}{R_2^2}
\right)
=
\frac{Z_c}{R_2}.
\end{aligned}
\tag{4.119}
\end{equation}
//}
 or
//texequation{
\begin{equation}
R_2
=
\frac{Z_c}{\sqrt{r + r^2}},
\tag{4.120}
\end{equation}
//}
 where @<m>{r = R_1/R_2}.

Next we want to choose the resistor ratio @<m>{r = R_1/R_2} so that the desired attenuation is obtained.
 If @<m>{G} is the desired power gain, then we want to require @<m>{S_{12\} = S_{21\} = \sqrt{G\}}.
 Since @<m>{A = D} and @<m>{B/Z_c = C/Z_c}, @<m>{S_{12\}} from Eq. (4.117) can be written
//texequation{
\begin{equation}
\begin{aligned}
S_{12}
=
\frac{2}{2(A + CZ_c)} \\
=
\frac{2}{2(1 + r + Z_c/R_2)} \\
=
\frac{1}{1 + r + \sqrt{r + r^2}} .
\end{aligned}
\tag{4.121}
\end{equation}
//}
 With@<m>{\sqrt{G\} = S_{12\}}, this can be written
//texequation{
\begin{equation}
\sqrt{r + r^2}
=
\frac{1}{\sqrt{G}}
-1 - r.
\tag{4.122}
\end{equation}
//}
 Squaring both sides and solving for @<m>{r} gives
//texequation{
\begin{equation}
r
=
\frac{\sqrt{G}}{2}
\left(
\frac{1}{\sqrt{G}} - 1
\right)^2 .
\tag{4.123}
\end{equation}
//}
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
 Note that since @<m>{|Γ| ≤ 1}, the minus sign ensures that the return loss is always positive.
 There is a common temptation to want to make the “loss” negative 
 (i.e., to say, “the return loss is -10 dB”), but this would result in a double negative; 
 a negative loss would be the same as gain!

In practice, it is commonly assumed that the match is acceptable if at least 90% of the
 incident power is absorbed by the load. 
 This corresponds to a return loss of 10 dB.

=== Standing Wave Ratio (SWR)
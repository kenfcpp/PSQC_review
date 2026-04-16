= 単一量子ビットゲートの物理学

== 量子コンピュータの要件
　ご想像のとおり、量子ビットを表現して操作する何らかの方法があることは、量子コンピューターの基本要件です。 
 主要な要件をすべて検討する中で、DiVincenzo [3] は次の 5 つの基本要件を特定しました。

 1. 十分に特性化された量子ビットを備えたスケーラブルな物理システム
 2. 量子ビットの状態を @<m>{|000...\rangle} などの単純な基準状態に初期化する機能
 3. 関連するデコヒーレンス時間が長く、ゲート動作時間よりもはるかに長い
 4. 量子ゲートの「ユニバーサル」セット
 5. 量子ビット固有の測定機能
　この章では、これらの要件のうち 2 つの側面について説明しますが、DiVincenzo の順序とは少し異なります。
 * 量子ビットの任意の操作が回転として解釈できることがわかります。 
 そこで、要件 4 のサブトピックであるローテーションについて説明することから始めます。
 * 次に、要件 1 のサブトピックである量子ビットを表現するために必要な 2 状態システムの物理学を検討します。
 エンタングルメント、測定、初期化、およびデコヒーレンス時間の議論は後続の章で説明します。

== 単一量子ビットゲート

=== 回転
　前の章では、いくつかのタイプのゲートを説明し、それらを 2 つの @<m>{x} 2 行列で説明しました。 
 ゲートが量子ビットに対して何を行うかをより一般的に理解するには、回転を理解する必要があります。
 次に、これまで説明してきたゲートを特定の回転とみなすことができることが分かります。

　古典的な物理学や力学の授業で回転に遭遇したことがあるかもしれません。 
 そこで、3 空間における古典的なベクトルの回転について簡単に説明することから始めます。 
 しかし、量子力学では物理状態は状態ベクトルで表現され、 
 したがって、これらの状態ベクトルがどのように回転されるかを理解する必要があります。

　単一量子ビットの場合、状態ベクトルは2 @<m>{x} 1行列（またはベクトル）で表されます。
 量子力学の他の分野では、このような状態ベクトルはスピンと呼ばれます。
 この用語の由来は、磁場中のスピンを持つ粒子が最も単純な2状態系の一つであるという事実にあります。
 そして、この文脈では、2 @<m>{x} 1 の状態ベクトルがスピン状態を表します。
 しかし、これらの概念は、あらゆる2状態量子力学系に有効です。

==== クラシックローテーション
　z軸を中心とした古典的なベクトルの反時計回り (CCW) の角度 𝜃 の回転
 方向は図 2.1 に示されています。
 図の幾何学構造から、長さ @<m>{\gamma} のベクトルが 
 @<m>{x} 軸は (@<m>{\gamma}cos 𝜃, @<m>{\gamma}sin 𝜃, 0) に回転します。.
 同様の構築に従って、@<m>{y} 軸に沿った長さ @<m>{\gamma} のベクトルは次のように回転します。
 (−@<m>{\gamma} sin 𝜃, @<m>{\gamma} cos 𝜃, 0)。 
 一般的には次のように書くことができます
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

 正方行列を、z 軸を中心とした回転の回転行列と呼びます。
//texequation{
R_z^c(\theta) =
\begin{bmatrix}
\cos\theta & -\sin\theta & 0 \\
\sin\theta & \cos\theta & 0 \\
0 & 0 & 1
\end{bmatrix} \tag{2.2}
//}

 ここで、上付き文字 c は古典物理学の回転を示します。

　同様の手順に従って、@<m>{x} 軸と @<m>{y} 軸を中心とした回転は次のようになります。 
 次の行列で説明されます。
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

//image[fig_2_1][長さ r のベクトルの z 軸を中心とした CCW の回転。][scale=01.0]{
//}

==== 量子力学的状態ベクトルの回転
量子力学では、ベクトルは、ベクトル演算子の期待値 @<fn>{fn-1} を取得することによって得られます。 
 特定の量子状態。
 たとえば、電子のスピンの方向を決定するには、次のようにします。 
 電子の状態ベクトルを使用してスピン演算子の期待値を取得します。
 測定されたスピンベクトルを回転するには、 
 得られたベクトルが次のように電子状態ベクトルを回転させる必要があります。 
 期待を受け取ると、期待どおりに回転します。
 上で述べたように、電子スピンを例として参照すると役立つ場合があります。 
 しかし、私たちの議論はあらゆる 2 状態量子力学的システムに当てはまります。
//footnote[fn-1][期待値は、オペレーターの測定の平均結果です。]

この説明では、一般的なベクトル演算子 @<m>{A} を考慮します。
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
 let us consider an infinitesimal rotation @<m>{\epsilon} about the axis @<m>{\hat{n}}
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
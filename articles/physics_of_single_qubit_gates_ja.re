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
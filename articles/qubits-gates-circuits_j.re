= 量子ビット、ゲート、回路

== ビットと量子ビット
　最もよく知られているデジタル システムは、2 進数、つまり「ビット」に基づいています。
各ビットは「1」または「0」のいずれかの値を取ることができ、任意のデータをこのようなバイナリ表現で表すことができます。
さらに、任意の論理演算をビットを使用して実装できます。
これらのよく知られたシステムは、古典物理学の日常的な法則に支配されているため、「古典的」システムと呼ぶことにします。

量子コンピューティングは、いくつかの重要な点で従来のコンピューティングとは異なります。 
量子コンピューティングにおける情報の基本単位は、@<i>{qubit：量子ビット} (「キュービット」と発音) です。
量子ビットの機能と動作はビットとはまったく異なります。量子コンピューティングの研究の出発点として、まずは主な違いを指摘し、議論することから始めます。

=== 空間回路と時間回路
　単純な古典的論理回路は、図 1.1(a) に示す NOT ゲートで表されます。
NOT ゲートは「0」を「1」に変換し、その逆も行います。 
この回路図では、水平方向は空間を表しています。
つまり、回路の入力と出力は回路内の異なるポイントから物理的にアクセス可能であり、同時に測定できます。

　NOTゲートの量子バージョンは、図1.1(b)に示すXゲートです。
量子ビットの場合、「0」と「1」の状態は通常、それぞれ@<m>{|0\nolinebreak\rangle}、@<m>{|1\nolinebreak\rangle}と表記されます。
この表記の意味については後のセクションで詳しく説明しますが、今のところは、これらを2つの状態のラベルとして考えてください。
この場合、水平方向は時間を表します。
つまり、回路の入力と出力は、@<i>{X} ゲート操作を実行した後の同じ量子ビットの状態を表します。
言い換えれば、古典論理の通常の構造とは異なり、量子ゲートは@<i>{単一}の量子ビットまたは量子ビットのセットに対して実行する操作を表します。
出力は実質的に入力を上書きし、ゲートが適用されるたびに量子ビットの状態が変化します。

=== 重ね合わせ
　古典的なビットは「0」か「1」のいずれかでなければなりません。
対照的に、量子ビットは一部が「0」で一部が「1」である@<i>{重ね合わせ状態}になることもできます。

//image[fig_1_1][古典的 NOT ゲートと量子 NOT ゲートの解釈][scale=0.8]{
//}

量子ビットが「1」または「0」の状態にある場合、その量子ビットは@<i>{基底状態}にあると言います。@<fn>{fn-1}

//footnote[fn-1][より正確には、|0> と |1> は「計算基底」または「標準基底」状態として知られています。本章では、標準基底に限定して議論し、単に基底状態と呼ぶことにします。]

　基底状態の場合、古典ゲートの状態を測定するのと同じように、状態を変更せずに量子ビットの状態を何度でも測定できます。
重ね合わせ状態も、測定すると、混合によって決まる確率で「0」または「1」のいずれかが生成されます。
この場合、測定を行うという行為によって重ね合わせ状態が構成基底状態の 1 つに「崩壊」し、重ね合わせ状態に保存された情報は失われます。
例えば、@<m>{|\psi\nolinebreak\rangle}が重ね合わせ状態を表している場合、いつでも量子ビットを測定すると状態が
@<m>{|0\nolinebreak\rangle}または@<m>{|1\nolinebreak\rangle}>に崩壊し、重ね合わせ状態の情報が破壊されます。
この時点から、量子ビットを繰り返し測定すると、古典的なビットと同様に、常に最初の測定と同じ結果が得られます。

　数学的には重ね合わせ状態は次のように書ける。
//texequation{
\ket{\psi} = \alpha \ket{0} + \beta \ket{1}
\tag{1.1}
//}
ここで、@<m>{\alpha} と @<m>{\beta} は複素定数です。

　前述のように、このような重ね合わせ状態が測定された場合、常に @<m>{|0\nolinebreak\rangle}または @<m>{|1\nolinebreak\rangle}
 のいずれかが示されますが、それぞれの確率は @<m>{\alpha} と @<m>{\beta} によって決定されます。
具体的には、2つの可能な結果を測定する確率は次のように与えられる。
//texequation{
\Pr(0) = |\alpha|^2, \quad \Pr(1) = |\beta|^2\tag{1.2}
//}
これらが測定の唯一の可能な結果である場合、確率の合計は1になるか、
//texequation{
|\alpha|^2 + |\beta|^2 = 1\tag{1.3}
//}
この重ね合わせ状態を表現する能力は、量子コンピューティングの強力な秘密の一つです。
量子ビットは、ある意味では複数の可能性を並行して探索できるのです。

=== 複製作成禁止
　古典的な論理回路では、いつでもビットの状態を測定し、その状態のコピーを必要なだけ作成できます。
量子ビットが基底状態のいずれかにあることが分かっている場合は、これを実行することもできます。
前述のように、@<m>{|0\nolinebreak\rangle} または @<m>{|1\nolinebreak\rangle} 状態を乱すことなく測定でき、
 必要に応じて
 @<m>{|0\nolinebreak\rangle} または @<m>{|1\nolinebreak\rangle} のコピーをいくつでも作成できます。

　しかし、任意の量子状態の正確で独立したコピーを作成することは@<i>{不可能}であることが判明しました。
これは@<i>{複製禁止定理}として知られています。
1.7節で証明を示しますが、今はこれが量子プログラマーにもたらす課題について考えてみましょう。

　たとえば、回路を 1 回実行しただけでは、@<m>{\alpha} または @<m>{\beta} の推定値を得ることはできません。
複製により、回路を実行し、その結果を多数コピーし、それぞれのコピーを測定して、
 @<m>{|0\nolinebreak\rangle} または @<m>{|1\nolinebreak\rangle} を測定する確率から @<m>{|\alpha|^2} と
 @<m>{|\beta|^2} を推定することができます。
複製がなければ、結果を一度しか測定できません。
多くの測定値を得るには、同じ計算を何度も実行し、（うまくいけば！）同じ結果を何度も生成する必要があります。

　ブレークポイントやデバッグ、エラー回復のために状態のコピーを作成することはできません。
また、計算の過程で単一の状態に異なる演算子を適用することも困難です。
従来のプログラマーは状態のコピー機能を当然のことと考えていますが、この制限には調整が必要です。

　量子状態をエンタングルメント（1.1.5節）を用いてコピーすることは可能であることが判明していますが、
コピー対象となる状態を破壊することによってのみ可能です。
これはコピーではなく状態の@<i>{転送}を表し、@<i>{テレポーテーション}と呼ばれます。

=== 可逆性
従来の NOT ゲートは可逆的です。
つまり、2 つの NOT ゲートを直列に接続すると、ビットが元の状態に戻ります。
しかし、複数の入力を持つ古典的な論理ゲートの場合は状況が異なります。
例として、図1.2に示すNANDゲートを考えてみましょう。
入力ビットと出力ビットを一意に決定することはできません。 
このため、従来の多入力ロジックは@<i>{不可逆}@<fn>{fn-2} です。

//footnote[fn-2][注: 可逆的な「保守的論理」ゲートと呼ばれる古典的な多入力論理ゲートが存在する。現在まで広く使用されていないが、原理的には電力を消費せずに計算できるという利点がある(1)]

　対照的に、量子ゲートは可逆的です。
その結果、出力が入力を上書きしたとしても、適切な逆操作を適用することで一連のゲート操作の効果を逆転させることが
できるため、入力は失われません。

=== エンタングルメント
　重ね合わせ状態にある量子ビットの測定結果の確率（正確な結果ではない）しか計算できないという事実は、
古典力学には類似例のない現象、すなわち@<i>{エンタングルメント}（量子もつれ）を可能にします。 
2つの量子ビットがエンタングルメント状態にある場合、
どちらの量子ビットの測定結果もその確率によってしか予測できないにもかかわらず、状態は相関しています。
たとえば、2 つの量子ビットがエンタングルされている場合、量子ビットの 1 つを測定すると、
孤立した量子ビットの場合と同様に、重ね合わせ状態によって決まる確率で結果が得られます。
しかし、測定によって 1 つの量子ビットの状態が崩壊すると、エンタングルメントにより、
2 番目の量子ビットを測定した場合に何が得られるか正確にわかるようになります。
//image[fig_1_2][NAND回路図][scale=0.5]{
//}
　これは、2 枚のコインを同時に投げて、常に同じ結果、つまり両方とも表か両方とも裏が出ることに少し似ています。
あるいは、常に反対の、つまり一方が表でもう一方が裏になるようにします。
測定を行う前は、両方の量子ビットの状態はまだ決定されていません。
しかし、測定によって一方の量子ビットの状態が崩壊すると、もう一方の量子ビットはどういうわけか瞬時に結果を「知る」ことになります。
これは、量子ビットがどれだけ離れているかに関係なく当てはまります。
例えば、2つの量子ビットをエンタングルメントし、1つをニューヨークに、もう1つを東京に送り、
 両方を同時に測定できるように事前に準備しておくとします。
光速の信号が量子ビット間を移動するのに十分な時間がなかったとしても、測定結果は相関していることがわかります。
アインシュタインは、これを「不気味な遠隔作用」と呼んだ。

　もし最初の測定結果を制御できれば、特殊相対性原理に反して光速よりも速く通信できるようになると思われます。
 しかし、最初の測定結果を制御できないという事実は、このメカニズムを使用して実際に情報を送信できないことを意味します。@<fn>{fn-3}. 

//footnote[fn-3][エンタングルメントは、超高密度符号化と呼ばれるプロトコルを使用することで、通信チャネルの容量を増やすために使用できます。]

したがって、相対性理論が破られていないことを知って、私たちは安心していられるのです。

　@<i>{重ね合わせ}と@<i>{もつれ}の現象が量子コンピューティングに並外れて強力な機能を与えていることがわかります。

== 単一量子ビット状態
　量子ビットの状態には 2 つの要素があるため、状態を状態ベクトルと呼ばれる 2 次元ベクトルとして表すことができます。
基底状態は次のように書けます。
#@# //indepimage[eq_1_4]
The basis states can be written as
//texequation{
\ket{0} =
\begin{bmatrix}
1\\
0
\end{bmatrix},
\quad
\ket{1} =
\begin{bmatrix}
0\\
1
\end{bmatrix}
\tag{1.4}
//}
したがって、一般的な重ね合わせ状態は、基底状態の加重和として表現できます。
//texequation{
\ket{\psi}
=
\alpha\ket{0}+\beta\ket{1}
=
\alpha
\begin{bmatrix}
1\\
0
\end{bmatrix}
+
\beta
\begin{bmatrix}
0\\
1
\end{bmatrix}
=
\begin{bmatrix}
\alpha\\
\beta
\end{bmatrix}
\tag{1.5}
//}
@<m>{|\psi\rangle} という表記は「ケット」と呼ばれます。
ケットの転置複素共役e@<fn>{fn-4}は⟨@<m>{\langle\psi|}と表記され、「ブラ」と呼ばれる。

//footnote[fn-4][行列またはベクトルの転置は、行と列を入れ替えることで形成されます。列ベクトルの転置は行ベクトルになります。転置複素共役は、ベクトルまたは行列の転置を取り、各要素の複素共役を取ることで形成されます。]
#@# //indepimage[eq_1_6]
//texequation{
\ket{\psi}^\dagger
=
\bra{\psi}
=
\begin{bmatrix}
\alpha^* & \beta^*
\end{bmatrix}
\tag{1.6}
//}

ここで、上付き文字の†は転置複素共役、つまりエルミート共役、あるいは随伴とも呼ばれる複素共役を示します。
「ブラ」と「ケット」という用語は、掛け合わせて「ブラケット」になるまでは奇妙に思えるかもしれません。
例えば、
#@# //indepimage[eq_1_7]
//texequation{
\braket{\psi}{\psi}
=
\begin{bmatrix}
\alpha^\ast & \beta^\ast
\end{bmatrix}
\begin{bmatrix}
\alpha\\
\beta
\end{bmatrix}
=
\alpha^\ast \alpha + \beta^\ast \beta
\tag{1.7}
//}
#@# //indepimage[eq_1_8]
//texequation{
\alpha^\ast \alpha + \beta^\ast \beta
=
|\alpha|^2 + |\beta|^2
\tag{1.8}
//}

(bra-ket として表記する場合は、中央に縦棒が 1 本だけ使用されることに注意してください。)
ブラケット演算子（ブラとケットの乗算）は「内積」とも呼ばれます。
(1.8)を参照すると、状態ベクトルとそれ自身との内積は、測定において各基底状態が得られる確率の合計を与えることがわかります。
すべての起こり得る結果の確率の合計は 1 に等しくなければならないため、状態ベクトルは 1 の長さに適切に正規化される必要があることがわかります。

== 測定とボルンの法則
　重ね合わせ状態の特定の要素を測定する確率は、その係数の二乗の大きさで決まることをすでに述べました。
測定行為には、情報を抽出するために量子ビットと相互作用する装置が必要です。
量子力学の法則によれば、装置は一連の基本状態に関連した部分的な情報しか提供できない。
ここでは、測定は常に標準基底状態 @<m>{|1\rangle} と @<m>{|1\rangle} に関して行われるものと仮定します。
これはほとんどの量子コンピューティング システムに当てはまります。
しかし、測定装置が異なる基底状態のセットに関連付けられる可能性はあります。
（測定については、後の章でより詳細に説明します。）

　量子ビットが測定されると、(a) 状態は測定に関連付けられた基本状態の 1 つに変更され、(b) 測定装置によって結果の状態が通知されます。
一般に、測定時に状態@<m>{|\psi\rangle}が基底状態@<m>{|a\rangle}に見つかる確率は次のように与えられる。
#@# //indepimage[eq_1_9]
//texequation{
Pr[\ket{a}] = |\langle \psi | a \rangle|^2 \tag{1.9}
//}

これをボーン則といいます。
例えば、上の状態@<m>{|\psi\rangle}を測定した結果が@<m>{|0\rangle}、@<m>{|1\rangle}となる確率は次のように与えられます。
#@# //indepimage[eq_1_10]
//texequation{
Pr[|0\rangle] = |\langle \psi | 0 \rangle|^2 = |\alpha|^2 |\langle 0 | 0 \rangle|^2 = |\alpha|^2\tag{1.10}
//}
#@# //indepimage[eq_1_11]
//texequation{
Pr[|1\rangle] = |\langle \psi | 1 \rangle|^2 = |\beta|^2 |\langle 1 | 1 \rangle|^2 = |\beta|^2\tag{1.11}
//}

前にも記したとおりです。

== ユニタリ演算と単一量子ビットゲート
　ある量子状態から別の量子状態への変換をゲートと呼びます。
単一量子ビットゲートの効果は、@<m>{\alpha}と@<m>{\beta}を新しい混合物@<m>{\alpha'}と@<m>{\beta'}に変換することです。
#@# //indepimage[eq_1_12]
//texequation{
\begin{aligned}
\alpha' &= U_{11} \alpha + U_{12} \beta \\
\beta'  &= U_{21} \alpha + U_{22} \beta
\end{aligned}\tag{1.12}
//}

これは行列方程式として表すことができます。
#@# //indepimage[eq_1_13]
//texequation{
\begin{bmatrix}
\alpha' \\
 \beta'
\end{bmatrix}
=
\begin{bmatrix}
U_{11} & U_{12} \\
U_{21} & U_{22}]
\end{bmatrix}
\begin{bmatrix}
\alpha \\
\beta
\end{bmatrix}\tag{1.13}
//}
#@# //indepimage[eq_1_14]
//texequation{
|\psi'\rangle \equiv U |\psi\rangle\tag{1.14}
//}

状態ベクトルの長さは常に1でなければならないので、ベクトルの長さを保存する行列 @<m>{U} のみを使用できます。
つまり、@<m>{\langle \psi' | \psi' \rangle = \langle \psi | \psi \rangle = 1}となります。
これにより、行列 @<m>{U} に非常に重要な制約が課せられます。
#@# //indepimage[eq_1_15]
//texequation{
\langle \psi' | \psi' \rangle = \langle \psi | U^\dagger U | \psi \rangle = 1\tag{1.15}
//}

次の観察を使用します。
#@# //indepimage[eq_1_16]
//texequation{
\langle \psi' | = (U |\psi\rangle)^\dagger = \langle \psi | U^\dagger.\tag{1.16}
//}

@<m>{\langle \psi | 以来\psi \rangle = 1}なので、次のように結論付けられます。
#@# //indepimage[eq_1_17]
//texequation{
U^\dagger U = I\tag{1.17}
//}

ここで@<m>{I}は単位行列である
#@# //indepimage[eq_1_18]
//texequation{
I = \begin{bmatrix}
1 & 0 \\
0 & 1
\end{bmatrix}\tag{1.18}
//}

この要件を満たす行列はユニタリ行列と呼ばれます。
これらの行列は、基底状態の混合を変更することによって量子ビットに対して操作を実行するものとして考えることができます。
したがって、行列 @<m>{U} はユニタリ演算子とも呼ばれます。

　単位行列@<m>{I}は最も単純な「ゲート」とみなされ、状態ベクトルは変更されません。 
古典的には、NOT ゲートは唯一の非自明な単一ビット ゲートです。
対照的に、非自明な単一量子ビット量子ゲートは数多く存在します（技術的には、2×2ユニタリ行列の数は無制限です）。
最も一般的な非自明な単一量子ビット ゲートは、次のように定義される Pauli-X (𝑋)、Pauli-Y (𝑌)、Pauli-Z (𝑍)、
および Hadamard (𝐻) ゲートです。

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

これらのゲートが何をするのかを理解するために、𝑋ゲートを「基底」状態|0⟩に適用することを検討してください。

//indepimage[eq_1_23]
#@# \begin{equation}
#@# X |0\rangle = \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} 1 \\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\ 1 \end{bmatrix} = |1\rangle\tag{1.23}
#@# \end{equation}

同様に、

//indepimage[eq_1_24]
#@# \begin{equation}
#@# X |1\rangle = \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} 0 \\ 1 \end{bmatrix} = \begin{bmatrix} 1 \\ 0 \end{bmatrix} = |0\rangle\tag{1.24}
#@# \end{equation}

𝑋ゲートは「ビット反転」ゲートであり、|0⟩を|1⟩に変換し、その逆も行うことがわかります。
これは、古典的なNOTゲートの類似物です。𝑌、𝑍、𝐻ゲートを適用して次の結果を検証する必要があります。

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

さらに、これらの行列のそれぞれが独自のエルミート共役であることに注目することも興味深いことです。
したがって、これら 4 つのゲートには、2 回適用すると単位行列が生成されるという特性があります。

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

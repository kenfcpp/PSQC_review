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
対照的に、非自明な単一量子ビット量子ゲートは数多く存在します（技術的には、@<m>{2\,\times\,2}ユニタリ行列の数は無制限です）。
最も一般的な非自明な単一量子ビット ゲートは、次のように定義される Pauli-X (@<m>{X})、Pauli-Y (@<m>{Y})、Pauli-Z (@<m>{Z})、
および Hadamard (@<m>{H}) ゲートです。
#@# //indepimage[eq_1_19]
//texequation{
X = \begin{bmatrix}
0 & 1 \\
1 & 0
\end{bmatrix}\tag{1.19}
//}
#@# //indepimage[eq_1_20]
//texequation{
Y = \begin{bmatrix}
0 & -i \\
i & 0
\end{bmatrix}\tag{1.20}
//}
#@# //indepimage[eq_1_21]
//texequation{
Z = \begin{bmatrix}
1 & 0 \\
0 & -1
\end{bmatrix}\tag{1.21}
//}
#@# //indepimage[eq_1_22]
//texequation{
H = \frac{1}{\sqrt{2}} \begin{bmatrix} 1 & 1 \\ 1 & -1 \end{bmatrix}\tag{1.22}
//}
これらのゲートが何をするのかを理解するために、@<m>{X}ゲートを「基底」状態@<m>{|0\rangle}に適用することを検討してください。
#@# //indepimage[eq_1_23]
//texequation{
X |0\rangle = \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} 1 \\ 0 \end{bmatrix} = \begin{bmatrix} 0 \\ 1 \end{bmatrix} = |1\rangle\tag{1.23}
//}
同様に、
#@# //indepimage[eq_1_24]
//texequation{
X |1\rangle = \begin{bmatrix} 0 & 1 \\ 1 & 0 \end{bmatrix} \begin{bmatrix} 0 \\ 1 \end{bmatrix} = \begin{bmatrix} 1 \\ 0 \end{bmatrix} = |0\rangle\tag{1.24}
//}
@<m>{X}ゲートは「ビット反転」ゲートであり、@<m>{|0\rangle}を@<m>{|1\rangle}に変換し、その逆も行うことがわかります。
これは、古典的なNOTゲートの類似物です。@<m>{Y}、@<m>{Z}、@<m>{H}ゲートを適用して次の結果を検証する必要があります。
#@# //indepimage[eq_1_25]
//texequation{
Y |0\rangle = i |1\rangle, \quad Y |1\rangle = -i |0\rangle\tag{1.25}
//}
#@# //indepimage[eq_1_26]
//texequation{
Z |0\rangle = |0\rangle, \quad Z |1\rangle = -|1\rangle\tag{1.26}
//}
#@# //indepimage[eq_1_27]
//texequation{
H |0\rangle = \frac{1}{\sqrt{2}} (|0\rangle + |1\rangle), \quad
H |1\rangle = \frac{1}{\sqrt{2}} (|0\rangle - |1\rangle)\tag{1.27}
//}
さらに、これらの行列のそれぞれが独自のエルミート共役であることに注目することも興味深いことです。
したがって、これら 4 つのゲートには、2 回適用すると単位行列が生成されるという特性があります。
//texequation{
X^2 = Y^2 = Z^2 = H^2 = I\tag{1.28}
//}
@<m>{X}、@<m>{Y}、および @<m>{Z} ゲートは @<m>{|0\rangle} の間で変換されることに注意してください。
 @<m>{|1\rangle} の状態、 
 アダマール ゲートは実際に重ね合わせ状態を作成するため、次のことが証明されます。
 特に役に立ちます。 
 @<m>{H} を基底状態に適用した結果の状態には、それぞれ独自の名前が付けられます。
#@# //indepimage[eq_1_29]
//texequation{
|+\rangle \equiv H |0\rangle = \frac{|0\rangle + |1\rangle}{\sqrt{2}}\tag{1.29}
//}
#@# //indepimage[eq_1_30]
//texequation{
|-\rangle \equiv H |1\rangle = \frac{|0\rangle - |1\rangle}{\sqrt{2}}\tag{1.30}
//}
行列の乗算により、複数のゲートを量子ビットに順次適用できます。
#@# //indepimage[eq_1_31]
//texequation{
XYH\,|0\rangle\tag{1.31}
//}
この式は、基底状態から開始し、次にアダマール ゲートを適用し、その後に 
 Pauli-@<m>{Y}、次に Pauli-@<m>{Z}。
 このプロセスは概念的に右から左に進むことに注意してください。 
 この計算は、図 1.3 に示すような量子回路図で表すことができます。 
 プロセスは回路図上で左から右に移動することに注意してください。
//image[fig_1_3][Circuit representation of Eq. (1.31). In a quantum circuit diagram, the operation goes from left to right, while the matrix expression is shown going from right to left. The final box is a measurement in the standard basis, resulting in a classical bit.][scale=0.5]{
//}
 左側の基底状態から始めて、アダマール ゲート、Pauli-@<m>{Y} ゲート、Pauli-@<m>{X} を適用します。

　最後に、量子計算を実行した後、通常は各量子ビットを測定します。
 測定の記号は、図 1.3 の最後の要素として示されています。 
 このアクションにより、最終状態が基本状態の 1 つに折りたたまれます。 
 測定の結果は、古典的なレジスタに保存される古典的なビットです。 
 「量子細線」は実線、「古典細線」は二重線で示します。 
 量子ワイヤは、状態が変化しないまま維持される時間間隔を単純に表します。

== 2量子ビットゲート
入力として複数の量子ビットを持つゲートを持つことも可能です。 
 ただし、古典的なマルチビット ゲートとは異なり、量子ゲートが可逆であるという事実には、 
 入力量子ビットと同じ数の出力量子ビットが存在する必要があります。 
 このセクションでは、いくつかの一般的な 2 量子ビット ゲートについて説明します。

=== 2量子ビット状態
2 つの量子ビットを備えたシステムを検討するとき、各量子ビットを互いに独立して考慮するだけではありません。 
 代わりに、これは独自の基底状態セットを持つ 2 量子ビット システムを形成します。 
 各量子ビットの状態がわかっている場合、結合された 2 量子ビットの状態は次のように記述されます。 
 2 つの状態ベクトルのテンソル積。次のように定義されます。
#@# //indepimage[eq_1_32]
//texequation{
\begin{bmatrix}
a \\
b
\end{bmatrix}
\otimes
\begin{bmatrix}
c \\
d
\end{bmatrix}
 =
\begin{bmatrix}
a \begin{bmatrix} c \\ d \end{bmatrix} \\
b \begin{bmatrix} c \\ d \end{bmatrix}
\end{bmatrix}
 =
\begin{bmatrix}
ac \\
ad \\
bc \\
bd
\end{bmatrix}\tag{1.32}
//}

標準基底を使用すると、2 量子ビット システムの基底状態は @<m>{|0\rangle} の組み合わせによって定義されます。
 and @<m>{|1\rangle} states:
#@# //indepimage[eq_1_33]
//texequation{
|00\rangle = |0\rangle \otimes |0\rangle =
\begin{bmatrix}
1 \times
\begin{bmatrix}
1 \\
0
\end{bmatrix} \\
0 \times
\begin{bmatrix}
1 \\
0
\end{bmatrix} \\
0 \times
\begin{bmatrix}
1 \\
0
\end{bmatrix}
\end{bmatrix}
 =
\begin{bmatrix}
1 \\
0 \\
0 \\
0
\end{bmatrix}\tag{1.33}
//}
#@# //indepimage[eq_1_34]
//texequation{
|01\rangle = |0\rangle \otimes |1\rangle =
\begin{bmatrix}
1 \times \begin{bmatrix} 0 \\ 1 \end{bmatrix} \\
0 \times \begin{bmatrix} 0 \\ 1 \end{bmatrix}
\end{bmatrix}
 =
\begin{bmatrix}
0 \\
1 \\
0 \\
0
\end{bmatrix}\tag{1.34}
//}
#@# //indepimage[eq_1_35]
//texequation{
|10\rangle = |1\rangle \otimes |0\rangle =
\begin{bmatrix}
0 \times \begin{bmatrix} 1 \\ 0 \end{bmatrix} \\
1 \times \begin{bmatrix} 1 \\ 0 \end{bmatrix}
\end{bmatrix}
=
\begin{bmatrix}
0 \\
0 \\
1 \\
0
\end{bmatrix}\tag{1.35}
//}
#@# //indepimage[eq_1_36]
//texequation{
|11\rangle = |1\rangle \otimes |1\rangle =
\begin{bmatrix}
0 \times \begin{bmatrix} 0 \\ 1 \end{bmatrix} \\
1 \times \begin{bmatrix} 0 \\ 1 \end{bmatrix}
\end{bmatrix}
=
\begin{bmatrix}
0 \\
0 \\
0 \\
1
\end{bmatrix}\tag{1.36}
//}
任意の 2 量子ビット状態は、基底状態の線形結合として記述できます。
#@# //indepimage[eq_1_37]
//texequation{
|\psi\rangle = \alpha_{00} |00\rangle + \alpha_{01} |01\rangle + \alpha_{10} |10\rangle + \alpha_{11} |11\rangle\tag{1.37}
//}
2 量子ビットの状態ベクトルも正規化されます。
#@# //indepimage[eq_1_38]
//texequation{
|\alpha_{00}|^2 + |\alpha_{01}|^2 + |\alpha_{10}|^2 + |\alpha_{11}|^2 = 1\tag{1.38}
//}
後で説明するように、すべての 2 量子ビット状態は式 (1) の形式で書くことができます。 (1.37)、
 すべての 2 量子ビット状態を 1 量子ビット状態のテンソル積として書き込むことができるわけではありません。
 これは @<m>{n} 量子ビットを持つシステムに一般化でき、@<m>{2^n} コンポーネントを持つ状態ベクトルが必要になります。 
 @<m>{2^n} 複素係数を使用します。

=== 2量子ビットゲートの行列表現
Just as single qubit gates can be represented by @<m>{2\,\times\,2} matrices, an @<m>{n}-qubit gate can be represented bya 
 @<m>{2^n \,\times\, 2^n} matrix. 
 Consequently two-qubit gates require the construction of @<m>{4\,\times\,4} unitary matrices. 
 Given two single-qubit operators @<m>{A} and @<m>{B}, the tensor product is defined as:
#@# //indepimage[eq_1_39]
//texequation{
A \otimes B \equiv
\begin{bmatrix}
A_{11} B & A_{12} B \\
A_{21} B & A_{22} B
\end{bmatrix}
=
\begin{bmatrix}
A_{11}
\begin{bmatrix}
B_{11} & B_{12} \\
B_{21} & B_{22}
\end{bmatrix}
& 
A_{12}
\begin{bmatrix}
B_{11} & B_{12} \\
B_{21} & B_{22}
\end{bmatrix}
\\[10pt]
A_{21}
\begin{bmatrix}
B_{11} & B_{12} \\
B_{21} & B_{22}
\end{bmatrix}
&
A_{22}
\begin{bmatrix}
B_{11} & B_{12} \\
B_{21} & B_{22}
\end{bmatrix}
\end{bmatrix}\tag{1.39}
//}
which creates a @<m>{4\,\times\,4} matrix.

Suppose we wanted to construct a two-qubit circuit starting in the state @<m>{|10\rangle} with an
 X gate applied to the left qubit, and a Y gate applied to the other. 
 Mathematically this would be written
#@# //indepimage[eq_1_40]
//texequation{
X \otimes Y|10\rangle .\tag{1.40}
//}

Referring to (1.24) we see that the X gate will simply flip the left qubit, and referring to (1.25)
 we see that the Y gate will flip the right qubit and add the coefficient @<m>{i}. 
 We conclude that
#@# //indepimage[eq_1_41]
//texequation{
X \otimes Y|10\rangle=i|01\rangle.\tag{1.41}
//}
To see how this would be implemented using the matrix representation, we first construct the @<m>{X \otimes Y } matrix:
#@# //indepimage[eq_1_42]
//texequation{
X \otimes Y=\left[\begin{array}{cc}
0\left[\begin{array}{cc}
0 & -i \\
i & 0
\end{array}\right] & 1\left[\begin{array}{cc}
0 & -i \\
i & 0
\end{array}\right] \\
1\left[\begin{array}{cc}
0 & -i \\
i & 0
\end{array}\right] & 0\left[\begin{array}{cc}
0 & -i \\
i & 0
\end{array}\right]
\end{array}\right]=\left[\begin{array}{cccc}
0 & 0 & 0 & -i \\
0 & 0 & i & 0 \\
0 & -i & 0 & 0 \\
i & 0 & 0 & 0
\end{array}\right] .\tag{1.42}
//}
Completing the calculation gives the expected result:
#@# //indepimage[eq_1_43]
//texequation{
X \otimes Y|10\rangle=\left[\begin{array}{cccc}
0 & 0 & 0 & -i \\
0 & 0 & i & 0 \\
0 & -i & 0 & 0 \\
i & 0 & 0 & 0
\end{array}\right]\left[\begin{array}{l}
0 \\
0 \\
1 \\
0
\end{array}\right]=i\left[\begin{array}{l}
0 \\
1 \\
0 \\
0
\end{array}\right]=i|01\rangle .\tag{1.43}
//}
A particularly interesting two-qubit circuit is formed by applying a Hadamard gate to each qubit 
 in the ground state:@<m>{H \otimes H \ }@<m>{|00\rangle}. 
 Let us first compute @<m>{H \otimes H } :
#@# //indepimage[eq_1_44]
//texequation{
H \otimes H=\frac{1}{2}\left[\begin{array}{cc}
1\left[\begin{array}{cc}
1 & 1 \\
1 & -1
\end{array}\right] & 1\left[\begin{array}{cc}
1 & 1 \\
1 & -1
\end{array}\right] \\
1\left[\begin{array}{cc}
1 & 1 \\
1 & -1
\end{array}\right] & -1\left[\begin{array}{cc}
1 & 1 \\
1 & -1
\end{array}\right]
\end{array}\right]=\frac{1}{2}\left[\begin{array}{cccc}
1 & 1 & 1 & 1 \\
1 & -1 & 1 & -1 \\
1 & 1 & -1 & -1 \\
1 & -1 & -1 & 1
\end{array}\right].\tag{1.44}
//}
Completing the calculation gives:
#@# //indepimage[eq_1_45]
//texequation{
H \otimes H|00\rangle=\frac{1}{2}\left[\begin{array}{cccc}
1 & 1 & 1 & 1 \\
1 & -1 & 1 & -1 \\
1 & 1 & -1 & -1 \\
1 & -1 & -1 & 1
\end{array}\right]\left[\begin{array}{l}
1 \\
0 \\
0 \\
0
\end{array}\right]=\frac{1}{2}\left[\begin{array}{l}
1 \\
1 \\
1 \\
1
\end{array}\right].\tag{1.45}
//}
Note that the resulting state vector can be decomposed into a sum of all of the two-qubit basis states:
#@# //indepimage[eq_1_46]
//texequation{
\frac{1}{2}\left[\begin{array}{l}
1 \\
1 \\
1 \\
1
\end{array}\right]=\frac{1}{2}\left[\begin{array}{l}
1 \\
0 \\
0 \\
0
\end{array}\right]+\frac{1}{2}\left[\begin{array}{l}
0 \\
1 \\
0 \\
0
\end{array}\right]+\frac{1}{2}\left[\begin{array}{l}
0 \\
0 \\
1 \\
0
\end{array}\right]+\frac{1}{2}\left[\begin{array}{l}
0 \\
0 \\
0 \\
1
\end{array}\right].\tag{1.46}
//}
or alternatively
#@# //indepimage[eq_1_47]
//texequation{
H \otimes H|00\rangle=\frac{1}{2}(|00\rangle+|01\rangle+|10\rangle+|11\rangle).\tag{1.47}
//}
We see that application of Hadamard gates to each qubit creates an equally weighted superposition of 
 all possible basis states. 
 This is often a very useful starting point for a quantum calculation.

Although the matrix representation can be helpful in understanding the operations,
 calculations can often be done more compactly once the effect of the gates are understood.
 For example, we could write @<m>{H \otimes H \ }@<m>{|00\rangle} = @<m>{H \otimes H \ }@<m>{|0\rangle \otimes |0\rangle}, 
 apply the Hadamard gates to each qubit, and simplify:
#@# //indepimage[eq_1_48]
//texequation{
\begin{aligned}
\otimes H\, |00\rangle &= H\,|0\rangle \otimes H\,|0\rangle \notag \\
&= \left( \frac{|0\rangle + |1\rangle}{\sqrt{2}} \right) \otimes \left( \frac{|0\rangle + |1\rangle}{\sqrt{2}} \right) \notag \\
&= \frac{1}{2} \left( |00\rangle + |01\rangle + |10\rangle + |11\rangle \right)
\end{aligned}\tag{1.48}
//}
We conclude this section with a comment on notation. 
 A more compact notation is often used for situations where the same operator is applied across multiple qubits; i.e.,
 @<m>{H \otimes H } is alternatively written @<m>{H ^ \otimes\ ^2 },@<m>{H \otimes H \otimes H = H ^ \otimes\ ^3 } , etc.

=== Controlled-NOT
The gates that we have considered so far involve operations that are independently applied to separate 
 qubits—there is no qubit-qubit interaction. 
 If we are to entangle two qubits, then we need classes of gates where the operation on one qubit depends
 on the state of another. 
 One of the most important such gates is the controlled-NOT,or CNOT gate. 
 For this gate, one of the input qubits is the “control,” and the other is the “target.” 
 If the control qubit is zero, then nothing is done to the target qubit, but if the control qubit is one, 
 then the target qubit is flipped. 
 For example, if the right qubit in our notation is the control and the left qubit is the target, 
 then the CNOT gate transforms the basis states as follows:
#@# //indepimage[eq_1_49]
//texequation{
\begin{aligned}
U_{\text{CN}}\,|00\rangle &= |00\rangle \notag\\
U_{\text{CN}}\,|01\rangle &= |11\rangle \notag\\
U_{\text{CN}}\,|10\rangle &= |10\rangle \notag\\
U_{\text{CN}}\,|11\rangle &= |01\rangle
\end{aligned}\tag{1.49}
//}
The effect of a CNOT can be compactly represented by @<m>{U}@<sub>{CN}@<m>{|t\rangle|c\rangle} = @<m>{|c \oplus t\rangle |c\rangle},
 where @<m>{\oplus} represents 
 exclusive-OR or modulo-2 addition (e.g., 0+1=1, but 1+1=0). 
 The matrix representation of the CNOT gate is
#@# //indepimage[eq_1_50]
//texequation{
\begin{aligned}
U_{\text{CN}} =
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 0 & 0 & 1 \\
0 & 0 & 1 & 0 \\
0 & 1 & 0 & 0
\end{bmatrix} 
\end{aligned}\tag{1.50}
//}
and the circuit symbol is shown in Figure 1.4.

It isworth noting at this point thatwe are putting the least-significant qubit at the top of a circuit diagram, 
 and on the right on the state labels used with kets. 
 This labels states with the natural binary order. 
//image[fig_1_4][Symbol for a CNOT gate, and its effect on basis states.][scale=0.5]{
//}

However, there are different conventions in use, and this can be a point of confusion. 
 Some authors put the top-most qubit in a circuit diagram on the left when they label kets. 
 In this alternate notation,  @<m>{U'}@<sub>{CN}@<m>{|c\rangle|t\rangle}
 = @<m>{|c\rangle|c \oplus t\rangle } so that
#@# //indepimage[eq_1_51]
//texequation{
\begin{aligned}
U'_{\text{CN}}\,|00\rangle &= |00\rangle \notag\\
U'_{\text{CN}}\,|01\rangle &= |01\rangle \notag\\
U'_{\text{CN}}\,|10\rangle &= |11\rangle \notag\\
U'_{\text{CN}}\,|11\rangle &= |10\rangle
\end{aligned}\tag{1.51}
//}
The matrix representation of the CNOT gate in this alternate convention is
#@# //indepimage[eq_1_52]
//texequation{
\begin{aligned}
U'_{\text{CN}} =
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 0 & 1 \\
0 & 0 & 1 & 0
\end{bmatrix}
\end{aligned}\tag{1.52}
//}
We will consistently use the first convention, with the least-significant qubit (top-most on a circuit diagram)
 on the right when writing state labels.

== Bell State
Consider the circuit shown in Figure 1.5. The circuit can be described mathematically as 
 @<m>{U}@<sub>{CN}@<m>{(I \otimes H)|00\rangle}. 
 Here the expression @<m>{I \otimes H } simply means a Hadamard gate is applied to the right qubit, 
 and the identity matrix applied to the left qubit (which leaves the left qubit unchanged). 
 Completing the calculation gives
#@# //indepimage[eq_1_53]
//texequation{
\begin{aligned}
U_{\text{CN}} \left( I \otimes H \right) |00\rangle
= U_{\text{CN}} \left( |0\rangle \otimes \frac{|0\rangle + |1\rangle}{\sqrt{2}} \right)
\end{aligned}\tag{1.53}
//}
#@# //indepimage[eq_1_54]
//texequation{
\begin{aligned}
= \frac{1}{\sqrt{2}}\, U_{\text{CN}} \left( |00\rangle + |01\rangle \right)
\end{aligned}\tag{1.54}
//}
#@# //indepimage[eq_1_55]
//texequation{
\begin{aligned}
= \frac{1}{\sqrt{2}} \left( |00\rangle + |11\rangle \right)
\end{aligned}\tag{1.55}
//}
Note that there is no way to factor this state into (qubit 1 state) @<m>{\otimes} (qubit 0 state). 
 This is known as a Bell State, and it is an example of an entangled state, as described in Section 1.1.5.

1If we measure the state of one of the qubits in (1.55), then we will obtain either a zero or a one 
 with equal probability, as we would expect. 
 The unusual behavior happens when we measure the second qubit: if we measure @<m>{|0\rangle} on the first qubit,
 then we know the state has collapsed to @<m>{|00\rangle}, so a measurement of the second qubit will also yield
 @<m>{|0\rangle}. Similarly, if the first measurement yields @<m>{|1\rangle}, then the state must have collapsed to @<m>{|11\rangle},
 so a measurement of the second qubit will also yield @<m>{|1\rangle}. 
//image[fig_1_5][Circuit for creating an entangled state known as a Bell State. When the two qubits are measured, they will either both be 0, or they will both be 1.][scale=0.7]{
//}
//image[fig_1_6][Result of executing the circuit 1024 times on a quantum simulator, compared with executing the circuit 1024 times on a real IBM quantum computer.][scale=0.7]{
//}
 The measurements are correlated, no matter how far apart the physical qubits might be.

We simulated the Bell circuit using IBM’s Qiskit [2], and also executed the circuit on real IBM Quantum hardware. 
 A histogram illustrating the results of simulating the circuit 1024 times 
 (each execution is referred to as a “shot”) is shown in Figure 1.6.
 From (1.55), we see that the probability amplitudes of the states @<m>{|00\rangle} 
 and @<m>{|11\rangle} are both equal to @<m>{1/\sqrt{2\}}.
 Since the probability of measuring a state is the absolute magnitude squared of the amplitude, 
 the probability of measuring each state is 1/2. 
 Consistent with this, the measurements from the 1024 shots are roughly equally divided between the states 
 @<m>{|00\rangle} and @<m>{|11\rangle}, with no other states occurring.

The simulator gives the result expected from an error-free quantum processor. 
 In contrast, the quantum processors available today are noisy and contain errors. 
 As an illustration, Figure 1.6 also shows the result of executing 1024 shots on a real IBM Quantum processor. 
 Although the states @<m>{|00\rangle} and @<m>{|11\rangle} do occur most frequently, 
 the error states @<m>{|01\rangle} and @<m>{|10\rangle} occasionally occur as well. 
 Fortunately there are techniques to reduce and partially mitigate such noise (Chapter 9), 
 and these techniques represent an active area of research.

== No Cloning, Revisited
With a better understanding of quantum states and operations, 
 we are now ready to construct a proof of the no-cloning theorem. 
 The proof relies on the fact that unitary operators are linear; when applied to a sum of states, 
 the operator operates independently on each component:
#@# //indepimage[eq_1_56]
//texequation{
U \left( |\psi\rangle + |\phi\rangle \right) = U |\psi\rangle + U |\phi\rangle\tag{1.56}
//}
Suppose we have an operator @<m>{U_\text{clone\}} that takes two qubits, as shown in Figure 1.7.
 When the second qubit is @<m>{|0\rangle}, it is replaced with an exact copy of the first qubit. 
 The proof will show that such an operator cannot exist, because it is not compatible with the principle of linearity.
//image[fig_1_7][Hypothetical cloning operator, that creates an exact and independent copy of unknown quantum state |𝛼⟩. The text will show that such an operator cannot be implemented.][scale=0.5]{
//}
Further suppose that we have two states:
#@# //indepimage[eq_1_57]
//texequation{
|\alpha\rangle=a_0|0\rangle+a_1|1\rangle \tag{1.57}
//}
#@# //indepimage[eq_1_58]
//texequation{
|\beta\rangle=b_0|0\rangle+b_1|1\rangle\tag{1.58}
//}
By the definition of cloning:
#@# //indepimage[eq_1_59]
//texequation{
\begin{aligned}
& U_{\text {clone }}|\alpha\rangle|0\rangle=|\alpha\rangle|\alpha\rangle=|\alpha \alpha\rangle, \\
& U_{\text {clone }}|\beta\rangle|0\rangle=|\beta\rangle|\beta\rangle=|\beta \beta\rangle 
\end{aligned}.\tag{1.59}
//}
Now consider a new state @<m>{|\delta\rangle = (|\alpha\rangle + |\beta\rangle)/\sqrt{2\}}. 
By the definition of cloning:
#@# //indepimage[eq_1_60]
//texequation{
\begin{aligned}
U_{\text {clone }}|\delta\rangle|0\rangle & =|\delta\rangle|\delta\rangle \\
& =\frac{|\alpha\rangle+|\beta\rangle}{\sqrt{2}} \otimes \frac{|\alpha\rangle+|\beta\rangle}{\sqrt{2}} \\
& =\frac{1}{2}(|\alpha \alpha\rangle+|\alpha \beta\rangle+|\beta \alpha\rangle+|\beta \beta\rangle)
\end{aligned}\tag{1.60}
//}
However, by the linearity of unitary operators:
#@# //indepimage[eq_1_61]
//texequation{
\begin{aligned}
U_{\text {clone }}|\delta\rangle|0\rangle & =\frac{1}{\sqrt{2}} U_{\text {clone }}(|\alpha\rangle|0\rangle+|\beta\rangle|0\rangle) \\
& =\frac{|\alpha \alpha\rangle+|\beta \beta\rangle}{\sqrt{2}}
\end{aligned}\tag{1.61}
//}
Since Eqs. (1.60) and (1.61) cannot both be true, there is no unitary @<m>{U}@<sub>{clone} 
 that can perform the cloning operation for all states.
 We stated earlier that we can clone a (computational) basis state. 
 This can be done with the CNOT gate, with the first qubit as the control. 
 (With our bottom-to-top ordering, this corresponds to the @<m>{U'}@<sub>{CN} operator from (1.52).) 
 Suppose state @<m>{|\psi\rangle} is either @<m>{|0\rangle} or @<m>{|1\rangle},
 but we don’t know which.
#@# //indepimage[eq_1_62]
//texequation{
U_{\mathrm{CN}}^{\prime}|\psi\rangle|0\rangle=\left\{\begin{array}{l}
U_{\mathrm{CN}}^{\prime}|00\rangle=|00\rangle, \text { if }|\psi\rangle=|0\rangle \\
U_{\mathrm{CN}}^{\prime}|10\rangle=|11\rangle, \text { if }|\psi\rangle=|1\rangle
\end{array}\right\}=|\psi \psi\rangle
\tag{1.62}
//}
If we apply the circuit from Figure 1.5 to an arbitrary state @<m>{|\psi\rangle = \alpha |0\rangle + \beta |1\rangle}, 
 we get a result that looks sort of like cloning, but not quite:
#@# //indepimage[eq_1_63]
//texequation{
U_{\mathrm{CN}}(I \otimes H)|0\rangle|\psi\rangle=\frac{\alpha|00\rangle+\beta|11\rangle}{\sqrt{2}}\tag{1.63}
//}
The result is not cloning because the two qubits are entangled. 
 We did not succeed in creating two independent copies of @<m>{|\psi\rangle}. 
 This is a useful construct, however, and can be extended to create @<m>{n}-qubit states that look like this:
#@# //indepimage[eqe_1_1]
//texequation{
\frac{\alpha\,|0000\ldots\rangle + \beta\,|1111\ldots\rangle}{2^{n/2}}
//}
 These states will be useful for quantum error correction codes (Chapter 10).

== Example: Deutsch’s Problem
We now have enough quantum computing “machinery” to work out a simple example of a quantum algorithm. 
 The example algorithm is admittedly not very useful, 
 but it provides some important insights into how quantum computers can outperform classical computers.

Consider a function that takes a single binary digit as input, and provides a single binary digit as output. 
 There are four possible functions: @<m>{f_1(x) = 0,\; f_2(x) = 1,\; f_3(x) = x,\; f_4(x) = \bar{x\}} 
 Suppose someone gave us an implementation of one of these functions in a black box, 
 and asked us to determine whether @<m>{f(0) = f(1)}, or if @<m>{f(0) \neq f(1)}. 
 Classically, we could do this in two function calls, one with @<m>{x = 0}, and one with @<m>{x = 1}. 
 However, using a quantum algorithm we can answer this question with a single function call! Let’s see how this could be done.

First, suppose that we have the gate @<m>{U} shown in Figure 1.8(a) for implementing the function @<m>{f(x)}. 
 The function is implemented by changing the sign of the state: if @<m>{f(x) = 0} then the sign is unchanged, 
 and if @<m>{f(x) = 1} then the sign of the state is flipped.
 We will return to the question of how to implement this gate shortly, but for now let us assume that the gate is given to us, 
 and our job is to determine if @<m>{f(0) = f(1)} or @<m>{f(0) \neq f(1)}.
 Now consider the circuit shown in Figure 1.8(b). 
 Applying the Hadamard gate to the input @<m>{|0\rangle} gives
#@# //indepimage[eq_1_64]
//texequation{
\psi_1 = \frac{1}{\sqrt{2}} \left( |0\rangle + |1\rangle \right)\tag{1.64}
//}
Note that the Hadamard gate enables us to apply @<m>{U} to both @<m>{|0\rangle} and @<m>{|1\rangle}
 at the same time. 
 This is referred to as quantum parallelism and is one of the secrets behind the power of quantum computing 
 (although there are some key qualifications that make this somewhat less exciting than it would seem at first!).

Continuing with the calculation, we next compute @<m>{\psi_2 = U \psi_1} to obtain
#@# //indepimage[eq_1_65]
//texequation{
\psi_2 = \frac{1}{\sqrt{2}} \left( (-1)^{f(0)} |0\rangle + (-1)^{f(1)} |1\rangle \right)\tag{1.65}
//}
//image[fig_1_8][Conceptual illustration of the Deutsch Problem.][scale=0.5]{
//}
Applying the second Hadamard gate gives the final output:
#@# //indepimage[eq_1_66]
//texequation{
\begin{aligned}
H\psi_2
&= \frac{1}{2} \left[ (-1)^{f(0)} (|0\rangle + |1\rangle) + (-1)^{f(1)} (|0\rangle - |1\rangle) \right]\\
\end{aligned}\tag{1.66}
//}
//texequation{
\begin{aligned}
= \frac{1}{2} \left[ \left( (-1)^{f(0)} + (-1)^{f(1)} \right) |0\rangle + \left( (-1)^{f(0)} - (-1)^{f(1)} \right) |1\rangle \right]
\end{aligned}\tag{1.67}
//}
Examining (1.67), we see that if @<m>{f(0) = f(1)} the second term vanishes and the output is @<m>{|0\rangle}. 
 In contrast, when @<m>{f(0) \neq f(1)}, then the first term vanishes and the output is @<m>{\pm |1\rangle}. 
 Therefore, if we measure the output as @<m>{|0\rangle}, we know that @<m>{f(0) = f(1)}, 
 while if we measure @<m>{|1\rangle}, we know that is not the case. 
 (Our measuring device will ignore the minus sign and show us a result of “1” if the output state is @<m>{- |1\rangle}.)

Arranging for the amplitudes of the correct states to add and others to cancel is an example of quantum interference, 
 another key principle underlying quantum computing.
 So we see that in a single function call, we are able to determine whether or not @<m>{f(x)} is balanced or 
 constant—a feat that would only be possible classically with two function calls!

Now let us turn our attention to how the gate @<m>{U} can be realized. 
 First, we have to confess that the circuit in Figure 1.8 is hiding something: we need another qubit to implement the @<m>{U} gate.

Consider the function @<m>{f(x)=0}. We want a unitary @<m>{Uf} that converts @<m>{|x\rangle} to
 @<m>{|f(x)\rangle}, but this is clearly not reversible. 
 Given an output of @<m>{|0\rangle}, there’s no way to know whether the input is @<m>{|1\rangle} or @<m>{|0\rangle}. 
 To make the function reversible, we need to include both  @<m>{f(x)} and @<m>{x} in the output, 
 so that we can reconstruct the input when reversing the operation.

For two outputs, we need two inputs. 
 We typically use @<m>{|0\rangle} as second input, but to be more general, 
 let’s assume that the second input can be any input @<m>{|y\rangle}. 
 With @<m>{|x\rangle} and @<m>{|y\rangle} as the inputs, the outputs will be
 @<m>{|x\rangle} and @<m>{|y \oplus f(x)\rangle}, where ⊕ is the standard Boolean exclusive-OR (XOR) operation. 
 As shown in Figure 1.9, this function is its own inverse; if we use @<m>{|x\rangle} and 
 @<m>{|y \oplus f(x)\rangle} as the input, 
 we get @<m>{|x\rangle} and @<m>{|y \oplus f(x) \oplus f(x)\rangle} = @<m>{|y\rangle} as the output.

Figure 1.10 shows the four alternative implementations of  @<m>{Uf}, depending on which version of  @<m>{f(x)} we want. 
 From left to right:
 * @<m>{f_1(x) = 0}, do nothing to @<m>{y} equivalent to @<m>{y \oplus 0}.
 * @<m>{f_2(x) = 1}, flip @<m>{y} using a NOT gate, equivalent to @<m>{y \oplus 1}.
 * @<m>{f_3(x) = x}, use a CNOT gate to flip @<m>{y} if @<m>{x} = 1, equivalent to @<m>{y \oplus x}.
 * @<m>{f_4(x) = \bar{x\}}, flip @<m>{x} and then XOR with @<m>{y} using a CNOT gate, equivalent to @<m>{y \oplus \bar{x\}}. 
 We then use another NOT gate to restore @<m>{x} to its original value.

Now, using our @<m>{Uf} circuit, we will compute @<m>{(-1) ^ {f(x)\}|x\rangle} using a technique known as phase kickback. 
 If we set |@<m>{|y\rangle = |-\rangle = \frac{|0\rangle - |1\rangle\}{\sqrt{2\}\}}, 
 then the top output of @<m>{Uf} willremain @<m>{|-\rangle} and the bottom output will be @<m>{|x\rangle}
 if @<m>{f(x)=0} and will be @<m>{-|x\rangle} if @<m>{f(x)=1}.
 Let’s do the math.
//image[fig_1_9][Reversible circuit for calculating f(x).][scale=0.7]{
//}
//image[fig_1_10][Implementations of black-box function Uf for Deutsch’s problem. Top output is |y ⊕ f(x)⟩, and bottom output is |x⟩.][scale=0.7]{
//}
First, consider what happens if we flip @<m>{|-\rangle} using the @<m>{X} gate:
#@# //indepimage[eq_1_68]
//texequation{
\begin{aligned}
X \ket{-}
&= \frac{1}{\sqrt{2}} X(\ket{0} - \ket{1}) \\
&= \frac{1}{\sqrt{2}} (\ket{1} - \ket{0})\\
&= -\ket{-}
\end{aligned} \tag{1.68}
//}
In the cases where @<m>{Uf} flips @<m>{|y\rangle}, we have:
#@# //indepimage[eq_1_69]
//texequation{
\begin{aligned}
U_f \ket{x} \ket{-} = \ket{x} (-\ket{-}) = (-\ket{x}) \ket{-}
\end{aligned}\tag{1.69}
//}
It might seem that we “magically” moved the minus sign from one qubit to the other, but remember that this is really a two-qubit state, 
 not two individual qubits. 
 And -1 is just a constant, so we can associate it with either part of the two-qubit state.

Figure 1.11 shows the under-the-covers implementation of the circuit from Figure 1.8, where the dashed box replaces@<m>{U}.
 We add our ancilla qubit as part of this circuit.
 We typically assume that qubits are initialized in state @<m>{|0\rangle}, 
 so we use @<m>{HX} to create the desired @<m>{|-\rangle} state. 
 Then we have our black-box function, @<m>{Uf}, which has the desired sign-flipping effect on |𝑥⟩. 
 Finally, it is good practice to “uncompute” the ancilla bit, restoring it @<m>{|0\rangle}, 
 so that the qubit can be used elsewhere in a larger circuit.

If the notions of reversible logic and phase kickback seem strange, don’t worry.
 We’ll have a lot more to say about them in Chapters 11 and 12.
//image[fig_1_11][mplementation of Deutsch’s algorithm. The dashed box is equivalent to U in Figure 1.8.][scale=1.0]{
//}

== Key Characteristics of Quantum Computing
The Bell and Deutsch examples have illustrated several important characteristics of quantum computing:

・Results are (usually) statistical: When a classical program is executed, you obtain the same result each time. 
 However, when a quantum circuit is executed, multiple results are possible with probabilities determined by the magnitude 
 squared of the amplitudes of each state. 
 Consequently, in general a circuit must be executed a large number of times, 
 with the results of the computation extracted from a histogram of the measured outcomes.

It is possible, however, for the outcome to be one particular state with probability 1.
 This is the case for Deutsch’s algorithm, for example.
 We know the answer for certain after one execution (assuming the quantum machine is error-free). 
 So it’s not the case that a quantum algorithm must be probabilistic, but the most interesting algorithms tend to be that way.

・Quantum parallelism: Arranging for the input state to be a superposition allows the calculation 
 to consider multiple cases at once.
 However, it is not as easy to capitalize on this as it might sound. As indicated in the previous bullet, 
 even though the output state may contain the complete solution, 
 a single measurement will yield only one state with a probability 
 given by the squared magnitude of the amplitude of the state in the solution of the problem.

・Exponential scaling: The number of cases that can be considered scales as 2@<m>{N}, where @<m>{N} is the number of qubits. 
 Beyond about 50 qubits, a general quantum processor cannot be simulated by a supercomputer; said differently, 
 a processor with of order 50 or more qubits is capable of computations not possible on the best classical computers.
 However, if the quantum program is restricted to certain types of gates, then the operation of the quantum computer 
 can be efficiently simulated by a classical computer.

・Quantum interference: When multiple cases are considered using superposition, 
 the goal of the quantum circuit is to arrange for the amplitudes of correct answer(s) to add constructively, 
 while arranging for the incorrect answer(s) to add destructively.

・Asking the right question: Although the output state of a quantum calculation will generally contain information 
 about many possibilities, making a measurement collapses the state and therefore only gives a single result. 
 In the Deutsch Problem, two classical function calls would not only tell you whether the function was constant or balanced, 
 but it would tell you precisely what the function was. 
 In contrast, the quantum calculation answers the question about whether the function is constant or balanced in one function 
 call (which requires consideration of both cases), but it does not tell you which of the two possible functions it is.

== Quantum Computing Systems
At this point, you may be asking: what kind of physical system exhibits the behavior that we can exploit for quantum computing? 
 Any two-state quantum mechanical system can represent a qubit, and there are several possibilities, 
 such as the spin of an electron, the polarization of a photon, or the energy level of an electron in a charged ion.
 Any of these systems can be used to build a quantum computer, but there are tradeoffs regarding how the qubits 
 can be manufactured and controlled, and how they interact with one another.

In this book, we concentrate on one specific technology for creating qubits and quantum computing systems: 
 superconducting circuits. 
 Unlike many competing technologies, superconducting qubits are macroscopic in size and are based on well-known 
 nanofabrication technologies. 
 They represent the current technology of choice for several companies building quantum computer systems, 
 including IBM, Google, and Rigetti.

A large part of this book, Chapters 2-8, is devoted to a detailed explanation of these devices and how to control them
 to carry out the fundamental operations of a quantum computer, described above. 
 In this section, before diving into the details, we provide a high-level overview of a superconducting quantum computer.

As we will see in Chapter 2, we will need to couple the qubit to a signal whose frequency 
 depends on the energy difference between the @<m>{|0\rangle} and @<m>{|1\rangle} states, i.e., the ground and excited states. 
 In superconducting quantum computers, this energy difference corresponds to a microwave frequency near 5 GHz. 
 Consequently,we must design a microwave system to control and measure superconducting qubit states.

The general features of the microwave system to control and readout superconducting qubits are shown in Figure 1.12. 
 A key feature is that the qubits must be held at a very low temperature, near absolute zero. 
 Consequently the qubits must be located in a cryogenic refrigerator. 
 To understand why this is necessary, we want to make sure that if we put the qubit in the ground state, 
 it stays in the ground state. 
 In other words, we want to make sure that it is unable to absorb enough energy incidentally from its environment 
 to make a transition. 
 A circuit in equilibrium at temperature @<m>{T} can emit and absorb photons with the energy @<m>{kT}, 
 where @<m>{k} is Boltzmann’s constant. 
 The energy of a photon is @<m>{\hbar\omega}, where @<m>{\omega} is the frequency and @<m>{\hbar} is 
 Planck’s constant divided by 2𝜋.
 We want to make sure that @<m>{kT} << @<m>{\hbar\omega}. For @<m>{\omega/(2\pi) = 5} GHz, this means that @<m>{T} << 0.24 K. 
 In state-of-the-art dilution refrigerators, the temperature of the qubits can be held at 10-15 mK. 
 In this range of temperatures, thermal excitation of 5 GHz qubits can be neglected.

eferring again to Figure 1.12, the quantum processor (QP) containing the qubits is located 
 at the bottom left of the refrigerator. 
 In addition to being kept very close to absolute zero temperature, 
 the quantum processor is also sensitive to stray magnetic fields, 
 so it is further placed inside a magnetic shield within the coldest stage of the refrigerator.

The round component just above the quantum processor is a circulator. 
 This is a non-reciprocal microwave component in which energy can only propagate 
 between ports in the direction of the circulating arrow. 
 By non-reciprocal, we mean that the behavior of the component is different if you interchange the input with the output.
 For example, the RF signal from the control electronics enters the circulator at the top port; 
 the energy “circulates” around to the port to which the quantum processor is connected.
 Any reflected energy from the quantum processor, e.g., containing information about the state of a qubit, 
 then re-enters the bottom port of the circulator. 
 However, since the circulator is non-reciprocal, instead of returning to the input port on the top side of the circulator, 
 it flows instead to the port on the right and is conveyed to the circulator located in the center. 
 We will return to this center circulator in a moment, but let us first consider the chain of coaxial cables and attenuators 
 conveying the control signal to the first circulator.
//image[fig_1_12][System diagram for a superconducting quantum computer.][scale=1.0]{
//}
If we simply used a copper coaxial cable to carry the signal from the roomtemperature electronics into the refrigerator, 
 we would have at least two significant problems.
 First, copper is a good conductor of heat as well as electricity, so the copper cable would convey heat from 
 the upper stages to the lower stages, making it very difficult to reach the temperatures required at the lower stages. 
 To address this, coaxial cables made of an alloy of copper and nickel are used instead. 
 This alloy has very low thermal conductivity to assist with thermally isolating the stages, 
 while having an acceptable electrical conductivity.

The second problem is that a cable coming straight from the outside environment would convey significant noise
 from the environment into the refrigerator. 
 To combat this, attenuators are placed in the lower stages. 
 These attenuators reduce noise power from the upper stages, 
 but introduce their own noise proportional to their equilibrium temperature. 
 Consequently at the lowest stage, the thermal noise is minimized by the very low temperature of the attenuator. 
 Of course these attenuators also reduce the amplitude of the control signal, 
 so we must make sure that the signal level produced by the signal source is strong enough 
 to produce a satisfactory control signal at the quantum processor.

Returning to the signal reflected from the quantum processor, upon entering the center circulator, 
 the energy is transferred to the bottom port and delivered to a Josephson Junction Parametric Amplifier (JPA). 
 This is a quantum-limited amplifier, meaning that the noise it introduces 
 to the circuit is close to the fundamental minimum allowed by quantum theory. 
 The JPA works in reflection mode, so the amplified reflected signal is returned to the circulator 
 and transferred to the final circulator at the bottom right.

The circulator at the bottom right is operated as an isolator. 
 Power applied to the input (left port) is delivered to the output (top port), 
 but any power reflected from impedance mismatches further down line, e.g., at the input of the HEMT amplifier, 
 will be delivered to the matched load attached to the bottom port. 
 In this way, the very sensitive quantum processor and quantum limited amplifier are isolated 
 from reflected power or noise from the upper stages.

The measured signal at this point is very weak, and we definitely would not want to use a stack of attenuators 
 on the output line! Instead, a coaxial cable made of an alloy of Niobium and Titanium (NbTi) is used 
 to convey the signal to the 3 K stage. 
 NbTi is a Type II superconductor with a transition temperature of about 10 K, 
 so it provides an extremely low loss path to the 3 K stage. 
 At the 3 K stage, there is a more conventional low-noise amplifier (LNA), 
 but made using a high electron mobility transistor (HEMT)—a type of transistor that is known for producing very low noise. 
 The signal from the output of the HEMT LNA is further amplified at room temperature before delivery 
 to the signal processing electronics.

Returning to the control-signal electronics, any band-limited signal centered on the frequency @<m>{\omega} can be 
 represented by sine and cosine components:
#@# //indepimage[eq_1_70]
//texequation{
\begin{aligned}
f(t) = I(t) \cos \omega t + Q(t) \sin \omega t,
\end{aligned}\tag{1.70}
//}
where @<m>{I(t)} and @<m>{Q(t)} are “in-phase” and “quadrature” functions whose time variations are 
 slow compared with the period @<m>{T = \frac{2\pi\}{\omega\}} 
 Digital samples of @<m>{I} and @<m>{Q} are converted to band-limited analog signals by digital-to-analog converters followed in general by
 low-pass filters to eliminate high-frequency components resulting from aliasing. 
 The circular components in Figure 1.12 containing “×” are called mixers, 
 and produce an output that is simply the product of the two input signals. 
 For example, the bottom-most mixer produces @<m>{Q(t)} sin 𝜔𝑡 on its output. 
 Similarly, the output of the next-to-bottom mixer is @<m>{I(t)} cos 𝜔𝑡. 
 The outputs of the two mixers are applied to a power combiner, shown as the square component with two terminals on the left, 
 and one on the right.
 The output of the combiner is the sum of the two input signals, 
 creating the desired general signal of the form given by Eq. (1.70). 
 This circuit is referred to as an IQ modulator.

There are different ways of combining RF signals, but the particular one shown is known as a Wilkinson combiner, 
 or Wilkinson divider. 
 Note that this component is reciprocal, so it can be used either as a combiner or a divider. 
 An attractive feature of the Wilkinson circuit when used as a divider is that if all of the ports are matched,
 it does not introduce any loss.

The output signal fromthe quantum processor is applied to a signal processing circuit at the top center of Figure 1.12 
 that is very similar to the IQmodulator used to generate the control signal. 
 The signal is first split into equal parts using a Wilkinson divider, 
 and the divided signals are multiplied by either cos 𝜔𝑡 or sin 𝜔𝑡 before being applied to low-pass filters. 
 The effect of the low-pass filters is to integrate the applied signal, 
 so since the cross term proportional to cos 𝜔𝑡 sin 𝜔𝑡 averages to zero, 
 the filter outputs are proportional to either @<m>{I(t)} or @<m>{Q(t)}. 
 These signals are then digitized and analyzed by the classical computer.

With this high-level description as motivation, we are now ready to discuss in detail the principles that underlie the hardware 
 and software of superconducting quantum computing.

・Chapters 2 and 3 explore the quantum physics that determine the behavior of qubits and gates. 
 This gives us the tools to understand the fundamentals of quantum states and how they can be manipulated.

・Chapters 4-8 show how qubits are constructed from superconducting devices, 
 how they are coupled to each other with microwave transmission lines, 
 and how they are controlled and measured by external systems.

・Chapters 9 and 10 discuss how imperfections in the systemswe build affect the quantum information we are trying to process. 
 In the near term, we need mechanisms to characterize and compensate for errors, while the long-term hope is thatwe will have
 a sufficient number of high-quality qubits to correct errors dynamically and sustain long-running, 
 fault-tolerant quantum computations.

・Finally, Chapters 11 and 12 describe the computations that can be accomplished using qubits and gates, 
 and the potential for applications beyond the capabilities of classical computers.

Our hope is to lay a firm foundation for those new to the quantum computing field whether students or practicing engineers, 
 as a first step toward tackling the many research and engineering challenges
 that are needed to make large-scale quantum computers a reality.

== Exercises
1.1 How many basis states are there for a three-qubit system? Show the vectors for the (computational) basis states.

1.2 There are four Bell states that can be created by entangling two qubits. 
 In addition to the state shown in Figure 1.5, the three additional states are listed below.
#@# //indepimage[ex_1_1]
//texequation{
\begin{aligned}
\text{(a)}\quad \frac{1}{\sqrt{2}} (\ket{00} - \ket{11}) \\
\text{(b)}\quad \frac{1}{\sqrt{2}} (\ket{01} + \ket{10}) \\
\text{(c)}\quad \frac{1}{\sqrt{2}} (\ket{01} - \ket{10})
\end{aligned}
//}

1.3 Prove the following equivalencies.
#@# //indepimage[ex_1_2]
//texequation{
\begin{aligned}
& \text{(a)}\quad HZH = X \\
& \text{(b)}\quad HXH = Z \\
& \text{(c)}\quad HYH = -Y \\
& \text{(d)}\quad \text{CNOT}_{1,0} = H^{\otimes 2} \cdot \text{CNOT}_{0,1} \cdot H^{\otimes 2}
\end{aligned}
//}
In (d), @<m>{CNOT_{i,j\}} means a CNOT with qubit @<m>{i} as the control and qubit @<m>{j} as the target. 
 @<m>{H ^ {\otimes 2\}} means a Hadamard gate applied to both qubits.

1.4 Create a quantum circuit that swaps two qubit states. In other words: |𝑎𝑏⟩ ↦|𝑏𝑎⟩. 
 Hint: Consider this classical algorithm that swaps two numbers @<m>{x} and @<m>{y} using an exclusive-OR (XOR) instruction.
#@# //indepimage[ex_1_3]
//texequation{
\begin{aligned}
& x \leftarrow x XOR y \\
& y \leftarrow y XOR x \\
& x \leftarrow x XOR y
\end{aligned}
//}

1.5 Supposewe design a superconducting qubit where the energy difference between @<m>{|0\rangle} 
 and @<m>{|1\rangle} is around 10 GHz. 
 What is the temperature needed to minimize the effect of thermal energy on the qubit, assuming that the qubit is in thermal
 equilibrium with its environment?

1.6 Consider the following three-qubit quantum state:
#@# //indepimage[ex_1_4]
//texequation{
\begin{aligned}
\ket{q_2 q_1 q_0} = \frac{\ket{010} + \ket{101} + \ket{001} + \ket{110}}{2}
\end{aligned}
//}
Is qubit @<m>{q_2} entangled with the other two qubits? Explain why or why not.

1.7 Suppose we have a way of measuring a qubit in the @<m>{|+\rangle} and @<m>{|-\rangle} basis. As a reminder:
#@# //indepimage[ex_1_5]
//texequation{
\begin{aligned}
\ket{+} = \frac{\ket{0} + \ket{1}}{\sqrt{2}}, \quad
\ket{-} = \frac{\ket{0} - \ket{1}}{\sqrt{2}}
\end{aligned}
//}
#@# //indepimage[ex_1_6]
//texequation{
\begin{aligned}
& \text{(a)Given a qubit in the }\ket{0}\text{ state, what is the probability of measuring }\ket{+}\text{ ? (Hint:Use the Born Rule.)}\\
& \text{(b)Given a qubit in the }\ket{1}\text{ state, what is the probability of measuring }\ket{+}\text{ ? }\\
& \text{(c)Given a qubit in the }\ket{R} = \frac{1}{\sqrt{2}} \ket{0} + \frac{1}{\sqrt{2}} \ket{1}\text{, what is the probability of measuring }\ket{-}\text{ ? }\\
\end{aligned}
//}

1.8 Given a qubit
#@# //indepimage[ex_1_7]
#@# //indepimage[ex_1_8]
//texequation{
\begin{aligned}
& \text{(a)What is the probability of measuring }\ket{0}\text{ ? }\\
& \text{(a)What is the probability of measuring }\ket{+}\text{ ? }\\
& \text{(a)What is the probability of measuring }\ket{-}\text{ ? }\\
\end{aligned}
//}

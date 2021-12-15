# 802. 区间和
假定有一个无限长的数轴，数轴上每个坐标上的数都是 $0$。

现在，我们首先进行 $n$ 次操作，每次操作将某一位置 $x$ 上的数加 $c$。

接下来，进行 $m$ 次询问，每个询问包含两个整数 $l$ 和 $r$，你需要求出在区间 $[l,r]$ 之间的所有数的和。

输入格式
第一行包含两个整数 $n$ 和 $m$ 。

接下来 $n$ 行，每行包含两个整数 $x$ 和 $c$ 。

再接下来 $m$ 行，每行包含两个整数 $l$ 和 $r$。

输出格式
共 $m$ 行，每行输出一个询问中所求的区间内数字和。

数据范围
$−10^{9} \leq x \leq 10^{9}$,

$1 \leq n,m \leq 10^{5}$,

$−10^{9} \leq l \leq r \leq 10^{9}$,

$−10000≤c≤10000$

# Solution
静态区间和问题，可以使用前缀和解决。但是本题的数据范围太大，开辟这么大的空间肯定不会过。但是实际的操作数只有 $10^{5}$，因此，可以考虑使用离散化。将所有操作的位置映射为下标。
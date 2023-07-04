# Math

## 辗转相除法/欧几里得算法求最大公因数

求最大公因数：

```c++
// 前提：a>b
int gcd(int a, int b) {
    if (a%b == 0) return b;
    return gcd(b, a%b);
}
```

求最小公倍数：

```c
int lcm(int a, int b){
    return a*b/gcd(a, b);
}
```

## 模运算

基本的模运算律：

```c
a%mod + b%mod = (a+b) % mod
a%mod - b%mod = (a-b) % mod
a%mod * b%mod = (a*b) % mod
```

注意：

- 有时候`a%mod - b%mod != (a-b) % mod`，比如：`7%5 - 4%5 = -2`而`(7-4)%5 = 3`，因此：`(a%mod - b%mod + m) % mod = (a-b) % mod`。
- 有时候`(a+b) % mod`或`(a*b) % mod`的结果可能小于int最大值，但`a+b`或`a*b`可能超过32位最大值，因此可以将变量设为64位整型。

## 快速幂运算

对于求 $x^n$。

根据 n 的二进制形式，任意 n 可转换为 $n = 2^{k_1} + 2^{k_2} + 2^{k_3} + ...$，例如：$22 = (10110)_2 = 2^4+2^2+2^1 = 16+4+2$。

那么 $x^n$ 可转换为 $x^n = x^{16} \times x^4 \times x^2$。

代码如下：

```c
// 快速幂并取模
ll mod_pow(ll x, ll n, ll mod) {
    // if (mod == 0 || mod == 1) return 0;
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}
```

## 求n以内的质数

1. 暴力。判断一个数 x(x属于`[1,n]`) 是否为质数，遍历 `[2,x-1]` ，如果 x 能被整除则说明不是质数。优化：假如 `p*q = x` 且 `p<q` ，那只需遍历到较小因数 p 就能判断 x 是否为质数，因此只需遍历 `[2, sqrt(x)]` 即可。

2. 埃氏筛。如果一个数 x 为质数，那 2x,3x,··· 一定不是质数，因此可以将它们标记为合数（非质数）。优化：对于一个质数 x ，应该直接从 `x*x` 开始标记，因为 2x,3x,··· 这些数一定在 x 之前就被其它数的倍数标记了。

    ```c
    for (int i = 2; i < n; ++i) {
        if (isPrime[i] && i*i < n) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    ```

3. 线性筛。埃氏筛的优化，详情见：https://leetcode.cn/problems/count-primes/solution/ji-shu-zhi-shu-by-leetcode-solution/ 。

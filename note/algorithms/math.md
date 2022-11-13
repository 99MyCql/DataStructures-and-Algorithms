# Math

## 最大公因数和最小公倍数

求最大公因数（辗转相除法/欧几里得算法）：

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

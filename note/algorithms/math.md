# Math

## 最大公约数

```c
int gcd(int a, in b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

## 模运算

基本的模运算律：

```c
(a + b) mod m = (a mod m) + (b mod m)
(a - b) mod m = (a mod m) - (b mod m)
(a * b) mod m = (a mod m) * (b mod m)
```

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

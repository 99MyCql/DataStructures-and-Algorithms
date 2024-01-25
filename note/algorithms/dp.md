# DP

## 简介

动态规划(Dynamic programming, DP)，本质上是一种空间换时间的算法。它先把问题转换为可递归计算的子问题，然后将重复计算的数据保存起来，从而减少重复计算，降低时间复杂度。

## 示例

以斐波那契数列为例 `f(1)=1，f(2)=1, f(n)=f(n-1)+f(n-2)` ，这显然是一个递归问题。但在递归过程中，我们发现某些值总会被重复计算。如下图计算`f(6)`，在递归计算 `f(4)` 过程中 `f(3), f(4)` 的值都已得出，但在递归计算 `f(5)` 的过程中，`f(4)` 又被计算一次，`f(3)` 又被计算两次，显然这存在重复计算。

![1](img/dp1.png)

对此，我们可以将已计算过的结果保存在一个名为 `dp` 的备忘录数组中，`dp[i] = f(i)`。那么，在递归计算 `f(4)` 过程中，可以将已知结果的 `f(3), f(4)` 分别保存在 `dp[3], dp[4]` 中。最终，`f(6)` 计算过程可转换成下图所示，减少了大量的重复计算。

![1](img/dp2.png)

上述改进方法是动态规划的一种初级解题方式：**带备忘录的自顶向下的递归求解/记忆化搜索**。

它还有另一种更常用更高级的解题方式：**自底向上的动态规划**。根据斐波那契数列的定义，自底向上动态规划的状态转移方程为：`dp[1] = 1, dp[2] = 1, dp[i] = dp[i-1] + dp[i-2] (i > 2)`，可令i从1到6计算 `dp[i]`，最终算出 `dp[6]`。最终可得到一个拓扑排序后的顺序结构——**有向无环图**：

![1](img/dp3.png)

对于斐波拉契数列这种子问题、状态转移方程、边界都已知的问题，可以轻松地使用动态规划方法求解。但对于大多数问题，并不会告诉我们这些，需要我们分析问题、找到规律、自行定义，而这就需要我们从大量题目中寻找经验。

## 小结

从图形的角度，考虑上述示例，若采用递归算法，问题求解过程可看作一颗树，子问题是树中的节点，相同子问题会重复出现。而采用动态规划，求解过程可看作一个**有向无环图DAG**，图中节点对应**子问题（状态）**，边对应**状态间的转移**，子问题不会重复出现，而且是拓扑排序的。

为了构建有向无环图且保证子问题能够按顺序、不重复地计算，动态规划中的子问题是**无后效性**的，即已求解的子问题不受后续未求解子问题的影响。（关于无后效性，参考：[经典动态规划问题（理解「无后效性」）](https://leetcode.cn/problems/maximum-subarray/solution/dong-tai-gui-hua-fen-zhi-fa-python-dai-ma-java-dai/)）

在具体解题中，动态规划通常包含如下关键部分，需要从具体问题中分析并定义。

- 状态（子问题）。定义 `dp[i]` 代表着什么，在定义中，需要保证无后效性。
- 状态转移方程（子问题之间的关系）。定义 `dp[i]` 与 `dp[i-1]` 或 `dp[i-2]` 等之前子问题的转移关系。
- 边界。定义`dp[0]`等。

## 基础DP

### 最长回文子串

定义 `dp[i][j]` 为 `[i,j]` 内的字符串是否为回文串，1代表是，0代表不是。

状态转移方程为：

```c
dp[i][j] = 1, i == j;
dp[i][j] = 1, i+1 == j && s[i] == s[j];
dp[i][j] = dp[i+1][j-1], j > i+1 && s[i] == s[j];
```

注意：由于 `dp[i][j] = dp[i+1][j-1]` ，这道题的递推方式不同于平常，i从后往前，j从前往后。

```c
for (int i = s_len-1; i >= 0; i--) {
    for (int j = i+1; j < s_len; j++) {
        ...
    }
}
```

代码：`exercise\leetcode\5最长回文子串.cpp`

### 最长公共子序列

定义 `dp[i][j]` 表示 s1 的[0,i-1]区间与 s2 的[0,j-1]区间的最长公共子序列长度。

状态转移方程为：

```c
dp[i][j] == 0, i == 0 || j == 0;
dp[i][j] == dp[i-1][j-1] + 1, s1[i] == s2[j];
dp[i][j] == max(dp[i-1][j], dp[i][j-1]);
```

代码：`exercise\leetcode\1143最长公共子序列.cc`

### 最短编辑距离

题目：[https://leetcode-cn.com/problems/edit-distance/](https://leetcode-cn.com/problems/edit-distance/)

类似最长公共子序列。

定义 `dp[i][j]` 为源串 s 的[0,i-1]区间与目标串 t 的[0,j-1]区间的最短编辑距离。

初始化：当目标串为空时，长度为i的源串需进行i次删除操作；源串为空时，若目标串为i，则需进行i次增加操作。

```c
for (int i = 0; i <= a_len; i++) dp[i][0] = i;
for (int i = 0; i <= b_len; i++) dp[0][i] = i;
```

状态转移方程：

```c
dp[i][j] = MIN(
    dp[i-1][j]+1,   // s[i] != t[j], 删除s[i]
    dp[i][j-1]+1,   // s[i] != t[j], 增加一个与t[j]相同的字符
    dp[i-1][j-1]+1, // s[i] != t[j], 将s[i]修改为与t[j]相同
    dp[i-1][j-1]    // s[i] == t[j], 不需任何操作
)
```

### 最大子数组和

这道题的关键在于定义无后效性的子问题！定义 `dp[i]` 代表以`nums[i]` **结尾** 的连续子数组中和最大的值。

状态转移方程为：

```c
dp[i] = max(dp[i-1]+nums[i], nums[i])
```

## 状态压缩DP

长度为n的集合中，**每个元素有0和1两种取值**，那么总共有$2^n$种情况，每种情况看作集合的一个状态。

对于集合的一个状态，我们可以用一个二进制序列表示，而二进制序列又可转换成十进制的数，那么就可以**用一个十进制数表示集合的一种状态**。

比如：长度为4的集合，第1和第2个元素取1，其它元素取0，可表示为 $4=(0011)_2$；所有元素都取0，可表示为 $0=(0000)_2$；所有元素都取1，可表示为 $15=(1111)_2$。

因此，**对于一个长度为n的集合，其各个状态可用十进制 $0 \thicksim 2^n-1$ 内的数一一表示** 。

以上就是状态压缩的精髓，将一个集合状态压缩到一个整数，这样就可以作为数组下标。然后，就可以用DP数组进行状态转移。

## 数位DP

答案跟**数字的数位（指千位、百位、十位）**有关系，前i位的值与前i-1位的值存在关系，且前i位的值会被重复使用。

### 模板

参考[灵神的数位DP通用模板](https://leetcode.cn/problems/count-special-integers/solutions/1746956/shu-wei-dp-mo-ban-by-endlesscheng-xtgx/)，题目为：[2376.统计特殊整数](https://leetcode.cn/problems/count-special-integers/description/)。

由于Python自带记忆化搜索，Python的模板更简明、更好理解：

```py
s = str(n)
@cache  # 记忆化搜索
def f(i: int, mask: int, is_limit: bool, is_num: bool) -> int:
    if i == len(s):
        return int(is_num)  # is_num 为 True 表示得到了一个合法数字
    res = 0
    if not is_num:  # 可以跳过当前数位
        res = f(i + 1, mask, False, False)
    low = 0 if is_num else 1  # 如果前面没有填数字，必须从 1 开始（因为不能有前导零）
    up = int(s[i]) if is_limit else 9  # 如果前面填的数字都和 n 的一样，那么这一位至多填 s[i]（否则就超过 n 啦）
    for d in range(low, up + 1):  # 枚举要填入的数字 d
        if (mask >> d & 1) == 0:  # d 不在 mask 中
            res += f(i + 1, mask | (1 << d), is_limit and d == up, True)
    return res
return f(0, 0, True, False)
```

C++模板修改后如下：

```c++
string s = to_string(n); // 123 -> "123" 。注意：一定要从左到右遍历，即从高位到低位，因为低位受高位限制！！！
int m = s.length();

// dp[i][state]：用于记忆化搜索。
// i 表示第几位，最高位是0。
// state 表示当前位的状态，依据题目变化，可以不需要
vector<vector<int>> dp(m, vector<int>(1<<10, -1));

// i 表示当前第几位，最高位是0。
// mask 表示数位已经选择的数字的集合。这个参数是根据模板所基于的题目添加的，不同题目含义不一样，甚至部分题目可以省去。
// limit 表示当前数位是否有上限。
// zero 表示当前数位之前是否都为0。
function<int(int, int, bool, bool)> dfs = [&](int i, int mask, bool limit, bool zero) -> int {
    if (i == m) {
        if (zero) return 0; // 数字0在本题中非法
        return 1;
    }
    // 此处只记录不受到 limit 和 zero 约束时的状态
    if (!limit && !zero && dp[i][mask] != -1) return dp[i][mask];

    int res = 0;
    // 如果存在前导零，当前数位可继续为0
    if (zero) res = dfs(i + 1, mask, false, true);

    // 如果前面填的数字都和 n 的一样，那么这一位至多填数字 s[i]（否则就超过 n 啦）
    int up = limit ? s[i] - '0' : 9;

    // 枚举当前数位要填入的数字 d 。当存在前导零时，从 1 开始；否则从 0 开始。
    for (int d = zero; d <= up; ++d)
        // d 不在 mask 中
        if ((mask >> d & 1) == 0) res += dfs(i + 1, mask | (1 << d), limit && d == up, false);

    // 此处只记录不受到 limit 和 zero 约束时的状态
    if (!limit && !zero) dp[i][mask] = res;

    return res;
};

return dfs(0, 0, true, true); // 注意：一定要从高位开始遍历（递归），低位受高位限制
```

### 数码出现次数

输入两个正整数a,b，求在[a,b]（0 < a < b < 10^13）中的所有整数中，每个数码（0～9）各出现了多少次。

思路：

- 找规律：`0~9`、`00~99`、`000~999`中各数码出现的次数相等
- 问题简化：可将问题简化为求[a,b]中数码1出现的次数
- 区间拆分：[a,b]中数码1的次数可转换成：[0,b]中数码1的次数 - [0,a-1]中数码1的次数
- 分析状态转移方程：求[0,54321]中数码1的次数，`前5位中1的次数 = 0000~9999中1的次数 * 5（第5位是0~4时，前4位中1出现的次数） + 1*10000（10000~19999间第5位的1出现了共10000次）+ 0000~4321中1出现的次数`。

代码：（有问题，不够简明，应参考[exercise\leetcode\233. 数字 1 的个数.cc](../../exercise/leetcode/233.%20数字%201%20的个数.cc)）

```c++
#include <cstdio>
#include <cstring>
#include <cmath>

#define ll long long


ll digits[60]; // digits[i] 表示数值第i+1位上的数码
ll temp[60]; // temp[i] 表示数值前i位的值，比如：对于54321，temp[0]=0，temp[1]=1，temp[2]=21
ll dp[60]; // dp[i] 表示前i+1位内数码0~9的个数（每个位的数码上限都是9，且允许0的存在）。比如：dp[2]表示3位数（000~999）内各个数码的个数，由于在这范围内各数码对应的个数相同（比如数码0与数码1个数相同），所以只存一个值。

// 求前 p+1 位中，数码 x 的个数
// lim 表示当前位是否考虑上限，zero 表示是否有前导零（最高位到当前位都是0）
ll dfs(int p, int x, bool lim, bool zero) {
    if (p == -1) return 0;
    if (p == 0 && x == 0) return 1; // 前1位中，数码0的个数为1，直接返回
    if (!lim && !zero && dp[p] != -1) return dp[p]; // 不考虑上限和前导零的情况下，直接返回已记录的值
    int up = lim ? digits[p] : 9; // 考虑位上限则取上限，否则取9
    ll ans = 0;
    for (int i = 0; i <= up; i++) {
        if (i == 0 && zero) { // 存在前导零，且当前位为0，则之后也要考虑前导零
            ans += dfs(p-1, x, i == up && lim, true);
        } else if (i == up && lim) { // 到达上限，则之后的取值都要考虑上限
            // 若当前位的值i是目标数码x，则需加上之后位的总值，比如：43210，p=4，i=4，x=4，则4出现了3210次，再加上3210中4出现的次数
            if (i == x) ans += temp[p]+1;
            ans += dfs(p-1, x, true, false);
        } else { // 没有上限
            if (i == x) ans += pow(10, p);
            ans += dfs(p-1, x, false, false);
        }
    }
    if (!lim && !zero) dp[p] = ans;
    return ans;
}

void solve(ll n, ll *res) {
    if (n < 0) return;
    if (n == 0) {
        res[0] = 1;
        return;
    }
    memset(digits, 0, sizeof(digits));
    memset(temp, 0, sizeof(temp));
    memset(dp, -1, sizeof(dp));
    int p = 0;
    while (n) {
        digits[p] = n%10;
        if (p > 0) temp[p] = digits[p-1] * pow(10, p-1) + temp[p-1];
        printf("%d %lld\n", p, temp[p]);
        p++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++) res[i] = dfs(p-1, i, true, true);
}

int main() {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll res_a[10], res_b[10];
    memset(res_a, 0, sizeof(res_a));
    memset(res_b, 0, sizeof(res_b));
    solve(a-1, res_a);
    solve(b, res_b);
    printf("%lld", res_b[0]-res_a[0]);
    for (int i = 1; i < 10; i++) printf(" %lld", res_b[i]-res_a[i]);
}
```

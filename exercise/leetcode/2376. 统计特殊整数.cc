/*
如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。

给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。



示例 1：

输入：n = 20
输出：19
解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。
示例 2：

输入：n = 5
输出：5
解释：1 到 5 所有整数都是特殊整数。
示例 3：

输入：n = 135
输出：110
解释：从 1 到 135 总共有 110 个整数是特殊整数。
不特殊的部分数字为：22 ，114 和 131 。


提示：

1 <= n <= 2 * 109
*/
#include <string>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n); // 123 -> "123"
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

        return dfs(0, 0, true, true);
    }
};
/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。


示例 1：

输入：s = "aa", p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa", p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab", p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。


提示：

1 <= s.length <= 20
1 <= p.length <= 20
s 只包含从 a-z 的小写字母。
p 只包含从 a-z 的小写字母，以及字符 . 和 *。
保证每次出现字符 * 时，前面都匹配到有效的字符
*/
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.size(), pLen = p.size();
        vector<vector<bool>> dp(sLen+5, vector<bool>(pLen+5, false));
        dp[0][0] = true;
        for (int i = 0; i <= sLen; i++) {
            for (int j = 1; j <= pLen; j++) {
                if (i-1 >= 0 && (s[i-1] == p[j-1] || p[j-1] == '.')) {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    // *重复0次
                    dp[i][j] = dp[i][j-2];
                    // *重复>=1次
                    if (i-1 >= 0 && (s[i-1] == p[j-2] || p[j-2] == '.'))dp[i][j] = dp[i-1][j];
                }
                // printf("dp[%d][%d]:%s\n", i, j, dp[i][j]?"true":"false");
            }
        }
        return dp[sLen][pLen];
    }
};
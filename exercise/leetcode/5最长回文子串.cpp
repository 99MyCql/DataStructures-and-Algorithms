/*
给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母（大写和/或小写）组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int s_len = s.size();
        bool dp[s_len][s_len];
        memset(dp, 0, sizeof(dp));
        int max = 1, max_p = 0;
        for (int i = s_len-1; i >= 0; i--) {
            dp[i][i] = true;
            for (int j = i+1; j < s_len; j++) {
                if (s[i] == s[j] && (j-i == 1 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (j-i+1 >= max) {
                        max = j-i+1;
                        max_p = i;
                    }
                }
            }
        }
        return s.substr(max_p, max);
    }
};
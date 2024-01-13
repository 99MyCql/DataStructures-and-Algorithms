#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        int dp[len1+1][len2+1]; // dp[i][j] 表示 text1 的[0,i-1]区间与 text2 的[0,j-1]区间的最长公共子序列长度
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[len1][len2];
    }
};
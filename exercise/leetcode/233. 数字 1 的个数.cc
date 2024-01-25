/*
给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。



示例 1：

输入：n = 13
输出：6
示例 2：

输入：n = 0
输出：0


提示：

0 <= n <= 109
*/
#include <string>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.size();
        vector<int> dp(m, -1);
        function<int(int,bool,bool)> dfs = [&](int i, bool limit, bool zero) -> int {
            if (i == m) return 0;
            if (!limit && !zero && dp[i] != -1) return dp[i];

            int ans = 0;
            if (zero) ans += dfs(i+1, false, true);
            int up = limit? s[i]-'0' : 9;
            for (int d = zero; d <= up; d++) {
                if (d == 1) {
                    if (limit && d == up) {
                        string ss = s.substr(i+1, m-(i+1));
                        if (ss == "") ss = "0";
                        ans += stoi(ss)+1;
                    } else ans += pow(10, m-i-1);
                }
                ans += dfs(i+1, limit && d == up, false);
            }

            if (!limit && !zero) dp[i] = ans;
            return ans;
        };
        return dfs(0,true,true);
    }

    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.size();
        vector<vector<int>> dp(m, vector<int>(10,-1));
        function<int(int,int,bool,bool)> dfs = [&](int i, int cnt, bool limit, bool zero) -> int {
            if (i == m) return cnt;
            if (!limit && !zero && dp[i][cnt] != -1) return dp[i][cnt];

            int ans = 0;
            if (zero) ans += dfs(i+1, cnt, false, true);
            int up = limit? s[i]-'0' : 9;
            for (int d = zero; d <= up; d++) {
                ans += dfs(i+1, cnt + (d==1), limit && d == up, false);
            }

            if (!limit && !zero) dp[i][cnt] = ans;
            return ans;
        };
        return dfs(0,0,true,true);
    }
};
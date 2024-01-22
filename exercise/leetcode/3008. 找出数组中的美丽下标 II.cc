/*
给你一个下标从 0 开始的字符串 s 、字符串 a 、字符串 b 和一个整数 k 。

如果下标 i 满足以下条件，则认为它是一个 美丽下标 ：

0 <= i <= s.length - a.length
s[i..(i + a.length - 1)] == a
存在下标 j 使得：
0 <= j <= s.length - b.length
s[j..(j + b.length - 1)] == b
|j - i| <= k
以数组形式按 从小到大排序 返回美丽下标。



示例 1：

输入：s = "isawsquirrelnearmysquirrelhouseohmy", a = "my", b = "squirrel", k = 15
输出：[16,33]
解释：存在 2 个美丽下标：[16,33]。
- 下标 16 是美丽下标，因为 s[16..17] == "my" ，且存在下标 4 ，满足 s[4..11] == "squirrel" 且 |16 - 4| <= 15 。
- 下标 33 是美丽下标，因为 s[33..34] == "my" ，且存在下标 18 ，满足 s[18..25] == "squirrel" 且 |33 - 18| <= 15 。
因此返回 [16,33] 作为结果。
示例 2：

输入：s = "abcd", a = "a", b = "a", k = 4
输出：[0]
解释：存在 1 个美丽下标：[0]。
- 下标 0 是美丽下标，因为 s[0..0] == "a" ，且存在下标 0 ，满足 s[0..0] == "a" 且 |0 - 0| <= 4 。
因此返回 [0] 作为结果。


提示：

1 <= k <= s.length <= 5 * 105
1 <= a.length, b.length <= 5 * 105
s、a、和 b 只包含小写英文字母。
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> kmp(string &S, string &P) {
        int n = S.size(), m = P.size();
        vector<int> next(m);
        int x = 0;
        for (int i = 1; i < next.size(); i++) {
            while (x > 0 && P[i] != P[x]) x = next[x-1];
            if (P[i] == P[x]) x++;
            next[i] = x;
        }

        vector<int> res;
        int i = 0, j = 0;
        for (int i = 0; i < S.size(); i++) {
            while (j > 0 && S[i] != P[j]) j = next[j-1];
            if (S[i] == P[j]) j++;

            if (j == P.size()) {
                res.push_back(i - m + 1);
                j = next[j-1];
            }
        }
        return res;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> a_pos = kmp(s, a);
        vector<int> b_pos = kmp(s, b);

        vector<int> res;
        for (int i = 0; i < a_pos.size(); i++) {
            int j = lower_bound(b_pos.begin(), b_pos.end(), a_pos[i]-k) - b_pos.begin();
            if (j < b_pos.size() && b_pos[j]-a_pos[i] <= k) res.push_back(a_pos[i]);
        }
        return res;
    }
};
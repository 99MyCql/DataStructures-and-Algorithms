/*
给你一个字符串 s ，找出它的所有子串并按字典序排列，返回排在最后的那个子串。



示例 1：

输入：s = "abab"
输出："bab"
解释：我们可以找出 7 个子串 ["a", "ab", "aba", "abab", "b", "ba", "bab"]。按字典序排在最后的子串是 "bab"。
示例 2：

输入：s = "leetcode"
输出："tcode"


提示：

1 <= s.length <= 4 * 105
s 仅含有小写英文字符。
*/
#include <string>

using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        char maxC = 'a'-1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > maxC) maxC = s[i];
        }

        int i = 0;
        while (s[i] != maxC) i++;
        int j = i+1;
        while (j < s.size() && s[j] != maxC) j++;

        int k = 0;
        while (j+k < s.size()) {
            if (s[i+k] == s[j+k]) k++;
            else if (s[i+k] > s[j+k]) {
                j = j+k+1;
                while (j < s.size() && s[j] != maxC) j++;
                k = 0;
            } else if (s[i+k] < s[j+k]) {
                i = i+k+1;
                if (j <= i) j = i+1;
                while (j < s.size() && s[j] != maxC) j++;
                k = 0;
            }
        }
        return s.substr(i, s.size()-i);
    }
};
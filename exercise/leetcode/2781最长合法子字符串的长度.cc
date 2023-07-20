/*
2781. 最长合法子字符串的长度
给你一个字符串 word 和一个字符串数组 forbidden 。

如果一个字符串不包含 forbidden 中的任何字符串，我们称这个字符串是 合法 的。

请你返回字符串 word 的一个 最长合法子字符串 的长度。

子字符串 指的是一个字符串中一段连续的字符，它可以为空。



示例 1：

输入：word = "cbaaaabc", forbidden = ["aaa","cb"]
输出：4
解释：总共有 9 个合法子字符串："c" ，"b" ，"a" ，"ba" ，"aa" ，"bc" ，"baa" ，"aab" 和 "aabc" 。最长合法子字符串的长度为 4 。
其他子字符串都要么包含 "aaa" ，要么包含 "cb" 。
示例 2：

输入：word = "leetcode", forbidden = ["de","le","e"]
输出：4
解释：总共有 11 个合法子字符串："l" ，"t" ，"c" ，"o" ，"d" ，"tc" ，"co" ，"od" ，"tco" ，"cod" 和 "tcod" 。最长合法子字符串的长度为 4 。
所有其他子字符串都至少包含 "de" ，"le" 和 "e" 之一。


提示：

1 <= word.length <= 105
word 只包含小写英文字母。
1 <= forbidden.length <= 105
1 <= forbidden[i].length <= 10
forbidden[i] 只包含小写英文字母。
*/
#include <string>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> s;
        for (int i = 0; i < forbidden.size(); i++) {
            s.insert(forbidden[i]);
        }
        int len = word.size();
        int l = 0, r = 0;
        int max = 0;
        while (r < len) {
            for (int i = 0; r-i >= l && i < 10; i++) {
                if (s.count(word.substr(r-i,i+1))) {
                    l = r-i+1;
                    break;
                }
            }
            // printf("%d,%d\n", l, r);
            if (r-l+1 > max) max = r-l+1;
            r++;
        }
        return max;
    }
};
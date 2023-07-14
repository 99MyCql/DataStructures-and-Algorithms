/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
 

提示：

m == s.length
n == t.length
1 <= m, n <= 105
s 和 t 由英文字母组成
 

进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-window-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <map>
#include <string>

using namespace std;

class Solution {
    map<char, int> t_map;
    map<char, int> s_map;
public:
    bool check() {
        bool flag = true;
        for (map<char, int>::iterator it = t_map.begin(); it != t_map.end(); it++) {
            if (s_map[it->first] < it->second) flag = false;
        }
        return flag;
    }

    string minWindow(string s, string t) {
        int len = s.size();
        for (int i = 0; i < t.size(); i++) {
            t_map[t[i]]++;
        }

        int st = 0, end = len+1;
        int i = 0, j = 0;
        while (j < len) {
            while (j < len && t_map.count(s[j]) == 0) j++;
            if (j >= len) break;
            s_map[s[j]]++;
            j++;

            while (true) {
                if (s_map.count(s[i])) {
                    if (s_map[s[i]] > t_map[s[i]]) s_map[s[i]]--;
                    else break;
                }
                i++;
            }

            if (check() && (j-i) < (end-st)) {
                end = j;
                st = i;
            }
        }
        if (end == len+1) return "";
        return s.substr(st, end-st);
    }
};

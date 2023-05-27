/*
3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。



示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。


提示：

0 <= s.length <= 5 * 104
s 由英文字母、数字、符号和空格组成
*/
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if (len == 0) return 0;

        int max = 0;
        int i = 0, j = 0;
        int ch_index_map[1000];
        memset(ch_index_map, 0xff, sizeof(ch_index_map));
        while (j < len) {
            if (ch_index_map[s[j]] >= i) {
                i = ch_index_map[s[j]] + 1;
            }
            if (j-i+1 > max) max = j-i+1;
            // printf("i:%d, j:%d, ch[j]:%d, max:%d\n", i, j, ch_index_map[s[j]], max);
            ch_index_map[s[j]] = j;
            j++;
        }
        return max;
    }
};
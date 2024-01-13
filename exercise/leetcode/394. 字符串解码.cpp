/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

 

示例 1：

输入：s = "3[a]2[bc]"
输出："aaabcbc"
示例 2：

输入：s = "3[a2[c]]"
输出："accaccacc"
示例 3：

输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
示例 4：

输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"
 

提示：

1 <= s.length <= 30
s 由小写英文字母、数字和方括号 '[]' 组成
s 保证是一个 有效 的输入。
s 中所有整数的取值范围为 [1, 300]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/decode-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <string>
#include <cstdio>

using namespace std;


class Solution {
public:
    /* 1 */
    // map<int, int> m;

    // string decodeString(string s) {
    //     stack<int> st;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] == '[') st.push(i);
    //         if (s[i] == ']') {
    //             int t = st.top();
    //             st.pop();
    //             m[t] = i;
    //             printf("%d-%d\n", t, i);
    //         }
    //     }

    //     return fun(s, 0, s.size());
    // }

    // string fun(string s, int start, int end) {
    //     printf("%s\n", s.substr(start, end-start).c_str());
    //     string res;
    //     for (int i = start; i < end; i++) {
    //         if (s[i] >= '0' && s[i] <= '9') {
    //             int cnt = 0;
    //             while (s[i] >= '0' && s[i] <= '9') {
    //                 cnt = cnt*10 + s[i]-'0';
    //                 i++;
    //             }
    //             string tmp = fun(s, i+1, m[i]);
    //             for (int j = 0; j < cnt; j++) {
    //                 res += tmp;
    //             }
    //             i = m[i];
    //         } else {
    //             res += s[i];
    //         }
    //     }
    //     return res;
    // }

    /* 2 */
    // string decodeString(string s) {
    //     string res;
    //     stack<int> num_st;
    //     stack<string> res_st;
    //     for (int i = 0; i < s.size(); i++) {
    //         if (s[i] >= '0' && s[i] <= '9') {
    //             int cnt = 0;
    //             while (s[i] >= '0' && s[i] <= '9') {
    //                 cnt = cnt*10 + s[i]-'0';
    //                 i++;
    //             }
    //             i--;
    //             num_st.push(cnt);
    //         } else if (s[i] == '[') {
    //             res_st.push(res);
    //             res = "";
    //         } else if (s[i] == ']') {
    //             for (int j = 0; j < num_st.top(); j++) res_st.top() += res;
    //             res = res_st.top();
    //             res_st.pop();
    //             num_st.pop();
    //         } else {
    //             res += s[i];
    //         }
    //         printf("%d:%s\n", i, res.c_str());
    //     }
    //     return res;
    // }

    /* 3 */
    int len;

    string decodeString(string s) {
        printf("%s\n", s.c_str());
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int cnt = 0;
                while (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt*10 + s[i]-'0';
                    i++;
                }
                string tmp = decodeString(s.substr(i+1));
                for (int j = 0; j < cnt; j++) {
                    res += tmp;
                }
                i += 1+len;
            } else if (s[i] == ']') {
                len = i;
                return res;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};
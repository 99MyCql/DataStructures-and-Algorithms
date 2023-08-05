/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。



示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]


提示：

1 <= n <= 8
*/
#include <vector>
#include <string>

using namespace std;


class Solution {
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        f(n,0,"");
        return res;
    }

    void f(int lCnt, int rCnt, string s) {
        if (lCnt == 0 && rCnt == 0) {
            res.push_back(s);
            return;
        }
        if (lCnt != 0) {
            string tmp = s;
            tmp.push_back('(');
            f(lCnt-1, rCnt+1, tmp);
        }
        if (rCnt != 0) {
            string tmp = s;
            tmp.push_back(')');
            f(lCnt, rCnt-1, tmp);
        }
    }
};
/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。





示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]


提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
*/
#include <string>
#include <vector>

using namespace std;

class Solution {
    string num2chs[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> va, vb;
        va.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            for (int j = 0; j < va.size(); j++) {
                for (int k = 0; k < num2chs[digits[i]-'0'].size(); k++) {
                    string tmp = va[j];
                    tmp.push_back(num2chs[digits[i]-'0'][k]);
                    vb.push_back(tmp);
                }
            }
            va = vb;
            // for (int j = 0; j < va.size(); j++) {
            //     printf("%s ", va[j].c_str());
            // }
            // printf("\n");
            vb.clear();
        }
        if (va[0] == "") return {};
        return va;
    }
};
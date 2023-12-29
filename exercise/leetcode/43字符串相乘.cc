/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。



示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"


提示：

1 <= num1.length, num2.length <= 200
num1 和 num2 只能由数字组成。
num1 和 num2 都不包含任何前导零，除了数字0本身。
*/
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        vector<int> res(m+n, 0);
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                int x = num1[j]-'0', y = num2[i]-'0';
                int sum = res[i+j+1]+x*y;
                res[i+j+1] = sum%10;
                res[i+j] += sum/10;
            }
        }
        string s;
        int i = 0;
        while (i < m+n && res[i] == 0) i++;
        while (i < m+n) {
            s.push_back(res[i]+'0');
            i++;
        }
        return s;
    }
};
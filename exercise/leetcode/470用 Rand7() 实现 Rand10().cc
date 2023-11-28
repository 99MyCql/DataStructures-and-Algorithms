/*
给定方法 rand7 可生成 [1,7] 范围内的均匀随机整数，试写一个方法 rand10 生成 [1,10] 范围内的均匀随机整数。

你只能调用 rand7() 且不能调用其他方法。请不要使用系统的 Math.random() 方法。

每个测试用例将有一个内部参数 n，即你实现的函数 rand10() 在测试时将被调用的次数。请注意，这不是传递给 rand10() 的参数。



示例 1:

输入: 1
输出: [2]
示例 2:

输入: 2
输出: [2,8]
示例 3:

输入: 3
输出: [3,8,10]


提示:

1 <= n <= 105


进阶:

rand7()调用次数的 期望值 是多少 ?
你能否尽量少调用 rand7() ?
*/

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (1) {
            int num = (rand7() - 1) * 7 + rand7();
            if (num <= 40) return num%10 + 1;
        }
    }
};
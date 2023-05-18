/*
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

子数组 是数组的连续子序列。

 

示例 1:

输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: nums = [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 

提示:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
nums 的任何前缀或后缀的乘积都 保证 是一个 32-位 整数

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-product-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int len = nums.size();
        // int max = -0x3f3f3f3f;
        // for (int i = 0; i < len; i++) {
        //     if (nums[i] > max) max = nums[i];
        //     int tmp = nums[i];
        //     for (int j = i+1; j < len; j++) {
        //         tmp *= nums[j];
        //         if (tmp > max) max = tmp;
        //     }
        // }
        // return max;

        int len = nums.size();
        int max_dp[len], min_dp[len];
        memset(max_dp, 0, sizeof(max_dp));
        memset(min_dp, 0, sizeof(min_dp));
        max_dp[0] = min_dp[0] = nums[0];
        int m = nums[0];
        for (int i = 1; i < len; i++) {
            max_dp[i] = max(max(max_dp[i-1]*nums[i], nums[i]), min_dp[i-1]*nums[i]);
            min_dp[i] = min(min(max_dp[i-1]*nums[i], nums[i]), min_dp[i-1]*nums[i]);
            if (max_dp[i] > m) m = max_dp[i];
        }
        return m;
    }
};
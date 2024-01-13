/*
给你一个下标从 0 开始的整数数组 nums ，它包含 n 个 互不相同 的正整数。如果 nums 的一个排列满足以下条件，我们称它是一个特别的排列：

对于 0 <= i < n - 1 的下标 i ，要么 nums[i] % nums[i+1] == 0 ，要么 nums[i+1] % nums[i] == 0 。
请你返回特别排列的总数目，由于答案可能很大，请将它对 109 + 7 取余 后返回。

 

示例 1：

输入：nums = [2,3,6]
输出：2
解释：[3,6,2] 和 [2,6,3] 是 nums 两个特别的排列。
示例 2：

输入：nums = [1,4,3]
输出：2
解释：[3,1,4] 和 [4,1,3] 是 nums 两个特别的排列。
 

提示：

2 <= nums.length <= 14
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/special-permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

// 递归
class Solution {
public:
    int len;
    vector<vector<int>> dp;
    int specialPerm(vector<int>& nums) {
        len = nums.size();
        dp = vector<vector<int>>(1<<len, vector<int>(len, 0));
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum = (sum + dfs(nums, 1<<i, i)) % 1000000007;
        }
        return sum;
    }

    int dfs(vector<int>& nums, int usedMask, int pre) {
        if (usedMask == (1<<len)-1) return 1;
        if (dp[usedMask][pre]) return dp[usedMask][pre];
        int sum = 0;
        for (int i = 0; i < len; i++) {
            if (((1<<i) & usedMask) != 0) continue;
            if (nums[pre]%nums[i] != 0 && nums[i]%nums[pre] != 0) continue;
            sum = (sum + dfs(nums, usedMask | (1<<i), i)) % 1000000007;
        }
        dp[usedMask][pre] = sum;
        return sum;
    }
};

// 递推
class Solution {
    int MOD = 1e9+7;
public:
    int specialPerm(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(1<<len, vector<int>(len, 0));
        for (int i = 0; i < len; i++) {
            dp[(1<<len)-1][i] = 1;
        }
        for (int i = (1<<len)-2; i >= 0; i--) {
            for (int j = 0; j < len; j++) {
                if ((i & (1<<j)) == 0) continue;
                for (int k = 0; k < len; k++) {
                    if ((i & (1<<k)) == 0 && (nums[j]%nums[k] == 0 || nums[k]%nums[j] == 0 )) {
                        dp[i][j] = (dp[i][j] + dp[i|(1<<k)][k]) % MOD;
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum = (sum + dp[1<<i][i]) % MOD;
        }
        return sum;
    }
};
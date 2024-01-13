/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。

 

示例 1：

输入：nums = [1,1,1], k = 2
输出：2
示例 2：

输入：nums = [1,2,3], k = 3
输出：2
 

提示：

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();

        vector<int> S(len, 0);
        S[0] = nums[0];
        for (int i = 1; i < len; i++) {
            S[i] = S[i-1]+nums[i];
        }

        int cnt = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < len; i++) {
            if (m.count(S[i]-k) > 0) cnt += m[S[i]-k];
            if (m.count(S[i]) > 0) m[S[i]]++;
            else m[S[i]] = 1;
        }

        return cnt;
    }
};
/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return {-1,-1};

        int l = 0, r = len-1;
        while (l < r) {
            int mid = (l+r)/2;
            if (nums[mid] >= target) r = mid;
            else l = mid+1;
        }
        if (nums[l] != target) return {-1,-1};
        int start = l;

        l = 0, r = len-1;
        while (l < r) {
            int mid = (l+r+1)/2;
            if (nums[mid] <= target) l = mid;
            else r = mid-1;
        }
        int end = l;
        return {start, end};
    }
};
/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。



示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]


提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
*/
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        fun(nums, 0, path);
        return ans;
    }

    void fun(vector<int>& nums, int used, vector<int>& path) {
        int len = nums.size();
        if (used == ((1<<len) - 1)) ans.push_back(path);
        for (int i = 0; i < len; i++) {
            if ((used & (1<<i)) == 0) {
                path.push_back(nums[i]);
                fun(nums, used|(1<<i), path);
                path.pop_back();
            }
        }
    }
};
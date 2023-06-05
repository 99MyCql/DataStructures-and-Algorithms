/*
2597. 美丽子集的数目
给你一个由正整数组成的数组 nums 和一个 正 整数 k 。

如果 nums 的子集中，任意两个整数的绝对差均不等于 k ，则认为该子数组是一个 美丽 子集。

返回数组 nums 中 非空 且 美丽 的子集数目。

nums 的子集定义为：可以经由 nums 删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。



示例 1：

输入：nums = [2,4,6], k = 2
输出：4
解释：数组 nums 中的美丽子集有：[2], [4], [6], [2, 6] 。
可以证明数组 [2,4,6] 中只存在 4 个美丽子集。
示例 2：

输入：nums = [1], k = 1
输出：1
解释：数组 nums 中的美丽数组有：[1] 。
可以证明数组 [1] 中只存在 1 个美丽子集。


提示：

1 <= nums.length <= 20
1 <= nums[i], k <= 1000
*/
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> v;
        for (int i = 0; i < len; i++) {
            for (int j = i+1; j < len; j++) {
                if (abs(nums[i]-nums[j]) == k) {
                    v.push_back((1<<i) | (1<<j));
                }
            }
        }

        // for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
        // printf("\n");

        int cnt = (1<<len) - 1;
        for (int i = 1; i < 1<<len; i++) {
            for (int j = 0; j < v.size(); j++) {
                if ((i & v[j]) == v[j]) {
                    cnt--;
                    // printf("i:%d, v[j]:%d, cnt:%d\n", i, v[j], cnt);
                    break;
                }
            }
        }
        return cnt;
    }
};
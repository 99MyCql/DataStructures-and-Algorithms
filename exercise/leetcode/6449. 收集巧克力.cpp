/*
6449. 收集巧克力
给你一个长度为 n 、下标从 0 开始的整数数组 nums ，表示收集不同巧克力的成本。每个巧克力都对应一个不同的类型，最初，位于下标 i 的巧克力就对应第 i 个类型。

在一步操作中，你可以用成本 x 执行下述行为：

同时对于所有下标 0 <= i < n - 1 进行以下操作， 将下标 i 处的巧克力的类型更改为下标 (i + 1) 处的巧克力对应的类型。如果 i == n - 1 ，则该巧克力的类型将会变更为下标 0 处巧克力对应的类型。
假设你可以执行任意次操作，请返回收集所有类型巧克力所需的最小成本。



示例 1：

输入：nums = [20,1,15], x = 5
输出：13
解释：最开始，巧克力的类型分别是 [0,1,2] 。我们可以用成本 1 购买第 1 个类型的巧克力。
接着，我们用成本 5 执行一次操作，巧克力的类型变更为 [2,0,1] 。我们可以用成本 1 购买第 0 个类型的巧克力。
然后，我们用成本 5 执行一次操作，巧克力的类型变更为 [1,2,0] 。我们可以用成本 1 购买第 2 个类型的巧克力。
因此，收集所有类型的巧克力需要的总成本是 (1 + 5 + 1 + 5 + 1) = 13 。可以证明这是一种最优方案。
示例 2：

输入：nums = [1,2,3], x = 4
输出：6
解释：我们将会按最初的成本收集全部三个类型的巧克力，而不需执行任何操作。因此，收集所有类型的巧克力需要的总成本是 1 + 2 + 3 = 6 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 109
1 <= x <= 109
*/
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int len = nums.size();
        vector<long long> map(len, LLONG_MAX);
        long long min = LLONG_MAX;
        for (long long i = 0; i < len; i++) {
            long long sum = 1ll*i*x;
            for (int j = 0; j < len; j++) {
                long long tmp = nums[(j+i)%len];
                if (tmp < map[j]) {
                    map[j] = tmp;
                }
                sum += map[j];
            }
            if (sum < min) min = sum;
        }
        return min;
    }
};

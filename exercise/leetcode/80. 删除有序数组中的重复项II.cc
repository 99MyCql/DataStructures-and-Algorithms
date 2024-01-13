/*
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。



说明：

为什么返回数值是整数，但输出的答案是数组呢？

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}


示例 1：

输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
示例 2：

输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。


提示：

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按升序排列
*/
#include <vector>

using namespace std;

class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
    //     int p = 1, cnt = 1;
    //     for (int i = 1; i < nums.size(); i++) {
    //         while (i < nums.size() && nums[i] == nums[p-1] && cnt == 2) i++;
    //         if (i >= nums.size()) break;
    //         nums[p] = nums[i];
    //         if (nums[i] == nums[p-1]) cnt++;
    //         else cnt = 1;
    //         p++;
    //     }
    //     return p;
    // }

    int removeDuplicates(vector<int>& nums) {
        int p = 0, k = 2;
        for (int i = 0; i < nums.size(); i++) {
            if (p < k || nums[p-k] != nums[i]) {
                nums[p] = nums[i];
                p++;
            }
        }
        return p;
    }
};
/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

 

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 

提示：

1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/top-k-frequent-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Item {
    int num;
    int freq;
    Item(int n, int f) : num(n), freq(f) {}
    bool operator < (const Item &i) const {
        return freq > i.freq;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, int> m;
        for (int i = 0; i < len; i++) {
            m[nums[i]]++;
        }
        priority_queue<Item> q;
        for (auto it = m.begin(); it != m.end(); it++) {
            Item item(it->first, it->second);
            if (q.size() < k) {
                q.push(item);
            } else if (q.size() == k && q.top().freq < it->second) {
                q.pop();
                q.push(item);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.top().num);
            q.pop();
        }
        return ans;
    }
};
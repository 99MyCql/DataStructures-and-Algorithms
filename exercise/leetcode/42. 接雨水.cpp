/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // int i = 0, len = height.size();
        // while (i < len && height[i] == 0) i++;

        // i++;
        // while (i < len && height[i] >= height[i-1]) i++;
        // i--;

        // int sum = 0;
        // while (i < len-1) {
        //     int j = i+1;
        //     while (j < len && height[j] <= height[j-1]) j++;
        //     if (j == len) break;
        //     j--;

        //     int k = j+1;
        //     while (k < len && height[k] >= height[k-1]) k++;
        //     k--;

        //     int h = height[i];
        //     if (height[k] < height[i]) h = height[k];
        //     for (int p = i; p <= k; p++) {
        //         if (height[p] < h) sum += (h-height[p]);
        //     }

        //     i = k;
        // }
        // return sum;

        // int len = height.size();
        // int i = 1;
        // vector<int> v;
        // while (i < len) {
        //     while (i < len && height[i] >= height[i-1]) i++;
        //     // printf("i-1:%d\n", i-1);
        //     v.push_back(i-1);
        //     while (i < len && height[i] <= height[i-1]) i++;
        // }
        // int v_len = v.size(), sum = 0;
        // for (int i = 0; i < v_len-1; ) {
        //     printf("v[%d]:%d\n", i, v[i]);
        //     int p = i, max = 0;
        //     for (int j = i+1; j < v_len; j++) {
        //         if (height[v[j]] > height[v[i]]) {
        //             p = j;
        //             break;
        //         }
        //         if (height[v[j]] > max) {
        //             max = height[v[j]];
        //             p = j;
        //         }
        //     }

        //     int h = height[v[i]];
        //     if (height[v[p]] < height[v[i]]) h = height[v[p]];
        //     printf("p:%d, h:%d\n", p, h);
        //     for (int j = v[i]; j <= v[p]; j++) {
        //         if (height[j] < h) sum += (h-height[j]);
        //     }
        //     i = p;
        // }
        // return sum;

        int len = height.size();
        int i = 1;
        while (i < len && height[i] >= height[i-1]) i++;
        stack<int> s;
        s.push(i-1);
        int sum = 0;
        while (i < len) {
            // printf("i:%d\n", i);
            while (!s.empty() && height[i] > height[s.top()]) {
                int t = s.top();
                s.pop();
                if (!s.empty()) {
                    // printf("t:%d,top:%d\n", t, s.top());
                    sum += (i-s.top()-1)*(min(height[s.top()], height[i])-height[t]);
                }
            }
            s.push(i);
            i++;
        }
        return sum;
    }
};
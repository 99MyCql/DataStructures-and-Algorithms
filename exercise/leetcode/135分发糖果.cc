/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。



示例 1：

输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
示例 2：

输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。


提示：

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pi;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        queue<pi> q;
        for (int i = 0; i < n; i++) {
            if ((i-1 >= 0 && i+1 < n && ratings[i] <= ratings[i-1] && ratings[i] <= ratings[i+1]) ||
                (i == 0 && i+1 < n && ratings[i] <= ratings[i+1]) ||
                (i == n-1 && i-1 >= 0 && ratings[i] <= ratings[i-1]) ||
                (i == 0 && i == n-1)) {
                q.push(pi(1,i));
                // printf("i:%d\n", i);
            }
        }
        vector<int> res(n,0);
        while (!q.empty()) {
            pi tmp = q.front();
            q.pop();
            int p = tmp.second, cnt = tmp.first;
            // printf("p:%d, cnt:%d\n",p,cnt);
            res[p] = cnt;
            if (p+1 < n && ratings[p+1] > ratings[p] && res[p+1] <= cnt) q.push(pi(cnt+1, p+1));
            if (p-1 >= 0 && ratings[p-1] > ratings[p] && res[p-1] <= cnt) q.push(pi(cnt+1, p-1));
        }
        int sum = 0;
        for (int i = 0; i < n; i++) sum += res[i];
        return sum;
    }
};
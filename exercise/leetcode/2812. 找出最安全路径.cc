/*
给你一个下标从 0 开始、大小为 n x n 的二维矩阵 grid ，其中 (r, c) 表示：

如果 grid[r][c] = 1 ，则表示一个存在小偷的单元格
如果 grid[r][c] = 0 ，则表示一个空单元格
你最开始位于单元格 (0, 0) 。在一步移动中，你可以移动到矩阵中的任一相邻单元格，包括存在小偷的单元格。

矩阵中路径的 安全系数 定义为：从路径中任一单元格到矩阵中任一小偷所在单元格的 最小 曼哈顿距离。

返回所有通向单元格 (n - 1, n - 1) 的路径中的 最大安全系数 。

单元格 (r, c) 的某个 相邻 单元格，是指在矩阵中存在的 (r, c + 1)、(r, c - 1)、(r + 1, c) 和 (r - 1, c) 之一。

两个单元格 (a, b) 和 (x, y) 之间的 曼哈顿距离 等于 | a - x | + | b - y | ，其中 |val| 表示 val 的绝对值。



示例 1：


输入：grid = [[1,0,0],[0,0,0],[0,0,1]]
输出：0
解释：从 (0, 0) 到 (n - 1, n - 1) 的每条路径都经过存在小偷的单元格 (0, 0) 和 (n - 1, n - 1) 。
示例 2：


输入：grid = [[0,0,1],[0,0,0],[0,0,0]]
输出：2
解释：
上图所示路径的安全系数为 2：
- 该路径上距离小偷所在单元格（0，2）最近的单元格是（0，0）。它们之间的曼哈顿距离为 | 0 - 0 | + | 0 - 2 | = 2 。
可以证明，不存在安全系数更高的其他路径。
示例 3：


输入：grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
输出：2
解释：
上图所示路径的安全系数为 2：
- 该路径上距离小偷所在单元格（0，3）最近的单元格是（1，2）。它们之间的曼哈顿距离为 | 0 - 1 | + | 3 - 2 | = 2 。
- 该路径上距离小偷所在单元格（3，0）最近的单元格是（3，2）。它们之间的曼哈顿距离为 | 3 - 3 | + | 0 - 2 | = 2 。
可以证明，不存在安全系数更高的其他路径。


提示：

1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] 为 0 或 1
grid 至少存在一个小偷
*/
#include <vector>
#include <queue>

using namespace std;


class Solution {
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n, vector<int>(n,-1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push(pair<int,int>(i,j));
                    dis[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int x = p.first+dir[i][0], y = p.second+dir[i][1];
                if (x < 0 || x >= n || y < 0 || y >= n || dis[x][y] >= 0) continue;
                dis[x][y] = dis[p.first][p.second]+1;
                q.push(pair<int,int>(x,y));
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         printf("%d ", dis[i][j]);
        //     }
        //     printf("\n");
        // }

        int max = min(dis[0][0], dis[n-1][n-1]);
        for (int i = max; i >= 0; i--) {
            // printf("---%d\n", i);
            vector<vector<int>> visited(n, vector<int>(n,0));
            queue<pair<int,int>> qq;
            qq.push(pair<int,int>(0,0));
            while (!qq.empty()) {
                pair<int,int> p = qq.front();
                qq.pop();
                for (int j = 0; j < 4; j++) {
                    int x = p.first+dir[j][0], y = p.second+dir[j][1];
                    if (x < 0 || x >= n || y < 0 || y >= n || dis[x][y] < i || visited[x][y]) continue;
                    visited[x][y] = 1;
                    // printf("%d,%d\n", x, y);
                    qq.push(pair<int,int>(x,y));
                }
            }
            if (visited[n-1][n-1]) return i;
        }
        return 0;
    }
};
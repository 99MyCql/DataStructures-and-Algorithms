/*
有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋 。
 

示例 1：

输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]


示例 2：

输入: heights = [[2,1],[1,2]]
输出: [[0,0],[0,1],[1,0],[1,1]]
 

提示：

m == heights.length
n == heights[r].length
1 <= m, n <= 200
0 <= heights[r][c] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>

using namespace std;


// class Solution {
// public:
//     int n;
//     int m;
//     int dfs(int i, int j, vector<vector<int>>& heights,
//         vector<vector<bool>>& flag, vector<vector<int>> &dp) {
//         flag[i][j] = true;
//         // printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
//         if (dp[i][j] != 0) return dp[i][j];

//         bool tp = false, ta = false;
//         if (j == 0 || i == 0) tp = true;
//         if (j == m-1 || i == n-1) ta = true;

//         int d[4] = {0};
//         if (j-1 >= 0 && !flag[i][j-1] && heights[i][j-1] <= heights[i][j])
//             d[0] = this->dfs(i, j-1, heights, flag, dp);
//         if (i-1 >= 0 && !flag[i-1][j] && heights[i-1][j] <= heights[i][j])
//             d[1] = this->dfs(i-1, j, heights, flag, dp);
//         if (j+1 < m && !flag[i][j+1] && heights[i][j+1] <= heights[i][j])
//             d[2] = this->dfs(i, j+1, heights, flag, dp);
//         if (i+1 < n && !flag[i+1][j] && heights[i+1][j] <= heights[i][j])
//             d[3] = this->dfs(i+1, j, heights, flag, dp);

//         for (int i = 0; i < 4; i++) {
//             if (d[i] == 1) tp = true;
//             else if (d[i] == 2) ta = true;
//             else if (d[i] == 3) {
//                 tp = true;
//                 ta = true;
//             }
//         }
//         if (tp && !ta) return 1;
//         else if (!tp && ta) return 2;
//         else if (tp && ta) return 3;
//         return 0;
//     }

//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         n = heights.size();
//         m = heights[0].size();

//         vector<vector<int>> ans;
//         vector<vector<int>> dp(n, vector<int>(m, 0));
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 vector<vector<bool>> flag(n, vector<bool>(m, false));
//                 // printf("====%d,%d====\n", i, j);
//                 dp[i][j] = dfs(i, j, heights, flag, dp);
//                 // printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
//                 if (dp[i][j] == 3) {
//                     vector<int> tmp(2);
//                     tmp[0] = i;
//                     tmp[1] = j;
//                     ans.push_back(tmp);
//                 }
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int n;
    int m;
    vector<vector<int>> heights;
    void dfs(int i, int j, vector<vector<bool>>& flag) {
        if (flag[i][j]) return;
        flag[i][j] = true;
        for (int x = 0; x < 4; x++) {
            int newi = i+dirs[x][0], newj = j + dirs[x][1];
            if (newi >= 0 && newi < n && newj >= 0 && newj < m &&
                heights[newi][newj] >= heights[i][j])
                this->dfs(newi, newj, flag);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        this->heights = heights;

        vector<vector<bool>> top(n, vector<bool>(m, false));
        vector<vector<bool>> toa(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++) dfs(0, i, top);
        for (int i = 0; i < n; i++) dfs(i, 0, top);
        for (int i = 0; i < m; i++) dfs(n-1, i, toa);
        for (int i = 0; i < n; i++) dfs(i, m-1, toa);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (top[i][j] && toa[i][j]) {
                    vector<int> tmp(2);
                    tmp[0] = i;
                    tmp[1] = j;
                    ans.push_back(tmp);
                }
            }
        }

        return ans;
    }
};
/*
79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。



示例 1：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true
示例 3：


输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false


提示：

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board 和 word 仅由大小写英文字母组成


进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
*/
#include <vector>
#include <string>

using namespace std;

class Solution {
    int dirs[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    int m, n, len;
    vector<vector<bool>> used;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        len = word.size();
        used = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board,word,i,j,0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int p) {
        if (p == len) return true;
        if (!(x >= 0 && x < m && y >= 0 && y < n) || board[x][y] != word[p] || used[x][y]) return false;

        used[x][y] = true;
        bool b = false;
        for (int i = 0; i < 4; i++) {
            int nx = x+dirs[i][0], ny = y+dirs[i][1];
            if (dfs(board,word,nx,ny,p+1)) b = true;
        }
        used[x][y] = false;
        return b;
    }
};
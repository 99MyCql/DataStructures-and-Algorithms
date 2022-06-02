/*
你将得到一个整数数组 matchsticks ，其中 matchsticks[i] 是第 i 个火柴棒的长度。你要用 所有的火柴棍 拼成一个正方形。你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次 。

如果你能使这个正方形，则返回 true ，否则返回 false 。

 

示例 1:



输入: matchsticks = [1,1,2,2,2]
输出: true
解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例 2:

输入: matchsticks = [3,3,3,3,4]
输出: false
解释: 不能用所有火柴拼成一个正方形。
 

提示:

1 <= matchsticks.length <= 15
1 <= matchsticks[i] <= 108

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/matchsticks-to-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> v;
    int n;
    int length;
    int cnt = 0;

    bool dfs(int p, vector<int>& e) {
        if (p >= n) {
            for (int i = 0; i < 4; i++) {
                if (e[i] < length) return false;
            }
            return true;
        }
        for (int i = 0; i < 4; i++) {
            if (e[i]+v[p] <= length) {
                e[i] += v[p];
                if (dfs(p+1, e)) return true;
                e[i] -= v[p];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        this->n = matchsticks.size();
        this->v = matchsticks;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += matchsticks[i];
        }
        if (sum % 4 != 0) return false;
        this->length = sum/4;
        sort(v.begin(), v.end(), greater<int>());
        vector<int> e(4, 0);
        return dfs(0, e);
    }
};
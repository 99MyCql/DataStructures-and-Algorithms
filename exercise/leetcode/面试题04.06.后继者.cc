/*
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /
1

输出: null

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/successor-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <cstdio>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        stack<TreeNode*> s;
        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (pre == p) return cur;
            pre = cur;
            cur = cur->right;
        }
        return NULL;
    }
};
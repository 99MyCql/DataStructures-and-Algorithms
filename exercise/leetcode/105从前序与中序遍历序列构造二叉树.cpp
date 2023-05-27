/*
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

示例 1:


输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:

输入: preorder = [-1], inorder = [-1]
输出: [-1]
 

提示:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;

        vector<int> l_preorder, r_preorder, l_inorder, r_inorder;
        int i = 0;
        while (i < inorder.size() && inorder[i] != preorder[0]) {
            l_inorder.push_back(inorder[i]);
            i++;
        }
        i++;
        while (i < inorder.size()) {
            r_inorder.push_back(inorder[i]);
            i++;
        }
        for (int i = 1; i < 1+l_inorder.size(); i++) l_preorder.push_back(preorder[i]);
        for (int i = 1+l_preorder.size(); i < preorder.size(); i++) r_preorder.push_back(preorder[i]);

        TreeNode* node = new TreeNode(preorder[0]);
        node->left = buildTree(l_preorder, l_inorder);
        node->right = buildTree(r_preorder, r_inorder);
        return node;
    }
};
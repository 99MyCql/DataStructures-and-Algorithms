/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。


示例 1：


输入：root = [2,1,3]
输出：true
示例 2：


输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。


提示：

树中节点数目范围在[1, 104] 内
-231 <= Node.val <= 231 - 1
*/
#include <climits>

using namespace std;


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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        int max = INT_MIN, min = INT_MAX;
        if (root->left != nullptr
            && (isValidBST(root->left, max, min) == false || max >= root->val)) return false;

        max = INT_MIN, min = INT_MAX;
        if (root->right != nullptr
            && (isValidBST(root->right, max, min) == false || min <= root->val)) return false;
        return true;
    }

    bool isValidBST(TreeNode* root, int &max, int &min) {
        max = root->val, min = root->val;

        if (root->left != nullptr) {
            if (root->left->val >= root->val) return false;

            int maxT = INT_MIN, minT = INT_MAX;
            if (isValidBST(root->left, maxT, minT) == false || maxT >= root->val) return false;
            min = minT;
        }

        if (root->right != nullptr) {
            if (root->right->val <= root->val) return false;

            int maxT = INT_MIN, minT = INT_MAX;
            if (isValidBST(root->right, maxT, minT) == false || minT <= root->val) return false;
            max = maxT;
        }
        return true;
    }
};

class Solution {
public:
    long long pre = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isValidBST(root->left)) return false;
        if (root->val <= pre) return false;
        pre = root->val;
        if (!isValidBST(root->right)) return false;
        return true;
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return fun(root, LLONG_MIN, LLONG_MAX);
    }

    bool fun(TreeNode* root, long long min, long long max) {
        if (root == nullptr) return true;

        if (root->val <= min || root->val >= max) return false;

        return fun(root->left, min, root->val) && fun(root->right, root->val, max);
    }
};
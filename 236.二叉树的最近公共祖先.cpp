/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node. */
// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q) {
      return root;
    }
    TreeNode *leftT = (lowestCommonAncestor(root->left, p, q));
    TreeNode *rightT = (lowestCommonAncestor(root->right, p, q));
    if (leftT && rightT) {
      return root;
    } else if (rightT) {
      return rightT;
    } else {
      return leftT;
    }
  }
};
// @lc code=end

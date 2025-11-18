struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  bool empty(TreeNode *root) {
    if (!root) {
      return true;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return true;
    }
    return false;
  }

public:
  TreeNode *invertTree(TreeNode *root) {
    if (empty(root)) {
      return root;
    }
    auto left = root->left;
    auto right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
  }
};
// @lc code=end

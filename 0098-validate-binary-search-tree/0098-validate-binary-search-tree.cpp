/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool isValidBSTHelper(TreeNode* root, long low, long high) {
    if (root == NULL) return true;
    if (root->val <= low || root->val >= high) return false;
    return isValidBSTHelper(root->left, low, root->val) && isValidBSTHelper(root->right, root->val, high);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}
};
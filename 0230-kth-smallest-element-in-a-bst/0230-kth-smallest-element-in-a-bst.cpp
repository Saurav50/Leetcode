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
    void genInorder(TreeNode* root,vector<int>& in){
        if(!root) return;
        genInorder(root->left,in);
        in.push_back(root->val);
        genInorder(root->right,in);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in;
        genInorder(root,in);
        return k-1>=0? in[k-1]:-1;
    }
};
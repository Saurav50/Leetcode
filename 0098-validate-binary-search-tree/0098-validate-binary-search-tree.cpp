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
    void genInorder(TreeNode* root,vector<int> &in){
        if(root==NULL) return;

        if(root->left) genInorder(root->left,in);
        in.push_back(root->val);
        if(root->right) genInorder(root->right,in);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        genInorder(root,in);
        bool check=true;
        for(int i=1;i<in.size();i++){
            if(in[i]<=in[i-1]){
                check=false;
                break;
            }
        }
        return check;
    }
};
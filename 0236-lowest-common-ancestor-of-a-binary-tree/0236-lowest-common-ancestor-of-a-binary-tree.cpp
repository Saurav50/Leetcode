/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool genPath(TreeNode* root,vector<TreeNode*>&path,TreeNode* k){
        if(root==NULL) return false;
        if(root==k){
            path.push_back(root);
            return true;
        }
        path.push_back(root);
        if(genPath(root->left,path,k)||genPath(root->right,path,k)){
            return true;
        }
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathP;
        vector<TreeNode*> pathQ;
        genPath(root,pathP,p);
        genPath(root,pathQ,q);
        int i = 0;
        while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
            i++;
        }

        // The LCA is the last common node
        return pathP[i - 1];
       

    }
};
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
    pair<int,int> calHeight(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> l=calHeight(root->left);
        pair<int,int> r=calHeight(root->right);
        int h=max(l.first,r.first)+1;
        int d=l.first+r.first;
        int dia=max(l.second,max(r.second,d));
        return {h,dia};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        pair<int,int> p=calHeight(root);
        return p.second;

    }
};
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
    int genInorder(TreeNode* root,int k,int &c){
        if(!root) return -1;
        int left=genInorder(root->left,k,c);
        if(left!=-1) return left;
        c++;
        if(c==k) return root->val;
        int right=genInorder(root->right,k,c);
        
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        return genInorder(root,k,c);
        
    }
};
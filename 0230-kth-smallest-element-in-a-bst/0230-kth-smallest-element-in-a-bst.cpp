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
    int kthSmallestHelper(TreeNode* root, int k,int &counter) {
        if(root==NULL){
            return -1;
        }
        
        int left=kthSmallestHelper(root->left,k,counter);
        if(left!=-1) return left;
        counter++;
        if(counter==k){
            return root->val;
        }
        return kthSmallestHelper(root->right,k,counter);
    }
    int kthSmallest(TreeNode* root, int k){
        int counter=0;
        return kthSmallestHelper(root,k,counter);
    }
};
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
    int maxPathSumCall(TreeNode* root,int &maxi) {
        if(root==NULL) return 0;
        int leftS=max(0,maxPathSumCall(root->left,maxi));
        int rightS=max(0,maxPathSumCall(root->right,maxi));
        maxi=max(maxi,leftS+rightS+root->val);
        return root->val+max(leftS,rightS);
    }
    int maxPathSum(TreeNode* root){
        int maxi=INT_MIN;
        maxPathSumCall(root,maxi);
        return maxi;
    }
};
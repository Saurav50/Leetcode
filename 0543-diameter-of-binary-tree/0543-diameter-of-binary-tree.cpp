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
    int calHeight(TreeNode* root){
        if(root==NULL) return 0;
        return max(calHeight(root->left),calHeight(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=INT_MIN;
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            int leftHeight=calHeight(front->left);
            int rightHeight=calHeight(front->right);
            ans=max(ans,leftHeight+rightHeight);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        return ans;

    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int>> ans;
        if(root==NULL) return ans;
        queue <TreeNode*> pendingNodes;
        pendingNodes.push(root);
   
        while(pendingNodes.size()!=0){
            vector<int> temp;
            int size=pendingNodes.size();
            for(int i=0;i<size;i++){
                TreeNode *front=pendingNodes.front();
                pendingNodes.pop();
                temp.push_back(front->val);
                if(front->left)  pendingNodes.push(front->left);
                if(front->right) pendingNodes.push(front->right);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
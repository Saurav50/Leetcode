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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int minI=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                int currI=q.front().second-minI;
                if(i==0) first=currI;
                if(i==size-1) last=currI;
                
                TreeNode* front=q.front().first;
                q.pop();
                if(front->left) q.push({front->left,(long long)2*currI+1});
                if(front->right) q.push({front->right,(long long)2*currI+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};
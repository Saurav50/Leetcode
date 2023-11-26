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
    void NodesAtDepthK(TreeNode* root,int k,vector<int>& v){
    if (root == NULL) return ;
    if(k==0){
        v.push_back(root->val);
        return;
    }
    NodesAtDepthK(root->left,k-1,v);
    NodesAtDepthK(root->right,k-1,v);
}

int DistanceK(TreeNode*root,int target,int k,vector<int>&v){
    if (root == NULL) return -1;
    if(root->val==target){
        NodesAtDepthK(root,k,v);
        return 0;
    }
    int left = DistanceK(root->left,target,k,v);
    if(left!=-1 && left+1==k){
        v.push_back(root->val);
    }
    if(left!=-1){
         NodesAtDepthK(root->right,k-(left+1)-1,v);
         return left+1; // distance increase by 1 from current node to target
    }

    int right = DistanceK(root->right,target,k,v);
    if(right!=-1 && right+1==k){
       v.push_back(root->val);
    }
    if(right!=-1){
        NodesAtDepthK(root->left,k-(right+1)-1,v);
        return right +1; // distance increase by 1 from current node to target
    }
    return -1;
}
    
    
    
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v;
        DistanceK(root,target->val,k,v);
        return v;
        
    }
};
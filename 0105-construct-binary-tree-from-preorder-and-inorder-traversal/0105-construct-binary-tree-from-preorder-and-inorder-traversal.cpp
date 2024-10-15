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
    TreeNode* buildTreeCall(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,map<int,int> &inorderMap){
        if (ps > pe || is > ie) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);
        int rootidx=inorderMap[preorder[ps]];
        TreeNode* leftSubTree=buildTreeCall(preorder,ps+1,ps+rootidx-is,inorder,is,rootidx-1,inorderMap);
        TreeNode* rightSubTree=buildTreeCall(preorder,ps+rootidx-is+1,pe,inorder,rootidx+1,ie,inorderMap);
        root->left=leftSubTree;
        root->right=rightSubTree;

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return NULL;
        map<int,int> inorderMap;
        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]]=i;
        }
        TreeNode* root=buildTreeCall(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inorderMap);
        return root;
        
    }
};
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
    TreeNode* helper(vector<int>& preorder,int start,int end){
        if(start>end) return NULL;
        TreeNode* root=new TreeNode(preorder[start]);
        int idx=-1;
        for(int i=start+1;i<=end;i++){
            if(preorder[i]<preorder[start]){
                idx=i;
            }else break;
        }
        if(idx!=-1){
            root->left=helper(preorder,start+1,idx);
            root->right=helper(preorder,idx+1,end);
        } else root->right=helper(preorder,start+1,end);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        return helper(preorder,0,preorder.size()-1);
    }
};
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
class HieghtDiaPair{
    public:
    int height;
    int dia;
    HieghtDiaPair(int h,int d){
        this->height=h;
        this->dia=d;
    }
};

class Solution {
public:
    
    HieghtDiaPair * diameterBetter(TreeNode* root){
    if(root==NULL){
        HieghtDiaPair *hdp=new HieghtDiaPair(0,0);
        return hdp;
    }
    HieghtDiaPair * leftSubtreeInfo = diameterBetter(root->left);
    HieghtDiaPair * rightSubtreeInfo =diameterBetter(root->right);
    HieghtDiaPair * infoOfRoot = new HieghtDiaPair(1+ max( leftSubtreeInfo->height,rightSubtreeInfo->height),max(leftSubtreeInfo->dia,max(leftSubtreeInfo->height+rightSubtreeInfo->height,rightSubtreeInfo->dia)));
    return infoOfRoot;
}
    
       
    int diameterOfBinaryTree(TreeNode* root) {
            if(root==NULL) return 0;
    HieghtDiaPair *ans=diameterBetter(root);
    return ans->dia;
        
        
    }
};
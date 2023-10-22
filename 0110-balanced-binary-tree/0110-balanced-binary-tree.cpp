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

class BalancedPair{
    public:
    bool isBalanced;
    int height;
    BalancedPair(bool isBalanced,int h){
        this->isBalanced=isBalanced;
        this->height=h;
    }
};

class Solution {
public:
    
    // IsBalanced better approach
    BalancedPair* isBalancedBetter(TreeNode* root){
        if (root == NULL) return new BalancedPair(true,0);
        BalancedPair *lp=isBalancedBetter(root->left);
        BalancedPair *rp=isBalancedBetter(root->right);
        bool balance=lp->isBalanced&&rp->isBalanced;
        if(!balance) return new BalancedPair(false,max(lp->height,rp->height)+1);
        else{
            int temp= lp->height-rp->height;
            if(temp<-1 || temp >1 )return new BalancedPair(false,max(lp->height,rp->height)+1);
            else return new BalancedPair(true,max(lp->height,rp->height)+1);
        }

    }
    
    bool isBalanced(TreeNode* root) {
       BalancedPair *ans=isBalancedBetter(root);
        return ans->isBalanced;
    }
};
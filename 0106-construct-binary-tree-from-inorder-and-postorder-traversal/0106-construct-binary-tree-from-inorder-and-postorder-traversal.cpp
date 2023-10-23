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
    
    //Tree construct using inorder Nd postOrder
    TreeNode* ConstructTreePost(vector<int>& inOrder, vector<int>& postOrder,int inS,int inE,int postS,int postE){
        if (inS > inE || postS > postE) return NULL;
        TreeNode *root = new TreeNode(postOrder[postE]); 
        int rootIndex=-1;
        int rootData=postOrder[postE];
        for(int i=inS;i<=inE;i++){
            if(inOrder[i]==rootData){
                rootIndex=i;
                break;
            }
        }
        //left subtree
        int LinS=inS;
        int LinE=rootIndex-1;
        int LpostS=postS;
        int LpostE=LpostS+(LinE-LinS);
        root->left=ConstructTreePost(inOrder,postOrder,LinS,LinE,LpostS,LpostE);
        //right subtree
        int RinS=rootIndex+1;
        int RinE=inE;
        int RpostS=LpostE+1;
        int RpostE=postE-1;
        root->right=ConstructTreePost(inOrder,postOrder,RinS,RinE,RpostS,RpostE);
        return root;
    }


    
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size();
        return ConstructTreePost(inorder,postorder,0,size-1,0,size-1);
        
        
    }
};
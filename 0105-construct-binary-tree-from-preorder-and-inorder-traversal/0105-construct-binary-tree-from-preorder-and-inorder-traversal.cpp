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
    // Tree construct using inorder Nd preOrder
    TreeNode* ConstructTreePre(vector<int>& preOrder, vector<int>& inOrder,int inS,int inE,int preS,int preE){
        if (inS > inE || preS>preE) return NULL;

        TreeNode *root=new TreeNode(preOrder[preS]);
        int rootData=preOrder[preS];
        int rootIndex=-1;
        for(int i=inS;i<=inE;i++){
            if(inOrder[i]==rootData){
                rootIndex=i;
                break;
            }
        }

        //construct left subtree

        int LinS=inS;
        int LinE=rootIndex-1;
        int LpreS=preS+1;
        int LpreE=LpreS+(LinE-LinS);
        TreeNode *leftChild=ConstructTreePre(preOrder,inOrder,LinS,LinE,LpreS,LpreE);
        root->left=leftChild;

        //construct right subtree
        int RinS=rootIndex+1;
        int RinE=inE;
        int RpreS=LpreE+1;
        int RpreE=preE;
        TreeNode *rightChild=ConstructTreePre(preOrder,inOrder,RinS,RinE,RpreS,RpreE);
        root->right=rightChild;

        return root;


    }

    
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
        return ConstructTreePre(preorder,inorder,0,size-1,0,size-1);
        
    }
};
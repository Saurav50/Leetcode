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
class BSTIterator {
    
    private: 
    stack<TreeNode*> s;
    bool isreverse;
    
    void pushAll(TreeNode* root){
        if(root==NULL) return;
        
        s.push(root);
        if(!isreverse) pushAll(root->left); 
        else pushAll(root->right);
    }
public:
    BSTIterator(TreeNode* root,bool reverse) {
        this->isreverse=reverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode *current=s.top();
        s.pop();
        if(!isreverse){
            if(current->right){
                pushAll(current->right);
            }
        }else{
            if(current->left){
                pushAll(current->left);
            }
        }
        return current->val;   
    }
    
    bool hasNext() {
        bool size=s.size();
        return size;
        
    }
};



class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
        
        
    }
};
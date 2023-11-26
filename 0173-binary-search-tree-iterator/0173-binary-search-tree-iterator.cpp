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
    void pushLefts(TreeNode* root){
        if(root==NULL) return;
        s.push(root);
        pushLefts(root->left); 
    }
public:
    BSTIterator(TreeNode* root) {
        pushLefts(root);
    }
    
    int next() {
        TreeNode *current=s.top();
        s.pop();
        if(current->right){
            pushLefts(current->right);
        }
        return current->val;   
    }
    
    bool hasNext() {
        bool size=s.size();
        return size;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
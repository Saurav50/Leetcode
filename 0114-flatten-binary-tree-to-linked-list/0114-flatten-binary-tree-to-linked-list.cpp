class Solution {
public:
    pair<TreeNode*, TreeNode*> helper(TreeNode* root) {
        if (root == nullptr) return {nullptr, nullptr};
        
    
        pair<TreeNode*, TreeNode*> lSub = helper(root->left);
        pair<TreeNode*, TreeNode*> rSub = helper(root->right);
        // Connect left subtree to the right
        root->left =   NULL;
        root->right = lSub.first;
        
   
        
        // Connect the tail of left subtree to the head of right subtree
        if (lSub.second) {
            lSub.second->right = rSub.first;
        } else {
            root->right = rSub.first;
        }
        
        // Return the new subtree and its tail
        // return {head,tail}
        return {root, rSub.second ? rSub.second :(lSub.second ? lSub.second : root)};
    }
    
    void flatten(TreeNode* root) {
        pair<TreeNode*, TreeNode*> p = helper(root);
        root = p.first;  // Update root to point to the new flattened tree
    }
};

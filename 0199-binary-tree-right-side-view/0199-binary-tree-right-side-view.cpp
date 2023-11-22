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

    void helper(TreeNode* node, int level, vector<int>& v){
        if(node==NULL) return ;

        if(v.size()==level){
            v.push_back(node->val);
        }
        helper(node->right,level+1,v);
        helper(node->left,level+1,v);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector <int> v;
        helper(root,0,v);
        return v;
 
    }
};
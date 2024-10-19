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
    void traverse(TreeNode* root,unordered_set<int> &s){
        if(!root) return;
        traverse(root->left,s);
        s.insert(root->val);
        traverse(root->right,s);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        traverse(root,s);
        for(auto ele:s){
            int rem=k-ele;
            if(rem == ele) continue;
            if(s.find(rem)!=s.end()){
                return true;
            }
        }
        return false;
    }
};
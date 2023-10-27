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
#include <stack>
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if (root == NULL) return v;
    stack<TreeNode *> s1,s2;
     
    s1.push(root);
    while(!s1.empty() || !s2.empty()) {

            TreeNode *temp = NULL;
            vector<int> v1;
            while(!s1.empty()){
                temp=s1.top();
                s1.pop();
                v1.push_back(temp->val);
                if(temp->left) s2.push(temp->left);
                if(temp->right) s2.push(temp->right);
            }
        if(v1.size()!=0) v.push_back(v1);
        vector<int> v2;
            
            while(!s2.empty()) {
                temp = s2.top();
                s2.pop();
                v2.push_back(temp->val);
                if(temp->right) s1.push(temp->right);
                if(temp->left) s1.push(temp->left);    
            }
            if(v2.size()!=0)v.push_back(v2);
    }
        return v;


        
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Your code here
        queue<pair<TreeNode*, pair<int,int>>> q;//{Node,{vertical,level}}
        map<int,map<int,multiset<int>>> map;//{vertical,{level,set}}
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* front=q.front().first;
            int v=q.front().second.first;
            int l=q.front().second.second;
            q.pop();

            map[v][l].insert(front->val);
            // left child
            if(front->left) q.push({front->left,{v-1,l+1}});
            // right child
            if(front->right) q.push({front->right,{v+1,l+1}});

        }

        vector<vector<int>> ans;
        //{vertical,{level,set}}

        for(auto it:map){
            vector<int> v;
            for(auto it1:it.second){
                for(auto ele:it1.second){
                    v.push_back(ele);
                }
            }
            ans.push_back(v);
        }
        return ans;




    }  
};
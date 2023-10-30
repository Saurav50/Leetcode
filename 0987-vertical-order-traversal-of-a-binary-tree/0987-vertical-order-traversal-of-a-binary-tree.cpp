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
template <typename A,typename B>
class TemplatePair{
    public:
    A first;
    B second;
    TemplatePair() {};
    TemplatePair(A first,B second){
        this->first=first;
        this->second=second;
    };

};


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> res;
    queue<TemplatePair<TreeNode*, TemplatePair<int, int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        TreeNode *node = q.front().first;
        TemplatePair<int,int> pos = q.front().second;
        q.pop();
        res[pos.first][pos.second].insert(node->val);
        if(node->left) q.push({node->left,{pos.first-1,pos.second+1}});
        if(node->right) q.push({node->right,{pos.first+1,pos.second+1}});

    }
    vector<vector<int>> final;
    for(auto p:res){
        vector<int> v;
        for(auto pp:p.second){
            multiset<int>::iterator it=pp.second.begin(),end=pp.second.end();
            while (it != end){
                v.push_back(*it);
                ++it;

            }

        }
        final.push_back(v);

    }
    return final;
        
    }
};
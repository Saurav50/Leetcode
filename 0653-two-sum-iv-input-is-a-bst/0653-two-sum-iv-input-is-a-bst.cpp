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
    
    template <typename X, typename Y>
    class Pair{
        public:
        X x;
        Y y;
        Pair(X x,Y y){
            this->x = x;
            this->y = y;
        }
    };

    void addNodesToVector(TreeNode* root,vector<TreeNode*>& v){
        if(root == NULL){
            return ;
        }
        v.push_back(root);
        addNodesToVector(root->left,v);
        addNodesToVector(root->right,v);

    }

   static bool compareNodes(TreeNode* a, TreeNode* b) {
        return a->val< b->val;
    }

    // 2
    bool PairSum2(TreeNode* root,int k){
        vector<TreeNode*> vec;
        addNodesToVector(root,vec);
        // Sort the vector of nodes based on data values
        sort(vec.begin(), vec.end(), compareNodes);
        int i=0;
        int j=vec.size()-1;
        while(i<j){
            if(vec[i]->val + vec[j]->val == k){
                return true;
                i++;
                j--;
            }
            else if(vec[i]->val + vec[j]->val < k){
                i++;

            }
            else{
                j--;
            }


        }
        return false;
    }

    bool findTarget(TreeNode* root, int k) {
        return PairSum2(root,k);
        
        
    }
};
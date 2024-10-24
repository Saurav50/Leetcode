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
    vector<int> helper(TreeNode* root,int &maxi){
        if(!root) return {0,INT_MAX,INT_MIN};
        // if( root->left==NULL && root->right==NULL ){
        //     maxi=max(maxi,root->val);
        //     // cout<<"maxi: "<<maxi<<endl;
        //     return {root->val,root->val,root->val};
        // }
        vector<int> left=helper(root->left,maxi);
        vector<int> right=helper(root->right,maxi);
        //  // Print the left and right vectors for debugging
        // cout << "Node: " << root->val << std::endl;
        // cout << "Left: ";
        // for (int x : left) std::cout << x << " ";
        // cout << std::endl;

        // cout << "Right: ";
        // for (int x : right) std::cout << x << " ";
        // cout << std::endl;
        if(left[2]<root->val&&root->val<right[1]){
            int rootMax=max(root->val,right[2]);
            int rootMin=min(root->val,left[1]);
            int sum=left[0]+right[0]+root->val;
            maxi=max(maxi,sum);
            // cout<<"maxi"<<maxi<<endl;
            return {sum,rootMin,rootMax};
        }
        
        return {max(left[0],right[0]),INT_MIN,INT_MAX};
    }
    int maxSumBST(TreeNode* root) {
        int maxi=0;
        vector<int> ans=helper(root,maxi);
        
        return max(maxi,ans[0]);
      
    }
};
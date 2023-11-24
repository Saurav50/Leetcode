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
    
    
    TreeNode* constructBstHelper(vector<int>& arr,int start,int end){
         if (start > end) {
            return NULL; // Base case: empty subtree
        }
        int mid=(start+end)/2;
        TreeNode* root= new TreeNode(arr[mid]);

        root->left = constructBstHelper(arr,start,mid-1);
        root->right=constructBstHelper(arr,mid+1,end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.size() <= 0) {
        return NULL;
    }
    return constructBstHelper(nums, 0, nums.size()- 1);
        
    }
};
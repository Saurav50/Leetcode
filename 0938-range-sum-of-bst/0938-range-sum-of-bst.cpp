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
    void rangeSumBSTHelper(TreeNode* root, int k1, int k2,int &sum) {
     
        if (root == NULL) return ;

        // If current node's data is greater than k1, explore the left subtree
        if (root->val > k1) {
            rangeSumBSTHelper(root->left, k1, k2,sum);
        }

        // If current node's data is in the range, print it
        if (root->val >= k1 && root->val <= k2) {
            sum+=root->val;
        }

        // If current node's data is less than k2, explore the right subtree
        if (root->val < k2) {
            rangeSumBSTHelper(root->right, k1, k2,sum);
        }
    
    }
    int rangeSumBST(TreeNode* root,int low,int high){
        int sum=0;
        rangeSumBSTHelper(root,low,high,sum);
        return sum;
    }
};

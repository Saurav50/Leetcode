/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        s+=to_string(root->val)+',';
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front->left){
                s+=to_string(front->left->val)+',';
                q.push(front->left);
            }else s=s+"#"+",";
            if(front->right){
                s+=to_string(front->right->val)+',';
                q.push(front->right);
            }else s=s+"#"+",";
        }
    
        // Remove the trailing comma
        if (!s.empty()) {
            s.pop_back();
        }
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        cout<<data<<endl;
        vector<string> nums;
        stringstream ss(data);
        string token;
        // Split by the delimiter
        while (getline(ss, token,',')) {
            nums.push_back(token);
        }
        for(const auto& v:nums){
            cout<<v<<" ";
        }

        int i=0;
        queue<TreeNode*> q;
        TreeNode* root=new TreeNode(stoi(nums[i++]));
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            //getting left child
            if(nums[i]!="#"){
                front->left=new TreeNode(stoi(nums[i++]));
                q.push(front->left);
            }else i++;
            //getting right child
            if(nums[i]!="#"){
                front->right=new TreeNode(stoi(nums[i++]));
                q.push(front->right);
            }else i++;
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
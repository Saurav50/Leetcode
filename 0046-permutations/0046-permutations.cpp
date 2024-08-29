class Solution {
public:
    void permuteCall(vector<int>& nums,vector<int> &v,vector<vector<int>>& ans){
        if(nums.size()<1){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            // index i is my starting 
            v.push_back(nums[i]);
            int num = nums[i];
            nums.erase(nums.begin()+i);
            permuteCall(nums,v,ans);
            // re store nums
            nums.insert(nums.begin() + i, num);
            v.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        permuteCall(nums,v,ans);
        return ans;
    }
};
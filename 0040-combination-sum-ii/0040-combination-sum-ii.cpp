class Solution {
public:
  void subsetsCall(int idx, int n, int sum,vector<int>& sub, vector<int>& nums, set<vector<int>>& res,int target) {
        // Base case: 
        if(sum>target) return;
        if (sum == target) {
            // sort(sub.begin(),sub.end());
            res.insert(sub);
            return;
        }
         if (idx == n) {
            return;
        }
        
        
        // Include the current element at index `idx`
        sum+=nums[idx];
        sub.push_back(nums[idx]);
       
        subsetsCall(idx + 1, n, sum,sub, nums, res,target);
        // Exclude the current element and backtrack
        sum-=nums[idx];
        sub.pop_back();
        while (idx + 1 < n && nums[idx] == nums[idx + 1]) {
            idx++;
        }
        subsetsCall(idx + 1, n,sum, sub, nums, res,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         sort(candidates.begin(), candidates.end());
        set<vector<int>> res;
        vector<int> sub;
        int sum=0;
        vector<vector<int>> ans;
        subsetsCall(0, candidates.size(),sum, sub,candidates, res,target);
        for (const auto& subset : res) {
            ans.push_back(subset);
        }
        
        return ans;
    }
};
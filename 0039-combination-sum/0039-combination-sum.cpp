class Solution {
public:
  void subsetsCall(int idx, int n, int sum,vector<int>& sub, vector<int>& nums, set<vector<int>>& res,int target) {
        // Base case: If idx is equal to n, add the current subset to the result
        if(sum>target) return;
        if (sum == target) {
            res.insert(sub);
            return;
        }
         if (idx == n) {
            return;
        }
        
        
        // Include the current element at index `idx`
        sum+=nums[idx];
        sub.push_back(nums[idx]);
        subsetsCall(idx, n, sum,sub, nums, res,target);
        subsetsCall(idx + 1, n, sum,sub, nums, res,target);
        // Exclude the current element and backtrack
        sum-=nums[idx];
        sub.pop_back();
        subsetsCall(idx + 1, n,sum, sub, nums, res,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
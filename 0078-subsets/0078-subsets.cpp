class Solution {
public:
    void subsetsCall(int idx, int n, vector<int>& sub, vector<int>& nums, vector<vector<int>>& res) {
        // Base case: If idx is equal to n, add the current subset to the result
        if (idx == n) {
            res.push_back(sub);
            return;
        }
        
        // Include the current element at index `idx`
        sub.push_back(nums[idx]);
        subsetsCall(idx + 1, n, sub, nums, res);

        // Exclude the current element and backtrack
        sub.pop_back();
        subsetsCall(idx + 1, n, sub, nums, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        subsetsCall(0, nums.size(), sub, nums, res);
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sol;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if(mp.find(rem)!=mp.end()){
                sol.push_back(mp[rem]);
                sol.push_back(i);
                return sol;
            }
            mp[nums[i]]=i;
        }
        sol.push_back(-1);
        sol.push_back(-1);
        return sol;
        
    }
};
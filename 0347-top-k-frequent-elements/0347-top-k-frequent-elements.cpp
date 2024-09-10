class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minH;
        for(auto i:map){
            minH.push({i.second,i.first});
            if(minH.size()>k) minH.pop();
        }
        while(minH.size()>0){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};
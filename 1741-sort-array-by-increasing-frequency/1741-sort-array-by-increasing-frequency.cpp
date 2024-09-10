
class Compare {
public:
    bool operator()(pair<int,int>below, pair<int,int> above)
    {
        if (below.first > above.first) {
            return true;
        }
        else if (below.first == above.first
                 && below.second < above.second) {
            return true;
        }

        return false;
    }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> minH;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto i:map){
            minH.push({i.second,i.first});
        }
        vector<int> ans;
        while(minH.size()>0){
            int c=minH.top().first;
            while(c>0){
                ans.push_back(minH.top().second);
                c--;
            }
            
            minH.pop();
        }
        return ans;
    }
};
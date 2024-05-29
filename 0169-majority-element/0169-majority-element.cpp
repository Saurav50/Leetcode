class Solution {
public:
    // int majorityElement(vector<int>& nums) {
    //     map<int,int> mp;
    //     for(int i=0;i<nums.size();i++){
    //         mp[nums[i]]++;
    //     }
    //    for (auto i = mp.begin(); i != mp.end(); i++) {
    //        if(i->second>nums.size()/2) return i->first;
    //    }
    //     return -1;
    // }
    int majorityElement(vector<int>&nums){
        int el=-1;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                el=nums[i];
                c=1;
            }else if(nums[i]==el){
                c++;
            }else c--;
        }
        return el;
    }
};
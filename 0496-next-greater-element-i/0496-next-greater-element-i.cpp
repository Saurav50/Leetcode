class Solution {
public:
   
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> map;
        stack<int> s;
        for(int j=nums2.size()-1;j>=0;j--){
          while(!s.empty()&&s.top()<nums2[j]) s.pop();
          if(s.empty()) map[nums2[j]]=-1;
          else map[nums2[j]]=s.top();
          s.push(nums2[j]);
        }


        
        for(int i=0;i<nums1.size();i++){

            ans.push_back(map[nums1[i]]);
        }
        return ans;
        

    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i=0,j=0,n=nums.size();
        vector<int> ans;
        while(j<n){
            if(dq.empty()) dq.push_back(nums[j]);
            else{
                while(!dq.empty()&&dq.back()<nums[j]){
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
            }
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[i]) dq.pop_front();
                i++,j++;
            }
        }
             return ans;
        
    }
};
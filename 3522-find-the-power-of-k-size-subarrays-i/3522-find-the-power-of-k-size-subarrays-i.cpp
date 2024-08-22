class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int i=0,j=0,n=nums.size();
        bool isConsecutive=true;
        int idx=-1;
        while(j<n){
            while(!dq.empty()&&dq.back()<nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if(j-i+1<k) {
                if(j!=i&&nums[j]!=nums[j-1]+1) isConsecutive=false,idx=j;
                j++;
            }
            else if(j-i+1==k){
                if(j!=i&&nums[j]!=nums[j-1]+1)isConsecutive=false,idx=j;
                if(!dq.empty()&&isConsecutive){
                    ans.push_back(dq.front());
                } else ans.push_back(-1);
                
                if(dq.front()==nums[i]) dq.pop_front();
                i++,j++;
                if (idx > i ) {
                    // If idx is within the current window, do not reset isConsecutive
                } else {
                    isConsecutive = true;  // Reset isConsecutive when sliding window
                }
            }

        }
        return ans;
        
    }
};
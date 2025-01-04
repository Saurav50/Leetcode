class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        int sum=0;
        int maxS=INT_MIN;
        while(j<n){
            sum+=nums[j];
            maxS=max(maxS,sum);
            if(sum<=0){
                sum=0;
            }
            
            
            j++;
        }
        return maxS;
    }
};
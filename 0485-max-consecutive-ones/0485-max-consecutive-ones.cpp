class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m=INT_MIN;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) c++;
            else{
                m=max(m,c);
                c=0;
            }
        }
        return max(m,c);
        
    }
};
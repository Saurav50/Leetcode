class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double pP=1,sP=1,maxP=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            
            pP*=nums[i];
            sP*=nums[n-i-1];
            maxP=max(maxP,max(pP,sP));
            if(pP==0) pP=1;
             if(sP==0) sP=1;
            
        }
        return maxP;
        
    }
};
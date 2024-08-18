class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int i=0,j=0;
        int n=nums.size();
        int product=1; 
        int c=0;
        while(j<n){
            if(product>INT_MAX/nums[j]){
                while(product>=k&&i<=j){
                    product/=nums[i];
                    i++;
                }
            }else{
                    product*=nums[j];
            }
            
            
            
            
            if(product<k) c+=j-i+1,j++;
            else{
     
                while(product>=k&&i<=j){
                    product/=nums[i];
                    i++;
                }
                if(product<k) c+=j-i+1;
                j++;

            }
        }
        return c;
        
    }
};
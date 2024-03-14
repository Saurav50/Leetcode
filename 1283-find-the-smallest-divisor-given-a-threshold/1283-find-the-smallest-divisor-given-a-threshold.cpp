class Solution {
public:
    
    int divisorPossible(vector<int>& nums,int d, int t){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)(nums[i]) / (double)(d));;
        }
        return sum<=t;
    }
    
    int maxArr(vector<int>&arr){
        int max=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
    

    
    int smallestDivisor(vector<int>& nums, int threshold) {
        if (nums.size() > threshold) return -1;
        int i=1;
        int j=maxArr(nums);
        while(i<=j){
            int mid=(i+j)/2;
            bool midPossible=divisorPossible(nums,mid,threshold);
            if(midPossible) j=mid-1;
            else i=mid+1;
        }
        return i;
        
        
    }
};
class Solution {
public:
    
    
    int maxArr(vector<int>&arr){
        int max=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max) max=arr[i];
        }
        return max;
    }
    int sumArr(vector<int>&arr){
        int s=0;
          for(int i=0;i<arr.size();i++){
            s+=arr[i];
        }
        return s;
    }
    int cPartitions(vector<int>&nums,int maxSumOfSubArray){
        int numSubArrays=1,currentSum=0;
        for(int i=0;i<nums.size();i++){
            if(currentSum+nums[i]<=maxSumOfSubArray){
                currentSum+=nums[i];
            }
            else{
                numSubArrays++;
                currentSum=nums[i];
            }
        }
        return numSubArrays;
    }
    int splitArray(vector<int>& nums, int k) {
        int i=maxArr(nums);
        int j=sumArr(nums);
        while(i<=j){
            int mid=(i+j)/2;
            int countPartitions=cPartitions(nums,mid);
            if(countPartitions>k) i=mid+1;
            else j=mid-1;
        }
        return i;
        
    }
};
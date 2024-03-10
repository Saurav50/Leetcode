class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int i=1,j=n-2;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if(nums[mid]>nums[mid-1]) i=mid+1;
            else if(nums[mid]>nums[mid+1]) j=mid-1;
            else i= mid+1;
        }
        return -1;
        
    }
  
    // Brute force approach
//     int findPeakElement(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return 0;
//         if(nums[0]>nums[1]) return 0;
//         if(nums[n-1]>nums[n-2]) return n-1;
//         for(int i=1;i<n-1;i++){
//             if(nums[i]>nums[i-1]&&nums[i]>nums[i+1]){
//                 return i;
//             }
//         }
        
//         return -1;
//     }
};
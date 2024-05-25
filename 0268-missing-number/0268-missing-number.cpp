class Solution {
public:
//     int missingNumber(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<=n;i++){
//             bool check=false;
//             for(int j=0;j<n;j++){
//                 if(nums[j]==i) {
//                     check=true;
//                     continue;
//                 }
//             }
//             if(check==false) return i;
//         }
//           return -1; 
    
//     }
//     optimal sol
    int missingNumber(vector<int>& nums){
        int n=nums.size();
        int ArraySum=0;
        for(int i=0;i<n;i++) ArraySum+=nums[i];
        int originalSum=n*(n+1)/2;
        return originalSum-ArraySum;
    }
};
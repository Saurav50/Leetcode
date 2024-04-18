class Solution {
public:
    // int findMin(vector<int>& nums) {
    //     int i=0,j=nums.size()-1;
    //     int ans=INT_MAX;
    //     while(i<=j){
    //         int mid=(i+j)/2;
    //         if(nums[mid]<ans){
    //             ans=nums[mid];
    //         }
    //         if(nums[i]<=nums[mid]){
    //             if(nums[i]<ans){
    //                 ans=nums[i];
    //             }else{
    //                 i=mid+1;
    //             }
    //         }else{
    //             if(nums[mid+1]<ans){
    //                 ans=nums[mid+1];
    //             }else{
    //                 j=mid-1;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int ans=INT_MAX;
        while(i<=j){
            int mid=(i+j)/2;
            
            if(nums[i]<=nums[mid]){
                if(nums[i]<ans)
                    ans=nums[i];
                i=mid+1;
            }else{
                if(nums[mid]<ans)
                    ans=nums[mid];
                    j=mid-1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int lowerBound(vector<int>& nums,int i,int j,int target){
        int ans=j+1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
    int searchInsert(vector<int>& nums, int target) {
        return lowerBound(nums,0,nums.size()-1,target);
        
        
    }
};
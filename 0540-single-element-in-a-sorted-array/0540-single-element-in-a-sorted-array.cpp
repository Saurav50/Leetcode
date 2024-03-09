class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=1,j=nums.size()-2;
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[j+1]!=nums[j]) return nums[j+1];
        
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(
                ( (mid%2==1) && (nums[mid]==nums[mid-1]) ) ||                                       ( (mid%2==0) && (nums[mid]==nums[mid+1]) )
            ){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return -1;
        
    }
};
class Solution {
public:
    int BinarySearch(vector<int>& nums,int i,int j, int target){
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target) return mid;
            else if(target<nums[mid]){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        return BinarySearch(nums,0,nums.size()-1,target);
    }
};
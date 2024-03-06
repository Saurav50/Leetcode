class Solution {
public:
    
    vector<int> rangeFinder(vector<int>& nums,int n,int target){
        vector<int> ans;
         if(n==0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        
        int lowerBound=n,upperBound=n;
        int i=0,j=n-1;
        while(i<=j){
              int mid=(i+j)/2;
              if(nums[mid]>=target) {
                  lowerBound=mid;
                  j=mid-1;
                  
              }else{
                  i=mid+1;
              }
        }
        if(lowerBound==n || nums[lowerBound]!=target ){ 
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }else{
            i=0,j=n-1;
            while(i<=j){
                  int mid=(i+j)/2;
                  if(nums[mid]>target) {
                      upperBound=mid;
                      j=mid-1;

                  }else{
                      i=mid+1;
                  }
            }
            ans.push_back(lowerBound);
            ans.push_back(upperBound-1);
            return ans;
        }
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return rangeFinder(nums,nums.size(),target);
         
    }
};
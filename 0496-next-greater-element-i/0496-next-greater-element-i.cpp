class Solution {
public:
    int findNextGreater(vector<int>&arr,int k){
        int g=-1;
        int i=0;
        while(arr[i]!=k){
            i++;
        }
        for( int j=i+1;j<arr.size();j++){
            if(arr[j]>k){
                 g=arr[j];
                 break;
            }
        }
        return g;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int temp=findNextGreater(nums2,nums1[i]);
            ans.push_back(temp);
        }
        return ans;
        

    }
};
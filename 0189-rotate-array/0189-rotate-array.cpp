class Solution {
public:
//     void rotate(vector<int>& nums, int k) {
//         for(int i=0;i<k;i++){
//             int last=nums[nums.size()-1];
//             for(int j=nums.size()-2;j>=0;j--){
//                 nums[j+1]=nums[j];
//             }
//             nums[0]=last;
            
//         }
        
//     }
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1) return;
        vector<int> res;
        int n=nums.size();
        k %= n; // Take the modulus to handle cases where k is greater than n
        for(int j=n-k;j<n;j++){
            res.push_back(nums[j]);
        }
        for(int i=0;i<n-k;i++){
            res.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            nums[i]=res[i];
        }
        
    }
};
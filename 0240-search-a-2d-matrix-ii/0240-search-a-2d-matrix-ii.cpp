class Solution {
public:
     bool checkPresent(vector<int>&arr,int target){
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(arr[mid]==target) return true;
            if(target<arr[mid]) j=mid-1;
            else i=mid+1;
        }
        return false;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
                bool check=checkPresent(matrix[i],target);
                if(check) return check;
          
        }
        return false;
    }
};
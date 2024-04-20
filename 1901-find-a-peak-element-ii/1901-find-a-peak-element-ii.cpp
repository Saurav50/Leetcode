class Solution {
public:
    int  maxInCol(vector<vector<int>>&mat,int col){
        int max=INT_MIN;
        int maxIdx=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>max){
                max=mat[i][col];
                maxIdx=i;
            }
        }
        return maxIdx;
        
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int i=0;
        int j=mat[0].size()-1;
        while(i<=j){
            int mid=(i+j)/2;
        // check for the max element in the col-mid
            int maxIdx=maxInCol(mat,mid);
        // check for peak element properties
            if(
                ( mid==0 || mat[maxIdx][mid]>mat[maxIdx][mid-1] )
                &&
                ( mid==mat[0].size()-1 || mat[maxIdx][mid]>mat[maxIdx][mid+1])
            ) {
                return {maxIdx,mid};
            }
            if(mat[maxIdx][mid]<(mid-1>=0?mat[maxIdx][mid-1]:-1)) j=mid-1;
            else i=mid+1;
            
        }
        return {-1,-1};
    }
};
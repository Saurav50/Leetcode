class Solution {
public:
    bool possible(vector<int>&bloomDay,int day,int m,int k){
        int c=0,noOfBouquets=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                c++;
            }else{
                noOfBouquets+=c/k;
                c=0;
            }
        }
        noOfBouquets+=c/k;
        if(noOfBouquets>=m) return true;
        else{
            return false;
        }
        
    }
    int maxArr(vector<int>&arr){
        int max=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
    int minArr(vector<int>&arr){
        int min=INT_MAX;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]<min){
                min=arr[i];
            }
        }
        return min;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        int n = bloomDay.size(); //size of the array
        if (val > n) return -1; //impossible case.
        
        int i=minArr(bloomDay);
        int j=maxArr(bloomDay);
        while(i<=j){
            int mid=(i+j)/2;
            int possibleMid=possible(bloomDay,mid,m,k);
            if(possibleMid){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return i;
    }
};
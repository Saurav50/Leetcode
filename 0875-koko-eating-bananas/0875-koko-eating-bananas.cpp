class Solution {
public:
    double calTime(vector<int>& piles,int k){
        double time=0;
        for(int i=0;i<piles.size();i++){
            time+= ceil(double(piles[i])/double(k)); 
        }
        return time;
    }
    int maxArr(vector<int>&piles){
        int max=INT_MIN;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>max) max=piles[i];
        }
        return max;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int max=maxArr(piles);
        int i=1;
        while(i<=max){
            int mid=(i+max)/2;
            double time=calTime(piles,mid);
            if(time<=double(h)){
                max=mid-1;
            }else i=mid+1;
        }
        return i;
    }
};
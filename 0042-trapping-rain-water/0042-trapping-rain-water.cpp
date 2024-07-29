class Solution {
public:
    int calMax(vector<int>& arr,int i,int j){
        int max=0;
        while(i<=j){
            if(arr[i]>max) max=arr[i];
            i++;
        }
        return max;
    }
    int trap(vector<int>& height) {
        int sum=0;
        int n=height.size();
        vector<int> preMax(n);
        vector<int> sufMax(n);
        int pMax=INT_MIN;
        for(int i=0;i<height.size();i++){
            if(height[i]>pMax) {
                pMax=height[i];
                preMax[i]=pMax;
            }else  preMax[i]=pMax;
        }
        int sMax=INT_MIN;
        for(int i=height.size()-1;i>=0;i--){
            if(height[i]>sMax){
                sMax=height[i];
                sufMax[i]=sMax;
            }else  sufMax[i]=sMax;
        }
   
        for(int i=0;i<height.size();i++){
            int leftMax=preMax[i];
            int rightMax=sufMax[i];
            sum+=min(leftMax,rightMax)-height[i];
            
        }
        return sum;
    }
};
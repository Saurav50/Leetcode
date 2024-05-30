class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxProfit=0;
        int minP=INT_MAX;
        for(int i=0;i<prices.size();i++){
            maxProfit=max(maxProfit,prices[i]-minP);
            minP=min(minP,prices[i]);
        }
        return maxProfit;
        
        
    }
};
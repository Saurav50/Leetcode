class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> s;
        int n=heights.size();
        int maxAr=0;
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top().first>=heights[i]){
                int nse=i;
                int h=s.top().first;
                s.pop();
                int pse=s.empty()?-1:s.top().second;
                int ar=h*(nse-pse-1);
                maxAr=max(maxAr,ar);
            }

            s.push({heights[i],i});
        }
        while(!s.empty()){
            int nse=n;
                int h=s.top().first;
                s.pop();
                int pse=s.empty()?-1:s.top().second;
                int ar=h*(nse-pse-1);
                maxAr=max(maxAr,ar);
        }

        return maxAr;


        
    }
};
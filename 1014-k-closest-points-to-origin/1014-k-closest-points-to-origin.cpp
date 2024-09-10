class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxH;
        for(int i=0;i<points.size();i++){
            int dist=pow(points[i][0],2)+pow(points[i][1],2);
            maxH.push({dist,points[i]});
            if(maxH.size()>k) maxH.pop();
        }
        vector<vector<int>> ans;
        while(maxH.size()>0){
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        return ans;

        
    }
};
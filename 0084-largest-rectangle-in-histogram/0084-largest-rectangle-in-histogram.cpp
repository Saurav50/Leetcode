class Solution {
public:
    vector<int> pseCal(vector<int>& arr){
        vector<int> ans;
        stack<pair<int,int>> s;
        for(int i=0;i<arr.size();i++){
            while(!s.empty()&&s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top().second);
            pair<int,int> p={arr[i],i};
            s.push(p);
        }
        return ans;
    }
    vector<int> nseCal(vector<int>& arr){
        vector<int> ans;
        stack<pair<int,int>> s;
        for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty()&&s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty()) ans.push_back(arr.size());
            else ans.push_back(s.top().second);
            pair<int,int> p={arr[i],i};
            s.push(p);
        }
                return ans;

    }
    int largestRectangleArea(vector<int>& heights) {

        vector<int> pse=pseCal(heights);
        vector<int> nse=nseCal(heights);
        int maxAr=0;
        for(int i=0;i<heights.size();i++){
            int ar=heights[i]*(nse[heights.size()-i-1]-pse[i]-1);
            cout<<ar<<" ";
            maxAr=max(maxAr,ar);
        }
        return maxAr;
        
        
    }
};
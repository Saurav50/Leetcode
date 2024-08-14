class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](vector<int> a, vector<int> b) {
                return a[1] < b[1];
    });
        int c=1;
        int lastT=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>lastT){
                c++;
                lastT=pairs[i][1];
            }
        }
        return c;

        
    }
};
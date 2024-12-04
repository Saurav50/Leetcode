class Solution {
    bool check(vector<vector<int>>& graph,int start,vector<int>& colored){
        colored[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // traverse neighbors
            for(auto const& it:graph[node]){
                if(colored[it]==-1){
                    colored[it]=!colored[node];
                    q.push(it);
                }
                else if(colored[it]==colored[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colored(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(colored[i]==-1){
                if(!check(graph,i,colored)){
                    return false;
                }
            }
        }
        return true;


    }
};
class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited,vector<int>& tin,vector<int>& lowt,int time,vector<vector<int>>& ans,int parent){
        visited[node]=1;
        tin[node]=time;
        lowt[node]=time;
        for(auto it:adj[node]){
            //skip for parent
            if (it == parent) continue;
            if(!visited[it]) dfs(it,adj,visited,tin,lowt,time+1,ans,node);
            // update minimum
            lowt[node]=min(lowt[node],lowt[it]);
            // try to remove edge b/w node and its adjacent node
            if(lowt[it]<=tin[node]) continue; //not brirdge
            else {
                //it's a brdige, add to ans list
                ans.push_back({node,it});
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> tin(n,-1);
        vector<int> lowt(n,-1);
        vector<vector<int>> adj(n);
        for(auto& it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> visited(n,0);
        vector<vector<int>> ans;
        dfs(0, adj, visited, tin, lowt, 0, ans,-1);
         
        return ans;



        
    }
};
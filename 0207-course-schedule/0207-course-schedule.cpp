class Solution {
public:
    void bfs(queue<int>& q,vector<int> &ans,vector<int>& indegree,vector<vector<int>>& adj){
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    ans.push_back(node);
                    for(auto const& it:adj[node]){
                        indegree[it]--;
                        if(indegree[it]==0) q.push(it);
                    }
                }
                
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
            // Your code here
            int n=adj.size();
            vector<int> indegree(n,0);
            for(int i=0;i<n;i++){
                for(auto const& it:adj[i]){
                    indegree[it]++;
                }
            }
            queue<int> q;
            for(int i=0;i<n;i++){
                if(indegree[i]==0) q.push(i);
            }
            vector<int> ans;
            bfs(q,ans,indegree,adj);
            return ans;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto const& i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }

         vector<int> c=topologicalSort(adj);
         return c.size() == numCourses;
    }
};
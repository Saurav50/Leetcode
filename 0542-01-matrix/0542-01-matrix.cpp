class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> distance(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int d=q.front().second;
            distance[row][col]=d;
            q.pop();
            // move in all four direction
            int r[]={-1,0,+1,0};
            int c[]={0,-1,0,+1};
            for(int k=0;k<4;k++){
                int newR=row+r[k];
                int newC=col+c[k];
                if(newR >= 0 && newR < m && newC >= 0 && newC < n&& mat[newR][newC]==1&&visited[newR][newC]!=1){
                    // visit it
                    q.push({{newR,newC},d+1});
                    visited[newR][newC]=1;
                }
            }
        }
        return distance;
    }
};
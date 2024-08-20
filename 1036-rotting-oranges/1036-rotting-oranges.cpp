class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int vis[m][n];
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                     vis[i][j]=0;
                }
                if(grid[i][j]==1) cnt++;
            
            }
        }
        int tm=0;
        int c1=0;
        int delR[]={-1,0,1,0};
        int delC[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++){
                int r=row+delR[i];
                int c=col+delC[i];
                if(r>=0&&r<m&&c>=0&&c<n&&grid[r][c]==1&&vis[r][c]!=2){
                    q.push({{r,c},t+1});
                    vis[r][c]=2;
                    c1++;
                }

            }

        }

        if(c1==cnt) return tm;
        else return -1;
        
    }
};
class Solution {
public:
   void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visited){

        visited[i][j]=1;
        
        //all directions check
        // Directions for moving in the grid (up, down, left, right)
        vector<int> dirX = {-1, 1, 0, 0}; // Row adjustments
        vector<int> dirY = {0, 0, -1, 1}; // Column adjustments

        // Traverse in all 4 directions
        for (int k = 0; k < 4; ++k) {
            int newX = i + dirX[k];
            int newY = j + dirY[k];

            // Check if the new position is within bounds and not yet visited
            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && 
                !visited[newX][newY] && grid[newX][newY] == '1') {
                dfs(newX, newY, grid, visited); // Recurse
            }
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j] == '1'){
                    c++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return c;
        
    }
};
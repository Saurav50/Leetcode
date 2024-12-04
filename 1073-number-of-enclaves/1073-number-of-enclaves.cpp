class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // First row
        for (int i = 0; i < n; i++) {
            if (grid[0][i] == 1) {
                visited[0][i] = 1;
                q.push({0, i});
            }
        }

        // Last row
        for (int i = 0; i < n; i++) {
            if (grid[m - 1][i] == 1) {
                visited[m - 1][i] = 1;
                q.push({m - 1, i});
            }
        }

        // Left column
        for (int i = 1; i < m - 1; i++) {
            if (grid[i][0] == 1) {
                visited[i][0] = 1;
                q.push({i, 0});
            }
        }

        // Right column
        for (int i = 1; i < m - 1; i++) {
            if (grid[i][n - 1] == 1) {
                visited[i][n - 1] = 1;
                q.push({i, n - 1});
            }
        }
        int c=0;
        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Mark the current cell as visited (we'll use a temporary placeholder 'Q')
            c++;

            // Move in all four directions
            int r[] = {-1, 0, 1, 0};
            int c[] = {0, -1, 0, 1};

            for (int k = 0; k < 4; k++) {
                int newR = row + r[k];
                int newC = col + c[k];

                if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == 1 && visited[newR][newC] != 1) {
                    visited[newR][newC] = 1;
                    q.push({newR, newC});
                }
            }
        }

        // Final board update
        int t=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1) t++;
            }
        }
        return t-c>0? t-c:0;

    }
    
};
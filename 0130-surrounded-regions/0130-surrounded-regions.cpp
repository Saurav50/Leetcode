class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        // First row
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                visited[0][i] = 1;
                q.push({0, i});
            }
        }

        // Last row
        for (int i = 0; i < n; i++) {
            if (board[m - 1][i] == 'O') {
                visited[m - 1][i] = 1;
                q.push({m - 1, i});
            }
        }

        // Left column
        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O') {
                visited[i][0] = 1;
                q.push({i, 0});
            }
        }

        // Right column
        for (int i = 1; i < m - 1; i++) {
            if (board[i][n - 1] == 'O') {
                visited[i][n - 1] = 1;
                q.push({i, n - 1});
            }
        }

        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Mark the current cell as visited (we'll use a temporary placeholder 'Q')
            board[row][col] = 'Q';

            // Move in all four directions
            int r[] = {-1, 0, 1, 0};
            int c[] = {0, -1, 0, 1};

            for (int k = 0; k < 4; k++) {
                int newR = row + r[k];
                int newC = col + c[k];

                if (newR >= 0 && newR < m && newC >= 0 && newC < n && board[newR][newC] == 'O' && visited[newR][newC] != 1) {
                    visited[newR][newC] = 1;
                    q.push({newR, newC});
                }
            }
        }

        // Final board update
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Q') {
                    board[i][j] = 'O';  // 'Q' is a valid 'O' connected to border
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // 'O' is surrounded, change to 'X'
                }
            }
        }
    }
};

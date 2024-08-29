class Solution {
public:

    bool checkPossible(vector<string>& board, int row, int col, int n) {
        // Check the column for another queen
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false; // There is another queen in the same column
            }
        }

        // Check the left diagonal (top-left to bottom-right)
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false; // There is another queen in the left diagonal
            }
        }

        // Check the right diagonal (top-right to bottom-left)
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false; // There is another queen in the right diagonal
            }
        }

        return true; // It is safe to place the queen here
    }
    void solveNQueensCall(int n,int placed,vector<string>& v,vector<vector<string>>& ans){
        if(placed==n){
            ans.push_back(v);
            return;
        }
        for(int i=0;i<n;i++){
            bool isPossible=checkPossible(v,placed,i,n);
            if(isPossible){
                v[placed][i] = 'Q';
                solveNQueensCall(n,placed+1,v,ans);
                v[placed][i] = '.';
              
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n,string(n, '.'));
        vector<vector<string>> ans;
       
        solveNQueensCall(n,0,v,ans);
        return ans;
    }

};
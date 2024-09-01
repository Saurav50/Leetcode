class Solution {
public:
    bool isPossible(vector<vector<char>>& board,int i,int j,char c){
       
        for(int k=0;k<9;k++){
             // check for entire row
            if(board[i][k]==c) return false;
                // check for entire column
            if(board[k][j]==c) return false;
            // 3 x 3 check
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==c) return false; 
        }

    
       return true;
    }
    bool solveSudokuCall(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isPossible(board,i,j,c)){
                            board[i][j]=c;
                            if(solveSudokuCall(board)) return true;
                            board[i][j]='.';
                        }
                    }
                     return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board){
        solveSudokuCall(board);
    }
};
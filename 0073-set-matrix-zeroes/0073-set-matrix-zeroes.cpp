class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
//         vector<vector<int>> visited = matrix;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(matrix[i][j] == 0){
//                     for(int k=0; k<m; k++){
//                         visited[i][k] = 0;
//                     }
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(matrix[i][j] == 0){
//                     for(int k=0; k<n; k++){
//                         visited[k][j] = 0;
//                     }
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 matrix[i][j] = visited[i][j];
//             }
//         }
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
//                     set row to 0
                    matrix[i][0]=0;
//                     set col to zero
                    if(j!=0) matrix[0][j]=0;
                    else col0=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
               if(matrix[i][j]!=0){
                   if(matrix[i][0]==0||matrix[0][j]==0){
                       matrix[i][j]=0;
                   }
               }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++){
                if(matrix[0][j]!=0){
                    matrix[0][j]=0;
                }
            }
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                if(matrix[i][0]!=0){
                    matrix[i][0]=0;
                }
            }
        }
        
        
    }
};
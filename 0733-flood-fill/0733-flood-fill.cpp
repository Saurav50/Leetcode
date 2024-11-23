class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& img,int initColor,int color){
        if(img[x][y]==initColor){
            img[x][y]=color;
        }
        // Traverse in all 4 directions
        vector<int> dirX = {-1, 1, 0, 0}; // Row adjustments
        vector<int> dirY = {0, 0, -1, 1}; // Column adjustments

        for (int k = 0; k < 4; ++k) {
            int newX = x + dirX[k];
            int newY = y + dirY[k];

            // Check if the new position is within bounds 
            if (newX >= 0 && newX < img.size() && newY >= 0 && newY < img[0].size() &&img[newX][newY] == initColor) {
                dfs(newX, newY, img,initColor,color); // Recurse
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initColor=image[sr][sc];
        if(initColor==color) return image;
        dfs(sr,sc,image,initColor,color);
        return image;
        
    }
};
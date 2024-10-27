class Solution {
public:

    void dfs(vector<vector<int>>& image,int i,int j,int m,int n,int color,int initialColor){
        if(i>=m||j>=n||i<0||j<0||image[i][j]!=initialColor) return;
        image[i][j]=color;
        dfs(image,i,j+1,m,n,color,initialColor);
        dfs(image,i,j-1,m,n,color,initialColor);
        dfs(image,i+1,j,m,n,color,initialColor);
        dfs(image,i-1,j,m,n,color,initialColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int initialColor=image[sr][sc];
        if(color==initialColor) return image;
        //perform dfs
        dfs(image,sr,sc,m,n,color,initialColor);
        return image;
    }
};
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int delrow[], int delcol[], int inicolor) {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == inicolor && ans[nrow][ncol] != color)
                dfs(nrow, ncol, ans, image, color, delrow, delcol, inicolor);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicol = image[sr][sc];
        if (inicol == color) return image; // If the initial color is the same as the new color, return the original image
        vector<vector<int>> ans = image;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, color, delrow, delcol, inicol);
        return ans;
    }
};
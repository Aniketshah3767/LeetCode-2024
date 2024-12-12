class Solution {
private:
//     void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, int color, int inicolor, int delrow[], int delcol[]) {
//         int n = image.size();
//         int m = image[0].size();
//         ans[row][col] = color;
        
//         for (int i = 0; i < 4; i++) {
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];
//             if (nrow < n && ncol < m && ncol >= 0 && nrow >= 0 &&
//                 image[nrow][ncol] == inicolor && ans[nrow][ncol] != color ) {
//                 dfs(nrow, ncol, image, ans, color, inicolor,delrow, delcol);
//             }
//         }
//     }

// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
//         vector<vector<int>> ans = image;
//         int inicolor = image[sr][sc];
//         int delrow[] = {-1, 0, 1, 0};
//         int delcol[] = {0 ,1, 0, -1};
//         dfs(sr, sc, image, ans, color, inicolor, delrow, delcol);

//         return ans;
//     }
// };



public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int color) {
        int curr = image[sr][sc];
        if(curr == color)  return image;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]= color;

        vector<pair<int,int>>dir = {{-1,0},{0,1},{1,0},{0,-1}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto [dr,dc]: dir){
                int newr = row + dr;
                int newc = col + dc;

                if(newr >= 0 && newr < n && newc >= 0 && newc < m && image[newr][newc] == curr){
                    q.push({newr,newc});
                    image[newr][newc] = color;
                }
            }
        }
        return image;
    }
};
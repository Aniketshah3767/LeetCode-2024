class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();
        // vis[row][col] = 1;
        // queue<pair<int, int>> q;
        // q.push({row, col});

        // while (!q.empty()) {
        //     int row = q.front().first;
        //     int col = q.front().second;
        //     q.pop();

        //     int delrow[] = {-1, 0, 1, 0};
        //     int delcol[] = {0, 1, 0, -1};

        //     for (int i = 0; i < 4; i++) {
        //         int nrow = row + delrow[i];
        //         int ncol = col + delcol[i];

        //         if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
        //             grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
        //             vis[nrow][ncol] = 1;
        //             q.push({nrow, ncol});
        //         }
        //     }
        // }
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};

            for(int i = 0 ; i < 4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // int n = grid.size();
        // int count = 0;
        // int m = grid[0].size();
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        // for (int row = 0; row < n; row++) {
        //     for (int col = 0; col < m; col++) {
        //         if (!vis[row][col] && grid[row][col] == '1') {
        //             count++;
        //             bfs(row, col, vis, grid);
        //         }
        //     }
        // }
        // return count;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int row = 0; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }
};


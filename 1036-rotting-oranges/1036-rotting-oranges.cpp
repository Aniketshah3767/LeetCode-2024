class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0;
        while(!q.empty()){
            auto node = q.front();
            int row = node.first.first;
            int col = node.first.second;
            int time = node.second;
            tm = max(tm,time);
            q.pop();

            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};

            for(int i =0 ; i < 4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && ncol < m && nrow < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow,ncol}, time+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return tm;

    }
};
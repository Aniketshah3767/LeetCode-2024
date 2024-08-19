class Solution {

private:
    int bfs(vector<vector<int>>&grid, int r, int c,int &n , int &m){
        int result = 0;

        queue<pair<int,int>>q;
        grid[r][c] = -1;
        q.emplace(r,c);

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            result++;
            int delrow[] = {-1,0,1,0};
            int delcol[] = {0,1,0,-1};
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow < 0 || ncol < 0 || ncol >= m || nrow >= n || grid[nrow][ncol] != 1){
                    continue;
                }
                grid[nrow][ncol] = -1;
                q.emplace(nrow,ncol);
            }
        }
        return result;

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        int n= grid.size();
        int m = grid[0].size();
        for(int i = 0 ;  i< n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(grid[i][j] == 1)
                    result = max(result, bfs(grid,i,j,n,m));
            }
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        //first for storing coordinates and another for stroing distance.
        vector<vector<int>>vis(n,vector<int>(m,0));
        //for stoting answer
        vector<vector<int>>ans(n,vector<int>(m,0));

        for(int i = 0 ;  i < n ;i++){
            for(int j = 0 ; j < m ;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            q.pop();
            
            ans[row][col] = dist;

            for(int i = 0 ; i < 4 ;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow < n && ncol < m && ncol >= 0 && nrow >= 0 && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
        return ans;
    }
};
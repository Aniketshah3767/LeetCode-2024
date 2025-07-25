class Solution {

private:
    // int solve(int i , int j ,vector<vector<int>>temp,vector<vector<int>>&dp){
    //     if(i >= 0 && j >=0 && temp[i][j] == 1){
    //         return 0;
    //     }

    //     if( i == 0 && j == 0){
    //         return 1;
    //     }
    //     if(i < 0 || j < 0 ){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int left = solve(i-1,j,temp,dp);
    //     int up = solve(i,j-1,temp,dp);

    //     return  dp[i][j] = left + up;
    // }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,obstacleGrid,dp);
        int dp[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[n-1][m-1];
    }
};
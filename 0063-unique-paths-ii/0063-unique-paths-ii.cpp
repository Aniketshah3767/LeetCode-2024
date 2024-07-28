class Solution {
public:
    int mod = (int)(1e9+7);
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dp[n][m];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if( obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else if( i == 0 && j == 0){
                    dp[i][j] = 1;
                }
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];

                    dp[i][j] = (up + left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();
//         vector<vector<long long>> dp(n, vector<long long>(m, 0));
        
//         // If the starting cell has an obstacle, return 0
//         if (obstacleGrid[0][0] == 1) return 0;
        
//         // Initialize the first cell
//         dp[0][0] = 1;
        
//         // Fill first row
//         for (int j = 1; j < m; j++) {
//             if (obstacleGrid[0][j] == 0) {
//                 dp[0][j] = dp[0][j-1];
//             }
//         }
        
//         // Fill first column
//         for (int i = 1; i < n; i++) {
//             if (obstacleGrid[i][0] == 0) {
//                 dp[i][0] = dp[i-1][0];
//             }
//         }
        
//         // Fill rest of the dp table
//         for (int i = 1; i < n; i++) {
//             for (int j = 1; j < m; j++) {
//                 if (obstacleGrid[i][j] == 0) {
//                     dp[i][j] = dp[i-1][j] + dp[i][j-1];
//                 }
//             }
//         }
        
//         return dp[n-1][m-1];
//     }
// };
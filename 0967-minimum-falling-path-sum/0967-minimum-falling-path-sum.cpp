class Solution {
private:
    // int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp) {
    //     int m = matrix.size();
    //     if (j < 0 || j >= m)
    //         return 1e9;

    //     if (i == matrix.size()-1) {
    //         return matrix[i][j];
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int down = solve(i + 1, j, matrix,dp);
    //     int leftDiag = solve(i + 1, j - 1, matrix,dp);
    //     int rightDiag = solve(i + 1, j + 1, matrix,dp);

    //     return dp[i][j] = matrix[i][j] + min(down, min(leftDiag, rightDiag));
    // }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      
        // int n = matrix.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // int mini = INT_MAX;
        // for (int j = 0; j < m; j++) {
        //     mini = min(mini, solve(0, j, matrix,dp));
        // }
        // return mini;
        for(int j = 0 ; j < n ; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < n ;j++){
                int up = dp[i-1][j];
                
                int leftdiag = (j>0) ? dp[i-1][j-1] : INT_MAX;
                int rightdiag = (j < n-1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up,leftdiag,rightdiag});
            }
        }
        int mini = dp[n-1][0];
        for(int i = 0 ; i < n ; i++){
            mini = min(mini,dp[n-1][i]);
        }
        return mini;
    }
};
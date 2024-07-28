class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[n][n];

        for(int j = 0 ; j < n ;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n ; i++){
            for(int j = 0 ; j < n ;j++){
            
                int up = dp[i-1][j];
                int left = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int right = (j < n-1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min(up,min(left,right));
            }
        }
        int maxi = dp[n-1][0];
        for(int i = 0 ; i< n ; i++){
            maxi = min(maxi,dp[n-1][i]);
        }
        return maxi;
    }
};
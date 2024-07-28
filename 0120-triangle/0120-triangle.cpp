class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        int dp[n][n];
        for(int j = 0 ; j < n ;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i = n-2; i >=0 ;i--){
            for(int j = i; j>=0 ;j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dig = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dig);
            }
        }
        return dp[0][0];
    }
};
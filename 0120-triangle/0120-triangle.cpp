class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>&dp) {
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solve(i + 1, j, triangle,dp);
        int diag = solve(i + 1, j + 1, triangle,dp);

        return dp[i][j] = triangle[i][j] + min(down, diag);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>>dp;
        for (int i = 0; i < n; i++)
            dp.push_back(vector<int>(i + 1, -1));
        return solve(0, 0, triangle,dp); 
    }
};

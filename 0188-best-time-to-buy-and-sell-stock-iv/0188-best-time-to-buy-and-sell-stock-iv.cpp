class Solution {
    int find(int ind, vector<int>& prices, int buy, int k, vector<vector<vector<int>>>& dp) {
        if (k == 0 || ind == prices.size())
            return 0;

        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];

        if (buy) {
            // Either buy at this point or skip
            return dp[ind][buy][k] = max(-prices[ind] + find(ind + 1, prices, 0, k, dp),
                                         find(ind + 1, prices, 1, k, dp));
        } else {
            // Either sell at this point or skip
            return dp[ind][buy][k] = max(prices[ind] + find(ind + 1, prices, 1, k - 1, dp),
                                         find(ind + 1, prices, 0, k, dp));
        }
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return find(0, prices, 1, k, dp);  // Start with option to buy (buy = 1)
    }
};

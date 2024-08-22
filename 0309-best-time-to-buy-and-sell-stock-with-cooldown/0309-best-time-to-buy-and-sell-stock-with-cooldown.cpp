class Solution {
private:
    int find(vector<int>& prices, int ind, int buy, vector<vector<int>>& dp) {
        int n = prices.size();
        if (ind >= n) 
            return 0;  // Base case: no more days left

        if (dp[ind][buy] != -1) 
            return dp[ind][buy];  // Return already calculated result

        int profit = 0;

        if (buy) {
            // Option to buy or skip
            profit = max(-prices[ind] + find(prices, ind + 1, 0, dp), 
                         find(prices, ind + 1, 1, dp));
        } else {
            // Option to sell or skip
            profit = max(prices[ind] + find(prices, ind + 2, 1, dp), 
                         find(prices, ind + 1, 0, dp));  // Assuming cooldown after selling
        }

        return dp[ind][buy] = profit;  // Store result in dp array
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  // Memoization table
        return find(prices, 0, 1, dp);  // Start with option to buy
    }
};

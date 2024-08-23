class Solution {
private:
    int find(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (ind == prices.size())  // Base case: end of the prices array
            return 0;

        if (dp[ind][buy] != -1)  // Check if already computed
            return dp[ind][buy];

        int profit = 0;
        if (buy) {
            // Option 1: Buy the stock and move to the next day with "no buy" state
            // Option 2: Skip the day and stay in the "buy" state
            profit = max(-prices[ind] + find(ind + 1, 0, prices, fee, dp), 
                         find(ind + 1, 1, prices, fee, dp));
        } else {
            // Option 1: Sell the stock, pay the fee, and move to the next day with "buy" state
            // Option 2: Skip the day and stay in the "no buy" state
            profit = max(prices[ind] - fee + find(ind + 1, 1, prices, fee, dp), 
                         find(ind + 1, 0, prices, fee, dp));
        }

        // Store the result in the dp array and return it
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));  // Initialize dp array
        return find(0, 1, prices, fee, dp);  // Start with day 0 and "buy" state
    }
};

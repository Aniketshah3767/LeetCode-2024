class Solution {
private:
    int func(int ind, int amount, vector<int>& coins,vector<vector<int>>&dp) {
        if (ind == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }

        int nottake = 0 + func(ind - 1, amount, coins,dp);
        int take = INT_MAX;
        if (coins[ind] <= amount) {
            take = 1 + func(ind, amount - coins[ind], coins,dp);
        }

        return dp[ind][amount] = min(take, nottake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        // vector<int>ans;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));


        int temp = func(coins.size() - 1, amount, coins,dp);

        if (temp == 1e9) {
            return -1;
        } else {
            return temp;
        }
    }
};
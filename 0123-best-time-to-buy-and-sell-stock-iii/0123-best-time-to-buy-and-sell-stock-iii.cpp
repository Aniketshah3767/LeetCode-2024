class Solution {
private:
//Recursion
    // int find(int ind,vector<int>& prices, int buy, int cap){
    //     if(cap == 0)
    //         return 0;
    //     if(ind == prices.size())
    //         return 0;
    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[ind] + find(ind+1,prices,0,cap) , 0+find(ind+1,prices,1,cap));
    //     }
    //     else{
    //         profit = max(prices[ind] + find(ind+1,prices,1,cap-1) , 0 + find(ind+1,prices,0,cap));
    //     }
    //     return profit;
    // }

int find(int ind, vector<int>& prices, int buy, int cap, vector<vector<vector<int>>>& dp) {
    if (cap == 0)
        return 0;
    if (ind == prices.size())
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];

    if (buy) {
        return dp[ind][buy][cap] = max(-prices[ind] + find(ind + 1, prices, 0, cap, dp),
                                       find(ind + 1, prices, 1, cap, dp));
    } else {
        return dp[ind][buy][cap] = max(prices[ind] + find(ind + 1, prices, 1, cap - 1, dp),
                                       find(ind + 1, prices, 0, cap, dp));
    }
}

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return find(0, prices, 1, 2, dp);
    }
};
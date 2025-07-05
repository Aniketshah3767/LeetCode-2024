class Solution {
private:
    int func(int ind, vector<int>&stones, int Target, vector<vector<int>>&dp) {
        
        if (ind == 0) {
            if (stones[0] <= Target)
                return stones[0];
            return 0;
        }

        if(dp[ind][Target] != -1){
            return dp[ind][Target];
        }
        int nottake = func(ind - 1, stones, Target,dp);
        int take = 0;
        if (stones[ind] <= Target) {
            take =stones[ind] + func(ind - 1, stones, Target - stones[ind],dp);
        }
        return dp[ind][Target] =  max(take, nottake);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>>dp(stones.size(),vector<int>(sum/2+1,-1));
        int s1 = func(stones.size() - 1, stones, sum / 2,dp);
        return sum - 2 * s1;
    }
};
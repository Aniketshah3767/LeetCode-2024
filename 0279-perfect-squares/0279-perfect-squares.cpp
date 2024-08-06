class Solution {
public:
    int numSquares(int n) {
        vector<int>temp;
        for(int i = 1 ; i*i <= n ; i++){
            temp.push_back(i*i);
        }

        vector<int>dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1 ; i <= n ;i++){
            for(int square: temp){
                if(i-square >= 0){
                    dp[i] = min(dp[i], dp[i-square] + 1);
                }
            }
        }
        return dp[n];
    }
};
class Solution {
private:
 bool ispalindrome(string& s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
int solve(string &str, int i , int n, vector<int>&dp){
    if(i >= n)
        return 0;

    int minCost = INT_MAX;
    
    if(dp[i] != -1)
        return dp[i];
    
    for(int j = i ; j < n ; j++){
        if(ispalindrome(str,i,j)){
            int cost = 1 + solve(str,j+1,n,dp);
            minCost = min(cost,minCost);
        }
    }
    return dp[i] = minCost;
}
public:
    int minCut(string s) {
        int n = s.size();
        // vector<int>dp(n+1,INT_MAX);
        // dp[n] = -1;
        // for(int i = n- 1 ; i >= 0 ; i--){
        //     int mincost = INT_MAX;
        //     for(int j = i ; j < n ; j++){
        //         if(ispalindrome(s,i,j)){
        //             int cost = 1 + dp[j+1];
        //             mincost = min(mincost , cost);
        //         }
        //     }
        //     dp[i] = mincost;
        // }
        // return dp[0];
        vector<int>dp(n,-1);
        return solve(s,0,n,dp) - 1 ;
    }
};
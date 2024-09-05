class Solution {

private:
int f(int ind , vector<int>&num , int k, vector<int>&dp){
    int n = num.size();
    if(ind == n)
        return 0;

    if(dp[ind] != -1)
        return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int maxans = INT_MIN;
    for(int j = ind ; j < min(ind+k,n) ; j++){
        len++;
        maxi = max(maxi , num[j]);
        int ans = len * maxi + f(j+1,num,k,dp);
        maxans = max(maxans,ans);
    } 
    return dp[ind] = maxans;
}
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(), -1);
        return f(0,arr,k,dp);
    }
};
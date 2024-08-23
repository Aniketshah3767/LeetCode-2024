class Solution {
    // int find(int ind, int prev, vector<int>nums,vector<vector<int>>&dp){

    //     if(ind == nums.size())
    //         return 0;

    //     if(dp[ind][prev+1] != -1)
    //         return dp[ind][prev+1];

    //     int len = 0;
    //     len = find(ind+1,prev,nums,dp);

    //     if(prev == -1 || nums[ind] > nums[prev])
    //         len = max(len , 1 + find(ind+1,ind,nums,dp));
    //     return dp[ind][prev+1] = len;
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return find(0,-1,nums,dp);

        //??Tabluation??//

        // int n = nums.size();
        // vector<int>dp(n,1);
        // int maxi = 1;

        // for(int i = 1 ; i < n ; i++){
        //     for(int j = 0 ; j < i ; j++){
        //         if(nums[i] > nums[j]){
        //             dp[i] = max(dp[i], 1+ dp[j]);
        //         }
        //     }
        //     maxi = max(maxi,dp[i]);
        // }
        // return maxi;

        // LIS using binary Search

        vector<int> temp;
        temp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > temp.back())
                temp.push_back(nums[i]);
            else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};
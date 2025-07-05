class Solution {
private:
    int func(vector<int>nums,int target,vector<int>&dp){
        if(target == 0) return 1;
        if(target < 0) return 0;
        
        int ways = 0;

        if(dp[target] != -1)
            return dp[target];

        for(int i = 0 ; i < nums.size() ;i++){
            ways += func(nums,target-nums[i],dp);
        }
        return dp[target] = ways;
       
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return func(nums,target,dp);
    }
};

// class Solution {
// private:
//     int func(int target, vector<int>& nums) {
//         if (target == 0) return 1;  // Found a valid combination
//         if (target < 0) return 0;   // Invalid path

//         int ways = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             ways += func(target - nums[i], nums);
//         }
//         return ways;
//     }

// public:
//     int combinationSum4(vector<int>& nums, int target) {
//         return func(target, nums);
//     }
// };

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i < n ;i++){
        //     ans=max(ans,nums[i]+nums[n-1-i]);
        // }
        // return ans;
        int start =0 ;
        int end = nums.size()-1;
        int ans = INT_MIN;
        while(start < end){ 
            ans = max(ans,nums[start++] + nums[end--]);
        }
        return ans;
    }
};
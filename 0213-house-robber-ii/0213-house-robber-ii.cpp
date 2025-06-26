class Solution {
public:
    int find(vector<int>&nums){
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1 ; i< n;i++){
            int take = nums[i];
            if(i>1)
                take += prev2;
            
            int nottake = 0 + prev1;

            int curr = max(take,nottake);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];
        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());

        int ans1 = find(temp1);
        int ans2 = find(temp2);

        return max(ans2, ans1);
    } 
};
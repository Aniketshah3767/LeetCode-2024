class Solution {
public:
    int minOperations(vector<int>& nums) {
         int ans = 0;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                int increment = nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
                ans += increment; 
            }
        }

        return ans;
    }
};
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MIN;
        if (nums.size() == 3)
            return nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        ans = nums[0] + nums[1] +              nums[2];

        for (int i = 0; i < nums.size(); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            int targetSum = target - nums[i];

            while (left < right) {
                int tempSum = nums[left] + nums[right];

                if (abs(tempSum + nums[i] - target) < abs(ans - target))
                    ans = tempSum + nums[i];

                if (tempSum < targetSum)
                    left++;
                else if (tempSum > targetSum)
                    right--;
                else {
                    return target;
                }
            }
        }
        return ans;
    }
};
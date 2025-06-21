class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            int temp = nums[i+1] - nums[i];
            ans = max(ans,temp);
        }
        return ans;
    }
};
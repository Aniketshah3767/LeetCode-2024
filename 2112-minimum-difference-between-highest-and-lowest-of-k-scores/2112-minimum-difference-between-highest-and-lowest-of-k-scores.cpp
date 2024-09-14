class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1){
            return 0;
        }
        int diff = INT_MAX;

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i <= nums.size()- k ; i++){
            int min_diff = nums[i+k-1] - nums[i];
            diff = min(diff,min_diff);
        }
        return diff;
    }
};
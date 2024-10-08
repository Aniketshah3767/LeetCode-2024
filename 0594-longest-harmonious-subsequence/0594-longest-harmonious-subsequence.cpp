class Solution {
public:
    int findLHS(vector<int>& nums) {
        int res = 0;
        int left = 0, right = 1,currInd = 0;

        sort(nums.begin(),nums.end());

        while(right < nums.size()){
            if(nums[right] - nums[left] == 1){
                res= max(res,right-left+1);
            }
            while(nums[right] - nums[left] > 1){
                ++left;
            }
            ++right;
        }
        return res;
    }
};
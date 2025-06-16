class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long first = LONG_MAX;
        long second = LONG_MAX;

        for(int i = 0 ; i < nums.size() ; ++i){
            if(nums[i] <= first){
                first = nums[i];
            }
            else if(nums[i] <= second){
                second = nums[i];
            }
            else{
                return true;
            }
        }
        return false;

    }
};
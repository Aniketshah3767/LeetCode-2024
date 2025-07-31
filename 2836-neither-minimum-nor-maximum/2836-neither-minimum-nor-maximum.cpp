class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
    
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());

        for(int i : nums){
            if(i > mini && i < maxi)
                return i;
        }
        return -1;
    }
};
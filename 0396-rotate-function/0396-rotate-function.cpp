class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int maxi = 0;
        int f = 0;
        
        for(int i = 0; i < nums.size() ; i++){
            sum += nums[i];
            f += i* nums[i];
        }

        maxi = f;
        
        for(int k = 1 ; k < nums.size() ; k++){
            f = f + sum - nums.size() * nums[nums.size()-k];
            maxi = max(maxi,f);
        }
        return maxi;
    }
};
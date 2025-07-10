class Solution {
public:
    void shiftleft(vector<int>&nums, int ind) {
        int n = nums.size();
        for(int i = ind; i < n-1; i++) {
            nums[i] = nums[i+1];
        }
        nums.pop_back();
    }
    
    void mergepair(vector<int>&nums) {
        int n = nums.size();
        int minsum = INT_MAX;  
        int minind = 0;        
        
        for(int i = 0; i < n-1; i++) {
            int sum = nums[i] + nums[i+1];
            
            if(sum < minsum) {
                minsum = sum;
                minind = i;
            }
        }
        nums[minind] = minsum;
        shiftleft(nums, minind+1);
    }
    
    bool isSorted(vector<int>&nums) {
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i+1] < nums[i])
                return false;
        }
        return true;
    }
    
    int minimumPairRemoval(vector<int>& nums) {
        int result = 0;
        while(!isSorted(nums)) {
            mergepair(nums);
            result++;  // Increment the operation count
        }
        return result;
    }
};
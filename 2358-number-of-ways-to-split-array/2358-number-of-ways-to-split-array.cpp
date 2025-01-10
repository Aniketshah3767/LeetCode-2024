class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
        }

        long long temp = 0;
        int count = 0;

        for(int i = 0 ; i < n-1 ; i++){
            temp = temp + nums[i];
            if(temp >= sum - temp){
                count++;
            }
        }
        return count;
    }
};
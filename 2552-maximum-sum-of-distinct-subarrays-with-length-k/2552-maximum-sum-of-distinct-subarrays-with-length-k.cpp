class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        long long start = 0; 
        long long count = 0, ans = 0;
        for(int i = 0 ; i < n ; i++){
            count += nums[i];
            if(mpp.find(nums[i]) != mpp.end()){
                while(start <= mpp[nums[i]]){
                    count -= nums[start];
                    start++;
                }
                mpp[nums[i]] = i;
            }
            mpp[nums[i]] = i;
            if(i-start + 1 == k){
                ans=max(ans,count);
                count -= nums[start];
                mpp.erase(nums[start]);
                start++;
            }
        }
    return ans;
    }
};
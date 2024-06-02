class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),c=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                i++;
                c++;
            }
        }
        return {c,n-2*c};
    }
};
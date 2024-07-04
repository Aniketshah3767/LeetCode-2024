class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int first = 0;
        int count = 0;
        int second = 0;
        int len = 0;
        for(int first = 0 ; first < nums.size() ;first++)
        {
            if(nums[first] == 0)
                count++;

            while(count > k)
            {
                if(nums[second] == 0)
                    count--;
                second++;
            }
            len = max(len,first-second+1);
        }
        return len;
    }
};
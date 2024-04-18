class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int last = nums.size();
        vector<int> ans;

        for(int i = 0 ;  i < last ;i++){
            int count = 0;
            for(int j = 0 ; j < last ;j++){
                if(nums[i] > nums[j])
                    count++;
            }
            ans.push_back(count);
        }
    return ans;

    }
};
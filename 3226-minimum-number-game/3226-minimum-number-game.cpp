class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int i = 0;
        for(int i = 0 ; i < nums.size() ; i+=2){
            ans.push_back(nums[i+1]);
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
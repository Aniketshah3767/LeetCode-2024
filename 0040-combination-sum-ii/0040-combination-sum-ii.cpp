class Solution {
private:
    void solve(vector<vector<int>>& ans, vector<int>& temp, int ind, int target,
               vector<int> nums) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // include
        for (int i = ind; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > ind && nums[i] == nums[i - 1]) 
                continue;

            if (nums[i] > target) 
                break;

            temp.push_back(nums[i]);
            solve(ans, temp, i + 1, target - nums[i], nums);  
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(ans, temp, 0, target, candidates);
        return ans;
    }
};
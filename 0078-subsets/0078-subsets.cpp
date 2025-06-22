class Solution {
private:
    void solve(vector<vector<int>>&ans, vector<int>nums, int ind , int n, vector<int>&temp){
        if(ind == n){
            ans.push_back(temp);
            return;
        }

        //exclude
        solve(ans,nums,ind + 1, n,temp);

        //include
        temp.push_back(nums[ind]);
        solve(ans,nums, ind+1,n,temp);

        //back tracking step
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,nums,0,nums.size(),temp);
        return ans;
    }
};
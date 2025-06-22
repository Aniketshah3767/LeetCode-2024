class Solution {
private:
    void solve(vector<vector<int>>&ans, vector<int>&temp, vector<int> candidates, int ind, int target){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        //include;
        if(candidates[ind] <= target){
            temp.push_back(candidates[ind]);
            solve(ans,temp,candidates,ind,target-candidates[ind]);
            temp.pop_back();
        }

        //exclude
        solve(ans,temp,candidates,ind+1,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,candidates,0,target);
        return ans;
    }
};
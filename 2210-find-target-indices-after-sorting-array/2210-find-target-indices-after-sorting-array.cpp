class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int start = 0;
        int end = n-1;
        int mid = 0;
        while(start<=end){
            mid = start + (end-start)/2;

            if(nums[mid] >= target){
                end =  mid -1;
            }
            else{
                start = mid + 1;
            }
             mid = start + (end-start)/2;
        }

        int d = mid;
        vector<int> ans;
        for(int i = d; i < n ;i++){
            if(nums[i] == target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
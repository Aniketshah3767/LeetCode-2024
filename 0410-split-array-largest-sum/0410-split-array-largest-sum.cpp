class Solution {
private:
    int possible(vector<int>&nums, int days){
        int painter = 1;
        int painterstu = 0;
        for(int i = 0; i < nums.size() ; i++){
            if(painterstu + nums[i] <= days){
                painterstu += nums[i];
            }
            else{
                painter += 1;
                painterstu = nums[i];
            }
        }
        return painter;
    }

public:
    int splitArray(vector<int>& nums, int k) {

        if(nums.size() < k){
            return -1;
        }


        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        while(start <= end){
            int mid = start + (end - start)/2;
            int no_of = possible(nums,mid);
            if(no_of > k){
                start = mid + 1; 
            }
            else{
                end = mid - 1;
            }
        }
        return start;
    }
};
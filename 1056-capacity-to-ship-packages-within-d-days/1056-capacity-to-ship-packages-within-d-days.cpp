class Solution {
private:
    int possible(vector<int>&nums, int mid){
        int days = 1;
        int load = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(load + nums[i] > mid){
                days += 1;;
                load = nums[i];
            }
            else{
                load += nums[i];
            }

        }
        return days;
    }
public:
    int shipWithinDays(vector<int>&nums , int day) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int end = sum;
        int start = *max_element(nums.begin(),nums.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(possible(nums,mid) <= day){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        // int start = 0;
        // int end = nums.size() - 1;
        // while (start <= end) {
        //     int mid = start + (end-start)/2;
        //     if(nums[mid] == 0){
        //         start = mid + 1;
        //     }
        //     else if(nums[mid] < 0){
        //         start = mid + 1;
        //     }
        //     else{
        //         end = mid - 1;
        //     }
        // }
        int neg = 0;
        int pos = 0;
        for(auto it : nums){
            if(it<0)
                neg++;
            else if(it>0){
                pos++;
            }
        }
        return max(neg,pos);
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int n = nums.size();
        // int start = 1;
        // int end = n - 2;

        // if( n == 1){
        //     return nums[0];
        // }

        // if(nums[0] != nums[1]){
        //     return nums[0];
        // }

        // if(nums[n-1] != nums[n-2]){
        //     return nums[n-1];
        // }

        // while(start <= end){
        //     int mid = start + (end - start)/2;
        //     if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
        //         return nums[mid];
        //     }
        // if((mid%2==1 && nums[mid-1] == nums[mid]) || (mid%2==0 && nums[mid+1] == nums[mid])){
        //         start = mid + 1;
        //     }
        //     else{
        //         end = mid - 1;
        //     }
        // }
        // return -1;
        int result = 0;
        for(int num : nums){
            result ^= num;
        }
        return result;
    }
};
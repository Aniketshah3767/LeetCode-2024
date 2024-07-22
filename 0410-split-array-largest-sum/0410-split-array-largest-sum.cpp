// class Solution {

// private:
//     int func(vector<int> nums, int number) {
//         int n = nums.size();
//         int  count= 1;
//         int currsum = 0;

//         for (int i = 0; i < n; i++) {
//             if (currsum + nums[i] <= number) {
//                 currsum += nums[i];
//             } else {
//                  count++;
//                 currsum = nums[i];
//             }
//         }

//         return count;
//     }

// public:
//     int splitArray(vector<int>& nums, int k) {

//         if (nums.size() < k)
//             return -1;

//         int n = nums.size();
//         int high = accumulate(nums.begin(), nums.end(), 0);
//         int low = *max_element(nums.begin(), nums.end());

//         while (high <= low) {
//             int subarray = func(nums, k);
//             int mid = low + (high - low) / 2;
//             if (subarray > k) {
//                 low = mid + 1;
//             } else {
//                 high = mid - 1;
//             }
//         }
//         return low;
//     }
// };
class Solution {
private:
    int func(vector<int>& nums, int number) {
        int n = nums.size();
        int count = 1;
        int currsum = 0;

        for (int i = 0; i < n; i++) {
            if (currsum + nums[i] <= number) {
                currsum += nums[i];
            } else {
                count++;
                currsum = nums[i];
            }
        }

        return count;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        if (nums.size() < k)
            return -1;

        int n = nums.size();
        int high = accumulate(nums.begin(), nums.end(), 0);
        int low = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int subarray = func(nums, mid);
            if (subarray > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
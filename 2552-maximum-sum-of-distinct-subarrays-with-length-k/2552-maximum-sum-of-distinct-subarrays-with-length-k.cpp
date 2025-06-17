class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //-------------------brute Force approach------------------
    //     long long maxi = 0;
    //     int n = nums.size();

    //     for(int i = 0 ; i < n ; i++){
    //         unordered_set<int>set;
    //         long long sum = 0;

    //         for(int j = i ; j < i + k && j < n ;j++){
    //             if(set.find(nums[j]) != set.end()){
    //                 break;
    //             }
    //             set.insert(nums[j]);
    //             sum+=nums[j];
    //         }

    //         if(set.size() == k)
    //             maxi = max(sum,maxi);
    //     }


    // return maxi;

    // -------------------------- Optimal Approach------------------------

    long long max_sum = 0;
        long long window_sum = 0;
        int start = 0;
        int n = nums.size();
        std::unordered_map<int, int> map;

        for (int i = 0; i < n; ++i) {
            window_sum += nums[i];
            map[nums[i]]++;

            if (i - start + 1 == k) {
                if (map.size() == k) {
                    max_sum = std::max(max_sum, window_sum);
                }

                window_sum -= nums[start];
                if (--map[nums[start]] == 0) {
                    map.erase(nums[start]);
                }
                ++start;
            }
        }

        return max_sum;
    }
};
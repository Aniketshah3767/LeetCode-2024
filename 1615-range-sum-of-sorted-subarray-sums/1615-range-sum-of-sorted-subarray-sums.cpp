#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> subarraySums;
        
        // Generate all subarray sums
        for (int start = 0; start < n; ++start) {
            int sum = 0;
            for (int end = start; end < n; ++end) {
                sum += nums[end];
                subarraySums.push_back(sum);
            }
        }
        
        // Sort the subarray sums
        sort(subarraySums.begin(), subarraySums.end());
        
        // Calculate the final sum from left to right (1-based index)
        long long finalSum = 0;
        for (int i = left - 1; i < right; ++i) {
            finalSum += subarraySums[i];
        }
        
        // Return the result modulo 10^9 + 7
        return static_cast<int>(finalSum % 1000000007);
    }
};

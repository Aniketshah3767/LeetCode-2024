class Solution {
public:
    int arrangeCoins(int n) {
        long long left = 0, right = n; // Use long long to avoid overflow
        while (left <= right) { // Correct condition for binary search
            long long mid = left + (right - left) / 2;
            long long temp = mid * (mid + 1) / 2; // Sum of the first 'mid' rows
            
            if (temp == n) { 
                return mid; // Exact match found
            } else if (temp < n) { 
                left = mid + 1; // Move to the right half
            } else { 
                right = mid - 1; // Move to the left half
            }
        }
        return right; 
    }
};

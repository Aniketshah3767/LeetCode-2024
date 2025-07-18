class Solution {
public:
    bool isSameAfterReversals(int num) {
        int original = num; 
        int n = 2;
        int rev;

        while (n--) {
            rev = 0; 
            while (num > 0) { 
                rev = rev * 10 + num % 10;
                num /= 10;
            }
            num = rev; 
        }

        return original == num; 
    }
};

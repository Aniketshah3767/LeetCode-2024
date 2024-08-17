class Solution {
public:
    bool check(string &s) {
        bool flg = false;
        for (auto& x : s) {
            if (x == '3' || x == '4' || x == '7') {
                return false;
            }
            if (x == '2' || x == '5' || x == '6' || x == '9') {
                flg = true;
            }
        }
        return flg;
    }

    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            if (check(s)) ans++;
        }   
        
        return ans;
    }
};
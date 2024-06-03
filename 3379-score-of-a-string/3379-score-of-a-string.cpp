class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        int n = s.size();
        int i = 0;
        int j = 1;
        while(j < n){
            int val1 = (int)s[i];
            int val2 = (int)s[j];
            sum += abs(val1-val2);
            i++;
            j++;
        }
        return sum;
    }
};
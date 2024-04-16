class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        int n = s.size();
        int count = 0;
        unordered_map<char,int>mpp;
        while(right<n){
            mpp[s[right]]++;
            while(mpp['a'] >= 1 && mpp['b'] >=1 && mpp['c']>=1){
                count = count + (n-right);
                mpp[s[left]]--;
                left++;
            }
        right++;
        }
        return count;
    }
};
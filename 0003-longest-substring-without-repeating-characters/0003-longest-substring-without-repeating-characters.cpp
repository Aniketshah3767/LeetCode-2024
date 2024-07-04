class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        vector<bool>count(256,0);
        int l = 0;
        int r = 0;
        while(r < s.size())
        {
            while(count[s[r]])
            {
                count[s[l]] = 0;
                l++;
            }
            count[s[r]] = 1;
            len = max(len,r-l+1);
            r++;
        }
        return len;
    }
};
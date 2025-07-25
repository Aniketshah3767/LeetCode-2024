class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(j < t.size() && i < s.size()){
            if(s[i] == t[j])
                i++;
            j++;
        }
        return i == s.size();
    }
};
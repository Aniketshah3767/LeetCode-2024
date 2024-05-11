class Solution {
public:
    int firstUniqChar(string s) {
       int hash[52] = {0};
    int n = s.size();
        for(int i = 0 ; i < s.size() ; i++){
            hash[s[i] - 'a']++;
        }
        int i = 0 ;
        for(int i = 0 ; i < n ;i++){
            if(hash[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
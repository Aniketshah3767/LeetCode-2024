class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,vector<int>>m1,m2;
        if(s.length() != t.length())
            return false;
        

        for(int i = 0 ; i < s.length() ;i++){
            m1[s[i]].push_back(i);
        }

        for(int i = 0 ; i < t.length() ;i++){
            m2[t[i]].push_back(i);
        }

        for(int i = 0 ; i < s.length() ;i++){
            if(m1[s[i]] != m2[t[i]])
                return false;
        }
        return true;
    }
};
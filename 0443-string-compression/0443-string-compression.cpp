class Solution {
    public:
     int compress(vector<char>& chars) {
        vector<char> ans;
        int n = chars.size();
        int i = 0;
        
        while (i < n) {
            char currentChar = chars[i];
            int count = 0;
            
            while (i < n && chars[i] == currentChar) {
                count++;
                i++;
            }
            
            ans.push_back(currentChar);
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    ans.push_back(c);
                }
            }
        }
        chars = ans;
        return chars.size();
    }
};
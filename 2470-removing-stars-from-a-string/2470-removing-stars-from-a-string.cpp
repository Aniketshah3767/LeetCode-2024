class Solution {
public:
    string removeStars(string s) {
        int count = 0;
        stack<char>st;
        string res = "";
        int i = 0;
        int n = s.size();
        while(i<n){
            if(s[i] == '*')
                st.pop();
            else
                st.push(s[i]);
            i++;
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
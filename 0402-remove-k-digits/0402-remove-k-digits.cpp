class Solution {
public:
    string removeKdigits(string num, int k) {
        // deque<char> st;
        // int keep = num.size() - k;

        // for (char digit : num) {
        //     while (!st.empty() && st.back() > digit && k > 0) {
        //         st.pop_back();
        //         k--;
        //     }
        //     st.push_back(digit);
        // }
        // while (k > 0) {
        //     st.pop_back();
        //     k--;
        // }

        // while (!st.empty() && st.front() == '0') {
        //     st.pop_front();
        // }

        // string ans;
        // copy(st.begin(), st.end(), back_inserter(ans));

        // return ans.empty() ? "0" : ans;
        stack<char>st;
        for(auto it: num){
            while(!st.empty() && k && it < st.top()){
                st.pop();
                k--;
            }
            st.push(it);
        }

        string ans = "";
        while(!st.empty() && k){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        int n = ans.length();
        while(i < n && ans[i] == '0'){
            i++;
        }
        if(i == n)
            return "0";
        return ans.substr(i);
    }
};
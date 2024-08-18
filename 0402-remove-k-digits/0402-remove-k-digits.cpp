class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> st;
        int keep = num.size() - k;

        for (char digit : num) {
            while (!st.empty() && st.back() > digit && k > 0) {
                st.pop_back();
                k--;
            }
            st.push_back(digit);
        }
        while (k > 0) {
            st.pop_back();
            k--;
        }

        while (!st.empty() && st.front() == '0') {
            st.pop_front();
        }

        string ans;
        copy(st.begin(), st.end(), back_inserter(ans));

        return ans.empty() ? "0" : ans;
    }
};
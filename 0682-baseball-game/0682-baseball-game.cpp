
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (auto& op : operations) {
            if (op == "C") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (op == "D") {
                if (!st.empty()) {
                    st.push(st.top() * 2);
                }
            } else if (op == "+") {
                if (st.size() >= 2) {
                    int top1 = st.top();
                    st.pop();
                    int top2 = st.top();
                    st.push(top1);
                    st.push(top1 + top2);
                }
            } else {
                st.push(stoi(op));
            }
        }

        int total = 0;
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};
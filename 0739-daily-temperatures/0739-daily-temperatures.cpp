class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        vector<int>res(temperatures.size(),0);

        for(int i = 0 ; i < temperatures.size();i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int ind = st.top();
                st.pop();
                res[ind] = i - ind;
            }
            st.push(i);
        }
        return res;
    }
};
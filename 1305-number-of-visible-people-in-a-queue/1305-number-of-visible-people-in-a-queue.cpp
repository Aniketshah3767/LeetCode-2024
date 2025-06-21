class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> ans(heights.size(), 0);
        int n = heights.size();

        for(int i = n - 1 ; i >= 0 ; i--){
            int count = 0;
            while(!st.empty() && heights[i] > st.top()){
                st.pop();
                count++;
            }

            if(st.size() > 0){
                count++;
            }
            ans[i] = count;
            st.push(heights[i]);
        }
        return ans;
        
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int n = asteroids.size();
        for(int i = 0 ;  i < n ; i++){
            while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
                int diff = asteroids[i] + st.top();
                if(diff < 0)
                    st.pop();
                else if(diff>0)
                    asteroids[i] = 0;
                else{
                    st.pop();
                    asteroids[i] = 0;
                }
            }
            if(asteroids[i] != 0)
                st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
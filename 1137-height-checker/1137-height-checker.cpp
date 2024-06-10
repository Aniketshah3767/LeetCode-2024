class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int>second(n);
        for(int i = 0 ; i < n ; i++){
            second[i] = heights[i];
        }

        sort(heights.begin(),heights.end());

        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(heights[i] != second[i])
                count++;
        }
        return count;
    }
};
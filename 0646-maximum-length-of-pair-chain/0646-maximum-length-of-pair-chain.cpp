class Solution {
    
public:
    int findLongestChain(vector<vector<int>>& pair) {
        sort(pair.begin(),pair.end(), [](const vector<int>&a , vector<int>& b){
            return a[1] < b[1];
        });

        int chainlength = 0;
        int current = INT_MIN;

        for(const auto pair: pair){
            if(pair[0] > current){
                chainlength++;
                current = pair[1];
            }
        }
        return chainlength;
    }
};
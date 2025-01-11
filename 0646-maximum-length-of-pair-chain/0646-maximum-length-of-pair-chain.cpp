class Solution {
    
public:
    int findLongestChain(vector<vector<int>>& pair) {
        // sort(pair.begin(),pair.end(), [](const vector<int>&a , vector<int>& b){
        //     return a[1] < b[1];
        // });

        // int chainlength = 0;
        // int current = INT_MIN;

        // for(const auto pair: pair){
        //     if(pair[0] > current){
        //         chainlength++;
        //         current = pair[1];
        //     }
        // }
        // return chainlength;
        sort(pair.begin(),pair.end());
        int n = pair.size();

        vector<int>dp(n,1);

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(pair[j][1] < pair[i][0]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
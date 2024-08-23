class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int maxi = 1;
        int lastind = 0;
        vector<int>dp(n,1), hash(n);
        vector<int>ans;
        for(int i = 0 ; i < n ; i++){
            hash[i] = i;
            for(int j = 0 ; j < i ; j++){
                if(arr[i] % arr[j] == 0 && 1+dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
                lastind = i;
            }
        }
        ans.push_back(arr[lastind]);
        while(hash[lastind] != lastind){
            lastind = hash[lastind];
            ans.push_back(arr[lastind]);
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};
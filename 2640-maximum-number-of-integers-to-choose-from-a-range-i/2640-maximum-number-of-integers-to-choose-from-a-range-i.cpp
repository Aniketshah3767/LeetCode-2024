class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>s(banned.begin(), banned.end());

        int count = 0 ;
        int sum = 0;
        for(int i = 0 ; i <= n ; i++){
            if(s.find(i) == s.end() && sum+i <= maxSum){
                sum += i;
                count++;
            }
            
        }
        return count - 1;
    }
};
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(int i : arr){
            mpp[i]++;
        }

        int maxi =0;
        int temp1 = 0;
        for(auto it : mpp){
            if(it.second == it.first){
                temp1 = it.first;
                maxi = max(maxi,temp1);
            }
        }
        return maxi != 0 ? maxi : -1;
    }
};
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int temp = 0;
        int finalans = 0;
        for(int i = 0 ; i < gain.size(); i++){
            temp += gain[i];
            finalans = max(finalans,temp);
        }
    return finalans;
    }
};
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        // int total = 0;
        // for(int i = 0 ; i < values.size()-1 ; i++){
        //     for(int j = i+1 ; j < values.size() ; j++){
        //         int temp = values[i] + values[j] + i - j;
        //         total = max(total,temp);
        //     }
        // }
        // return total;
        int maxScore = 0;
        int maxi = nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            maxScore = max(maxScore,maxi+nums[i] - i);
            maxi = max(maxi,nums[i] + i);
        }
        return maxScore;
    }
};
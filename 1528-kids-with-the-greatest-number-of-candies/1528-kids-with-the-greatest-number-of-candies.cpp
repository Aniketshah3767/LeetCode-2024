class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int maxi = *max_element(candies.begin(),candies.end());
        for(int i = 0 ; i < candies.size() ; i++){
            if((extraCandies + candies[i]) >= maxi){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};
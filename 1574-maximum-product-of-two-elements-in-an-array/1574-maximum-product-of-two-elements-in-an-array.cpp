class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxproduct = 0;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            int product = 1;
            for(int j = i+1 ; j < nums.size() ; j++){
                product = ((nums[i]-1)*(nums[j]-1));
                maxproduct = max(maxproduct,product);
            }
        }
        return maxproduct;
    }
};
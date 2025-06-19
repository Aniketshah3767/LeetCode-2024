class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_prod = 1;

        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            max_prod *= nums[i];
            maxi = max(max_prod, maxi);
            if (max_prod == 0) {
                max_prod = 1;
            }
        }
        max_prod = 1;

        for(int i = nums.size()- 1 ;i>=0;i--){
            max_prod *= nums[i];
            maxi = max(maxi,max_prod);
            if(max_prod == 0)
                max_prod = 1;
        }
        return maxi;
    }
};
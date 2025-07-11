class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int max_prod = 1;

        // int maxi = INT_MIN;
        // for (int i = 0; i < nums.size(); i++) {
        //     max_prod *= nums[i];
        //     maxi = max(max_prod, maxi);
        //     if (max_prod == 0) {
        //         max_prod = 1;
        //     }
        // }
        // max_prod = 1;

        // for(int i = nums.size()- 1 ;i>=0;i--){
        //     max_prod *= nums[i];
        //     maxi = max(maxi,max_prod);
        //     if(max_prod == 0)
        //         max_prod = 1;
        // }
        // return maxi;
        int prefix = 1;
        int suffix = 1;
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[nums.size()-i-1];

            maxi = max(maxi,max(prefix,suffix));
        }
        return maxi;
    }
};
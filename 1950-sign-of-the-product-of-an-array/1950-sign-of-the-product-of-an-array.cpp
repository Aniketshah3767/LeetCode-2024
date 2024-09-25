class Solution {
    private:
    int signFunc(int product){
        if(product > 0){
            return 1;
        }
        else if(product < 0){
            return -1;
        }
        else{
            return 0;
        }
    }
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0)
                nums[i] = -1;
            else if (nums[i] > 0)
                nums[i] = 1;
            else
                return 0;
        }

        for(auto it : nums){
            product *= it;
        }
        return signFunc(product);
    }
};
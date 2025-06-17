class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int count = 0;
        // for(int i = 0 ; i < nums.size() ;i++){
        //     for(int j = i ; j < nums.size() ; j++){
        //         if(nums[i] == nums[j] && i < j){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        for(int i = 0 ; i < nums.size() ;i++){
            if(mpp.find(nums[i]) != mpp.end()){
                count += mpp[nums[i]];
            }
            mpp[nums[i]] = mpp[nums[i]]+1;
        }
        return count;
    }
};
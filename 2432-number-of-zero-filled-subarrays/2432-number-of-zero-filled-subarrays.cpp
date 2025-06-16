class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i ; j < n ; j++){
        //         if(nums[j] != 0)
        //             break;
                
        //         else
        //             ans++;

        //     }
        // }
        // return ans;
        int i = 0;
        while(i < n){
            long long count = 0;
            while(i<n && nums[i] == 0){
                count++;
                i++;
            }
            ans += (count*(count+1))/2;
            i++;
        }
        return ans;


    }
};
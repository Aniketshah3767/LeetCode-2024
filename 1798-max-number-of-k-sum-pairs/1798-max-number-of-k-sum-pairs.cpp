class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        map<int,int>mpp;

        for(int i = 0 ; i < nums.size() ; i++){
            mpp[nums[i]]++;
        }

        sort(nums.begin(),nums.end());
        int i = 0 ;
        int j = nums.size()-1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum == k){
                count++;
                i++;j--;
            }
            else if(sum < k){
                i++;
            }
            else 
                j--;

        }
        return count;
    }
};
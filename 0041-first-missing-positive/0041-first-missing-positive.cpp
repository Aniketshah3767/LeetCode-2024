class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int temp = 1;
        for(auto i : nums){
            if(s.find(temp) == s.end()){
                return temp;
            }
            else{
                temp++;
            }
        }
        return temp;
    }
};
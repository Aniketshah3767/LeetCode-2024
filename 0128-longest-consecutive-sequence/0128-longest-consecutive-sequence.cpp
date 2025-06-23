class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest = 0;
        for(int num : nums){
            if(s.find(num-1) == s.end()){
                int currNum = num;
                int streak = 1;

                while(s.find(currNum + 1) != s.end()){
                    currNum++;
                    streak+=1;
                }
                longest = max(streak,longest);
            }

        }
        return longest;
        
    }
};
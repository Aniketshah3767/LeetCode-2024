class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        vector<int>ans;

        while(i<j){
            int total = numbers[i] + numbers[j];
            if(total > target)
                j--;
            
            else if(total < target)
                i++;

            else
                return {i+1,j+1};
        }
        return {-1,-1};
    }
};
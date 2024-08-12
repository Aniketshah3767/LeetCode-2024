class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum =0;
        double size = 0;
        double i = 0; 
        double j = 0;
        while(j<k){
            sum += nums[j];
            j++;
        }

        double total = sum / k;
        while(j<nums.size()){
            sum += nums[j] - nums[i];
            total = max(total , sum / k);
            i++; j++;
        }
        return total;
    }
};
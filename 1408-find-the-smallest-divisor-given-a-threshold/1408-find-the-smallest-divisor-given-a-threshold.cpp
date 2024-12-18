class Solution {
private:
    int possible(vector<int>&nums, int mid){
        int temp = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            temp = temp + ceil(double(nums[i]) / double(mid));
        }
        return temp;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // if(nums.size() > threshold)
        //     return -1;

        int start = 1;
        int end = *max_element(nums.begin(),nums.end());

        while(start <= end){
            int mid = start + (end-start)/2;
            if(possible(nums,mid) <= threshold){
                end = mid -1 ;
            }
            else{
                start = mid + 1;
            }
        }  
        return start;
    }
};
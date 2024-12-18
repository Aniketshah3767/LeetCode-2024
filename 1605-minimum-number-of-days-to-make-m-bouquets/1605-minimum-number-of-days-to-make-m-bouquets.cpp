class Solution {
private:
    bool possible(vector<int>& arr, int m, int k, int day){
        int flower = 0;
        int bookk = 0;

        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] <= day){
                flower++;
                if(flower == k){
                    bookk++;
                    flower = 0;
                }
            }
            else{
                flower = 0;
            }
        }
        return bookk >= m;
    }

public:
    int minDays(vector<int>& arr, int m, int k) {
        long long totalFlowers = (long long)m * k;
        
        if (totalFlowers > arr.size()) {
            return -1;
        }

        int maxi = *max_element(arr.begin(), arr.end());

        int start = 1;
        int end = maxi;

        while(start < end){
            int mid = start + (end - start)/2;
            if(possible(arr,m,k,mid)){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};
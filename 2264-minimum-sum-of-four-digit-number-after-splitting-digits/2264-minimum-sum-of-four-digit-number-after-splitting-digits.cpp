class Solution {
public:
    int minimumSum(int num) {
        vector<int>arr;
        int k = 0;
        while(num != 0){
            arr.push_back(num%10);
            num/=10;
        }

        sort(arr.begin(),arr.end());

        return ((arr[0]*10)+ arr[3])+ ((arr[1]*10)+ arr[2]);
    }
};
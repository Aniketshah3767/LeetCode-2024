class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i = 0;
        int count = 0;

        int n = arr.size();
        while( i < n )
        {
            if(arr[i] % 2 != 0){
                count++;
                if(count == 3)
                    return true;
            }
            else
                count = 0;
            i++;
        }
        return false;
    }
};
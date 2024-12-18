class Solution {
public:
    int mySqrt(int x) {
        if( x == 0 || x == 1){
            return x;
        }

        int start = 0;
        int end = x;
        while(start <= end){
            int mid = start + (end - start)/2;
            long long t = (long long)(mid)*mid;

            if(t == x){
                return mid;
            }
            else if(t < x){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return (int)(round(end));
    }
};
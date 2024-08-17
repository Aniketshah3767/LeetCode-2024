class Solution {
public:
    bool judgeSquareSum(int c) {

        long long start = 0;
        long long end = sqrt(c);
        while(start<=end){
            long long sumofsq = start * start + end * end;
            if(sumofsq == c)
                return true;
            else if(sumofsq > c)
                end--;
            else
                start++;
        }
        return false;
    }
};
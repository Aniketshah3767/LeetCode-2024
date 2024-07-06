class Solution {
public:
    int passThePillow(int n, int time) {
        int complete = time / (n-1);
        int remaining = time % (n-1);
        int ans = 0;
        if(complete % 2 != 0)
            ans = n - remaining;
        else
            ans = remaining + 1;
        return ans;
    }

};
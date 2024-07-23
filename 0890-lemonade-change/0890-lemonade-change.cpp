class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fivecnt = 0;
        int tencnt = 0;
        int i = 0;
        while(i < n){
            if(bills[i] == 5){
                fivecnt++;
            }
            else if(bills[i] == 10){
                if(fivecnt){
                    tencnt++;
                    fivecnt--;
                }
                else{
                    return false;
                }
            }
            else{
                if(tencnt && fivecnt){
                    tencnt--;
                    fivecnt--;
                }
                else if(fivecnt >= 3){
                    fivecnt -= 3;
                }
                else{
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};
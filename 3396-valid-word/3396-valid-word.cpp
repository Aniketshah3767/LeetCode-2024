class Solution {
public:
    bool isValid(string word) {
        int count1 = 0 ,count2 = 0;
        for(auto it : word){
            char lo = tolower(it);
            if(lo =='a' || lo =='e' || lo =='i' || lo == 'o' || lo == 'u'){
                count1++;
            }
            else if(isalpha(lo)){
                count2++;
            }
            else if(!isdigit(lo)){
                return false;
                break;
            }
            
        }
        return word.size() >= 3 && count1 > 0 && count2>0; 
    }
};
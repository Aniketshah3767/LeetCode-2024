class Solution {
public:
    bool isValid(string word) {
        int count1 = 0 ,count2 = 0;
        for(auto it : word){
            char lo = tolower(it);
            if(lo =='a' || lo =='e' || lo =='i' || lo == 'o' || lo == 'u'){
                count1++;
            }
            else if(lo == '$' || lo == '@' || lo == '(' || lo == ')' || lo == '{' || lo == '}' || lo == '[' || lo == ']' || lo == '*' || lo == '#' || lo == '!'){
                return false;
                break;
            }
            else if(isalpha(lo)){
                count2++;
            }
        }

        // return count1 + count2 >= 3 && count1 > 0 && count2>0;
        return word.size() >= 3 && count1 > 0 && count2>0; 
    }
};
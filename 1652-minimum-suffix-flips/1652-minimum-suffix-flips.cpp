class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        for(int i = 0 ; i < target.size()-1 ; i++){
            if(target[i] != target[i+1])
                count++;
        }

        return (target[0] == '0')? count : count+1;
    }
};
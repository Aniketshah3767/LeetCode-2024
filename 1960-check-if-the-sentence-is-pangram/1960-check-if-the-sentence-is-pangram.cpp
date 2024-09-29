class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>arr(26,0);
        int count = 0;
        for(char &ch : sentence){
            int idx = ch - 'a';

            if(arr[idx] == 0){
                arr[idx]++;
                count++;
            }
        }
        return true ? (count == 26) : false;
    }
};
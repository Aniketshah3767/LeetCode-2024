class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int count = n;
        for(int i = 1; i < n ;i++){
            count -= (word[i] != word[i-1]);
        }
        return count;
    }
};
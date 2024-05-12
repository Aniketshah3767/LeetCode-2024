class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string,int>mp;
        map<string,int>mp2;
        for(auto i : words1){
            mp[i]++;
        }

        for(auto i : words2){
            mp2[i]++;
        }
        int count = 0;

        for(auto i : words1){
            if(mp[i] == 1 && mp2[i] == 1)
                count++;
        }
        return count;
    }
};
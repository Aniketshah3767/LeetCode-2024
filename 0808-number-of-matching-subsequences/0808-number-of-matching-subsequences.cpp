class Solution {
public:

    bool help(string s , string word){
        int k = 0;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] == word[k]){
                k++;
            }

            if(k == word.size()){
                return true;
            }
        }
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count  = 0;
        unordered_map<string,int>mpp;
        for(auto it: words){
            mpp[it]++;
        }

        for(auto it : mpp){
            if(help(s,it.first)){
                count+=it.second;
            }
        }
    return count;
    }

};
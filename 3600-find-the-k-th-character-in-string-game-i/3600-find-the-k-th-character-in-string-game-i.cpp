class Solution {
public:
    char kthCharacter(int k) {
        vector<int>asc= {0};
        while(asc.size() < k){
            int len = asc.size();
            for(int i = 0 ; i < len ;i++){
                asc.push_back((asc[i]+1)%26);
            }
        }
        return (asc[k-1]+'a');
    }
};
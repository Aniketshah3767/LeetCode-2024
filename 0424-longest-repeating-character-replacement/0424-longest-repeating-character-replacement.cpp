class Solution {
public:
    int characterReplacement(string s, int k) {
        int left =0,right = 0,maxlen = 0, maxfreq=0;
        int hash[26] = {0};

        while(right < s.size()){
            hash[s[right]- 'A']++;
            maxfreq = max(maxfreq,hash[s[right]-'A']);

            //check for validity;
            while((right-left+1) - maxfreq > k){
                hash[s[left]-'A']--;
                maxfreq = 0;

                for(int i = 0 ; i < 26 ; i++)
                    maxfreq = max(maxfreq,hash[i]);
                left = left + 1;
            }

            if((right-left+1)- maxfreq <= k){
                maxlen = max(maxlen , right-left+1);
                right++;
            }
        }
        return maxlen;
    }
};
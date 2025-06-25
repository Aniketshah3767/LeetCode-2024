class Solution {
public:
    int numSplits(string s) {

        
        // int count = 0;

        // int i = 0;

        // while(i < s.size()-1){
        //     unordered_map<char,int>mpp1,mpp2;
        //     string s1 = s.substr(0,i+1); 
        //     string s2 = s.substr(i+1);

        //     for(auto it : s1){
        //         mpp1[it]++;
        //     }

        //     for(auto it : s2){
        //         mpp2[it]++;
        //     }

        //     if(mpp1.size() == mpp2.size()){
        //         count++;
        //     }

        //     i++;
        // }
        // return count;
        int count = 0 ;

        unordered_map<char,int>mpp1,mpp2;
        for(auto it : s){
            mpp1[it]++;
        }

        for(int i = 0 ; i < s.size()-1;i++){
            mpp2[s[i]]++;
            mpp1[s[i]]--;

             if (mpp1[s[i]] == 0)   
                mpp1.erase(s[i]);

            if(mpp1.size() == mpp2.size()){
                count+=1;
            }
        }
        return count;
    }
};
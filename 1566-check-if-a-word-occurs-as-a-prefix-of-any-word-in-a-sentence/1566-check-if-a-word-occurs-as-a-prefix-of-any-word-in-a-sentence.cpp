class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int size = searchWord.size();

        if(sentence.starts_with(searchWord))
            return 1;
        
        for(int split = -1 , cnt = 1;;cnt++){
            split = sentence.find(' ',split+1);
            if(split == -1)
                break;
            
            auto sb = sentence.substr(split+1,size);
            if(sb.starts_with(searchWord))
                return cnt+1;

        }
        return -1;
    }
};
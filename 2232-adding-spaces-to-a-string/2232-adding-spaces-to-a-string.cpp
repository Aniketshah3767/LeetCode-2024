class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        int i = 0;
        int count = 0;

        for(auto it : s){
            if(i < spaces.size() && count == spaces[i]){
                result+=" ";
                i++;
            }
            result += it;
            count++;   
        }
        return result;
    }
};
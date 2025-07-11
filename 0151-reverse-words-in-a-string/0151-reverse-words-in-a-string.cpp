#include <string.h>
class Solution {
public:
    string reverseWords(string str) {
        //    string ans ="";
        //    int i = 0;
        //    int n = str.length();
        //    while(i<n){
        //        string temp ="";
        //        while(str[i]==' ' && i<n) i++;
        //        while(str[i]!=' ' && i<n){
        //            temp += str[i];
        //            i++;
        //        }
        //        if(temp.size() > 0){
        //            if(ans.size()==0)
        //             ans=temp;
        //         else{
        //             ans = temp + " " + ans;
        //         }
        //        }
        //    }
        //    return ans;
        // -----------------------------------------
        // stringstream ss(str);
        // string word;
        // vector<string> words;
        // while (ss >> word) {
        //     words.push_back(word);
        // }
        // reverse(words.begin(), words.end());

        // string result;
        // for (int i = 0; i < words.size(); ++i) {
        //     result = result + words[i];
        //     if (i != words.size() - 1)
        //         result += " ";
        // }

        // return result;

        // ===================================

        stringstream ss(str);
        string word;
        vector<string>words;

        while(ss >> word){
            words.push_back(word);
        }
        reverse(words.begin(),words.end());

        string result;
        for (int i = 0; i < words.size(); ++i) {
            result = result + words[i];
            if (i != words.size() - 1)
                result += " ";
        }
        return result;
    }
};
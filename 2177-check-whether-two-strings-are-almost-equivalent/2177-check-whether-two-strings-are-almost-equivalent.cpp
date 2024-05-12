class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int hash[26] = {0};

        for (int i = 0; i < word1.size(); i++) {
            hash[word1[i] - 'a']++;
        }

        for (int i = 0; i < word2.size(); i++) {
            hash[word2[i] - 'a']--;
        }

        for (int count : hash) {
            if (abs(count) > 3) {
                return false;
            }
        }
        return true;
    }
};
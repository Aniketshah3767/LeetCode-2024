class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
    int size = searchWord.size();
    int index = 1; // Word index starts from 1.
    stringstream ss(sentence);
    string word;

    while (ss >> word) { // Split sentence into words
        if (word.substr(0, size) == searchWord) {
            return index; // Found a match, return the word index.
        }
        index++;
    }
    return -1; // No match found.
}
};
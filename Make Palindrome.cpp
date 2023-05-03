//User function Template for C++

class Solution{
public:
bool makePalindrome(int n, vector<string>& arr) {
    unordered_map<string, int> wordFrequency;

    for (auto word : arr) {
        string reverseWord = word;
        reverse(reverseWord.begin(), reverseWord.end());

        if (wordFrequency.find(reverseWord) != wordFrequency.end()) {
            wordFrequency[reverseWord]--;

            if (wordFrequency[reverseWord] == 0) {
                wordFrequency.erase(reverseWord);
            }
        }
        else {
            wordFrequency[word]++;
        }
    }

    if (wordFrequency.size() == 0) {
        return true;
    }
    else if (wordFrequency.size() == 1) {
        string currentWord = wordFrequency.begin()->first;
        string reverseWord = currentWord;
        reverse(reverseWord.begin(), reverseWord.end());
        return reverseWord == currentWord;
    }
    else {
        return false;
    }
}
};

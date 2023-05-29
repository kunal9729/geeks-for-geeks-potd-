//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 
    vector<string> CamelCase(int wordCount, vector<string> dictionary, string pattern) {
    vector<string> result;
    for (int i = 0; i < wordCount; i++) {
        string currentWord = dictionary[i];
        int patternPtr = 0;
        for (int j = 0; j < currentWord.size(); j++) {
            if (isupper(currentWord[j])) {
                if (currentWord[j] == pattern[patternPtr])
                    patternPtr++;
                else
                    break;
            }
            if (patternPtr == pattern.size())
                break;
        }
        if (patternPtr == pattern.size())
            result.push_back(currentWord);
    }
    if (result.empty())
        result.push_back("-1");
    return result;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

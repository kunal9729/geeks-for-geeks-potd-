
#include <string>
#include <queue>
#include <vector>

class Solution {
public:
    std::string FirstNonRepeating(std::string A) {
        std::queue<char> q;
        std::vector<int> freq(26, 0);
        std::string result = "";

        for (char ch : A) {
            ++freq[ch - 'a'];

            if (freq[ch - 'a'] == 1)
                q.push(ch);

            while (!q.empty() && freq[q.front() - 'a'] > 1)
                q.pop();

            result += (!q.empty() ? q.front() : '#');
        }

        return result;
    }
};

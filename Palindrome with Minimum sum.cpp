class Solution {
public:
    int minimumSum(string s) {
        int n = s.size();
        int left = (n % 2 == 0) ? n / 2 - 1 : n / 2;
        int right = n / 2;
        char previous = '#';
        int sum = 0;

        while (left >= 0) {
            if (s[left] != '?' && s[n - left - 1] != '?' && s[left] != s[n - left - 1])
                return -1;
            else if (s[left] == '?' && s[right] == '?') {
                left--;
                right++;
                continue;
            } else if (s[left] != '?' && s[left] != previous) {
                if (previous != '#')
                    sum += 2 * abs(s[left] - previous);
                previous = s[left];
            } else if (s[right] != '?' && s[right] != previous) {
                if (previous != '#')
                    sum += 2 * abs(s[right] - previous);
                previous = s[right];
            }
            left--;
            right++;
        }

        return sum;
    }
};

// T.C O(n)
// O.C O(1)

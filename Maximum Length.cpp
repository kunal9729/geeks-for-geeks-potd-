// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        
        char prev = '0';
        int v[3] = {a, b, c};

        string ans;
        for (int i = 0; i < a + b + c; i++) {
            int ma = 0;
            char cur;

            for (int j = 0; j < 3; j++)
                if (prev != char(j + 'a') && ma < v[j])
                    ma = v[j], cur = j + 'a';

            if (ma == 0)
                break;

            ans += cur;
            v[cur - 'a']--;
            if (ma >= 2 && (prev == '0' || ma > v[prev - 'a'])) {
                ans += cur;
                v[cur - 'a']--;
            }
            prev = cur;
        }
        int n = ans.length();
        if (n != a + b + c) return -1;
        return n;
        // code here
    }
};

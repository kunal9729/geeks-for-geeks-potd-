//User function Template for C++

class Solution {
public:
    string kthPermutation(int n, int k) {
        string ans;
        vector<int> v(n, 0);
        iota(v.begin(), v.end(), 1);
        --k;

        for (int i = n - 1; i >= 0; --i) {
            int f = factorial(i);
            int ind = k / f;
            ans += to_string(v[ind]);
            v.erase(v.begin() + ind);
            k %= f;
        }

        return ans;
    }

private:
    int factorial(int n) {
        if (n <= 1)
            return 1;

        int fact = 1;
        for (int i = 2; i <= n; ++i) {
            fact *= i;
        }

        return fact;
    }
};

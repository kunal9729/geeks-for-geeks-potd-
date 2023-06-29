
#include <unordered_set>

class Solution {
public:
    int nextHappy(int n) {
        n++;
        std::unordered_set<int> visited;

        while (n <= 1e5) {
            if (solve(n, visited))
                return n;
            n++;
        }

        return -1;
    }

    bool solve(int n, std::unordered_set<int>& visited) {
        // Happy numbers: 1, 7
        // Unhappy numbers: 2, 3, 4, 5, 6, 8, 9
        if (n == 1 || n == 7)
            return true;
        if (visited.count(n) > 0)
            return false;

        visited.insert(n);
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return solve(sum, visited);
    }
};


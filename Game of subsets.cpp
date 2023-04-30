//User function Template for C++

class Solution {
public:
    int mod;
    vector<int> prime_masks;

    Solution() {
        mod = 1e9+7;

        // Create a vector of masks where the i-th element represents the set of prime factors of i.
        prime_masks.resize(31);
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int num = 2; num <= 30; ++num) {
            if (num % 4 == 0 || num % 9 == 0 || num == 25) {
                // If num is a multiple of 4/9/25, adding it to any subset will make it "bad".
                continue;
            }
            int mask = 0;
            for (int j = 0; j < 10; ++j) {
                if (num % primes[j] == 0) {
                    mask |= (1 << j);
                }
            }
            prime_masks[num] = mask;
        }
    }

    long calculate_power_of_2(int n) {
        // Calculate (2^n) % mod using bitwise operations to optimize the calculation.
        long res = 1, m = 2;
        while (n != 0) {
            if (n & 1) {
                res = (res * m) % mod;
            }
            m = (m * m) % mod;
            n >>= 1;
        }
        return res;
    }

    int goodSubsets(vector<int>& nums, int n) {
        int ones_count = 0;
        vector<int> prime_counts(31), dp(1024);

        // Initialize dp[0] to 1 because the empty set is a "good" subset.
        dp[0] = 1;

        // Count the number of occurrences of each number and the number of ones.
        for (int num : nums) {
            if (num == 1) {
                ones_count++;
            } else if (prime_masks[num] != 0) {
                prime_counts[num]++;
            }
        }

        // Compute the number of subsets that can be formed using each set of prime factors.
        for (int i = 0; i < 31; ++i) {
            if (prime_counts[i] == 0) {
                continue;
            }
            for (int j = 0; j < 1024; ++j) {
                if (j & prime_masks[i]) {
                    // If the current mask already includes the prime factors of i, skip it.
                    continue;
                }
                dp[j | prime_masks[i]] = (dp[j | prime_masks[i]] + dp[j] * (long)prime_counts[i]) % mod;
            }
        }

        // Calculate the total number of "good" subsets.
        long total_good_subsets = 0;
        for (int count : dp) {
            total_good_subsets = (total_good_subsets + count) % mod;
        }

        // Subtract 1 from the total number of "good" subsets because we don't want to include the empty set.
        total_good_subsets--;

        // If there are ones, multiply the total number of "good" subsets by 2^ones_count.
        if (ones_count != 0) {
            total_good_subsets = (total_good_subsets * calculate_power_of_2(ones_count)) % mod;
        }

        return (int)total_good_subsets;
    }
};

// C++ easy code 

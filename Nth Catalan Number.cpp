class Solution
{
public:
    // Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        // Define a constant for modular arithmetic to avoid overflow.
        const int mod = 1e9 + 7;
        
        // Create a vector to store the Catalan numbers.
        vector<long long> dp(n + 1, 0);
        
        // Initialize the first Catalan number as 1.
        dp[0] = 1;
        
        // Iterate over each index to calculate Catalan numbers up to 'n'.
        for(int i = 1; i <= n; i++)
        {
            // Calculate the Catalan number at index 'i'.
            for(int j = 0; j < i; j++)
            {
                // The Catalan number at index 'i' is the sum of products of
                // Catalan numbers at indices 'j' and 'i - j - 1'.
                dp[i] = (dp[i] + (dp[j] * dp[i - j - 1]) % mod) % mod; 
            }
        }
        
        // Return the nth Catalan number.
        return dp[n];
    }
};

//User function Template for C++

class Solution{
public:
    int longestPalinSubseq(string A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the diagonal elements to 1
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;

        // Iterate over the remaining upper triangle elements of the matrix
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                
                // If the characters at positions i and j are equal
                if(A[i] == A[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};

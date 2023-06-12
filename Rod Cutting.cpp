// User function Template for C++
class Solution{
public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                dp[j] = max(dp[j], price[i - 1] + dp[j - i]);
            }
        }
        
        return dp[n];
    }
};

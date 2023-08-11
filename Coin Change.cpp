class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>> dp(N, vector<long long> (sum + 1, 0));
        for(int i = 0; i < N; i++)
            dp[i][0] = 1;
            
        for(int i = 0; i < N; i++){
            for(int j = 1; j < sum + 1; j++){
                long long take, notake;
                take = notake = 0;
                
                if(j >= coins[i])
                    take = dp[i][j - coins[i]];
                    
                if(i > 0)
                    notake = dp[i - 1][j];
                    
                dp[i][j] = take + notake;
            }
        }
        
        return dp[N - 1][sum];
    }
};

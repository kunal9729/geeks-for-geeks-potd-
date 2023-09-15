class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < n; i++)  
            sum += arr[i];
            
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        if(!(sum & 1)){
            dp[n][sum / 2] = 1;
        }
        else{
            return 0;
        }
        
        for(int i = n - 1; i > -1; i--){
            for(int j = 0; j < sum + 1; j++){
                bool take, notake;
                
                take = notake = 0;
                
                if(j + arr[i] <= sum)
                    take = dp[i + 1][j + arr[i]];
                notake = dp[i + 1][j];
                
                dp[i][j] = take || notake;
            }
        }
        
        return dp[0][0];
    }
};

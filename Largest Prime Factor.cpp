class Solution{
public: 
    long long int largestPrimeFactor(int N){
        int ans;
        
        for(int i = 2; i * i <= N; i++){
            if(N % i == 0){
                ans = i;
                while(N % i == 0){
                    N /= i;
                }
            }    
        }
        
        if(N > 1)
            ans = max(ans, N);
            
            
        return ans;
    }
};

class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(long long N, long long R)
    {
        const int mod = 1e9 + 7;
        long long ans = 1;
        
        while(R){
            if(R & 1)
                ans = (ans * N) % mod;
                
            N = (N * N) % mod; 
                
            R >>= 1;
        }
        
        return ans;
    }

};

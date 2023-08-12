class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> lis(n + 1, 1e9);
        lis[0] = -1;
               
        for(int i = 0; i < n; i++){
            auto p = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            if(p < n + 1)
                lis[p] = a[i];    
        }
        
        for(int i = n; i > 0; i--){
            if(lis[i] != 1e9)
                return i;
        }
    }
};

class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int count = 0;
        for(int i = 0; i < n; i++)
            if(a[i] == 1)
                a[i] = -1, ++count;
            else
                a[i] = 1;
                
        int sum = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            sum += a[i];
            ans = max(ans, sum);
            
            if(sum < 0)
                sum = 0;
        }
        
        return ans + count;
    }
};

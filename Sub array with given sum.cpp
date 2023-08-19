class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(n == 1){
            if(arr[0] == s)
                return {1, 1};
            else
                return {-1};
        }
        
        int r = 0;
        int l = 0;
        
        long long sum = arr[0];
        
        while(r < n){
            if(sum < s){
                sum += arr[++r];
            }
            else if(sum > s){
                if(l == r){
                    ++l; ++r;
                    sum = arr[l];
                }
                else{
                    sum -= arr[l++];
                }
            }
            else{
                return {l + 1, r + 1};
            }
        }
        
        return {-1};
    }
};

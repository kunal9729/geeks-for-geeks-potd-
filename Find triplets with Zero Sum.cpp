class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr + n);
        
        for(int k = 0; k < n; k++){
            int i = 0;
            int j = n - 1;
            
            if(i == k)
                ++i;
            if(j == k)
                --j;
                
            while(i < j){
                if(arr[i] + arr[j] + arr[k] > 0)
                    --j;
                else if(arr[i] + arr[j] + arr[k] < 0)
                    ++i;
                else
                    return 1;
                    
                if(i == k)
                    ++i;
                if(j == k)
                    --j;                    
            }
        }
        
        return 0;
    }
};

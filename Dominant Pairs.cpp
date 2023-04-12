//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        
        int x=n/2;
        
        for(int i=x; i<n; i++){
            
            arr[i]=5*arr[i];
        }
        sort(arr.begin(),arr.begin()+x);
        
        int i=x,ans=0;
        
        while(i<n){
            
            int idx=lower_bound(arr.begin(),arr.begin()+x,arr[i])-arr.begin();
            
            if(idx<x) ans+=(x-idx);
            
            i++;
        }
        
        return ans;
        // Code here
    }  
};

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        
        int MAX = -1e9;
        
        for(int i = n - 1; i > -1; i--){
            MAX = max(MAX, a[i]);
            
            if(a[i] >= MAX)
                ans.push_back(a[i]);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

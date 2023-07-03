//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution {
public:
    int maxIndexDiff(int arr[], int n) {
        // Create two arrays to store prefix and suffix values
        vector<int> prefix(n), suffix(n);
        
        // Store the first element of the array in the prefix array
        prefix[0] = arr[0];
        
        // Store the last element of the array in the suffix array
        suffix[n - 1] = arr[n - 1];
        
        // Calculate the minimum value from the left for each element and store it in the prefix array
        for(int i = 1; i < n; i++){
            prefix[i] = min(prefix[i - 1], arr[i]);
        }
        
        // Calculate the maximum value from the right for each element and store it in the suffix array
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = max(suffix[i + 1], arr[i]);
        }
        
        // Initialize variables for indices and the answer
        int i, j, ans;
        i = j = ans = 0;
        
        // Compare the prefix and suffix values to find the maximum index difference
        while(j < n){
            if(prefix[i] <= suffix[j]){
                ans = max(ans, j - i);
                ++j;
            }
            else{
                ++i;
            }
        }
        
        // Return the maximum index difference
        return ans;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

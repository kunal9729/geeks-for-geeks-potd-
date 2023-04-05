//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> A) {
        // Code here
        
        sort(A.begin(), A.end());
        
        int b = A[N-1];
        
        // unordered map to keep track of the count of special numbers
        
        unordered_map<int, int> cd;
        
        int res = 0;
        
        for(int k = 0; k < N; k++) {
            
            // If  current element has already been processed, add its count to the result
            
            if(cd.find(A[k]) != cd.end()) {
                
                res+= cd[A[k]] + 1;
                
                if(cd[A[k]] == 1) {
                    
                    cd[A[k]] = 0;
                }
                
                continue; // next element
            }
            
            //  Otherwise, set the count of the current element to 1
            cd[A[k]] = 1;
            
            for(int a = A[k]*2; a <= b; a += A[k]) {
                
                cd[a] = 0; 
        }
    }
    
    return res;
    
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        

    int suffix[N];
    suffix[N - 1] = A[N - 1];
    
    // Calculate suffix array
    for (int i = N - 2; i >= 0; i--) {
        suffix[i] = min(suffix[i + 1], A[i]);
    }
    
    int maxLength = A[0];
    int validCuts = 0;
    
    // Iterate over A
    for (int i = 1; i < N; i++) {
        if (maxLength + suffix[i] >= K) {
            validCuts++;
        }
        maxLength = max(maxLength, A[i]);
    }
    
    return validCuts;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends

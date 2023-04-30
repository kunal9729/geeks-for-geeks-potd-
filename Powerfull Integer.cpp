//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    
public:   
    int powerfullInteger(int n, vector<vector<int>>& intervals, int k) {
    map<int, int> freqMap;
    for (auto interval : intervals) {
        int start = interval[0], end = interval[1];
        freqMap[start]++;
        freqMap[end + 1]--;
    }
    int prefixSum = 0;
    int candidate = -1;
    bool candidateFound = false;
    for (auto it : freqMap) {
        prefixSum += it.second; // prefix sum of frequency
        if (prefixSum >= k) {
            candidateFound = true;
            candidate = it.first;
        } else if (candidateFound) {
            candidate = it.first - 1; // previous element is the candidate
            candidateFound = false;
        }
    }
    return candidate;
} 



   
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends

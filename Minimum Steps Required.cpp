//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    
    int step1, step2;
    
    step1 = step2 = 0;
    
    if(str[0] == 'a')
    step1++;
    
    else
    step2++;
    
    for(int j = 1; j< str.size(); j++) {
        
        if(str[j] == str[j-1])
        continue;
        
        if(str[j] == 'a')
        step1++;
        
        else
        step2++;
    }
    
    return min(step1, step2) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends

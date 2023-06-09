//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        
        int n = S.length();
        unordered_map<char, int> solve;
        for (int i = 0; i < n; i++)
        {
            solve[S[i]]++;
        }
        int l = 0, r = n - 1;
        int dir = 0;

        while (l <= r)
        {
            if (dir == 0)
            {

                if (solve[S[l]] > 1)
                {
                    solve[S[l]]--;
                    S[l] = '#';
                    dir = 1;
                    l++;
                }
                else
                {
                    l++;
                }
            }
            if (dir == 1)
            {
                if (solve[S[r]] > 1)
                {
                    solve[S[r]]--;
                    S[r] = '#';
                    dir = 0;
                    r--;
                }
                else
                {
                    r--;
                }
            }
        }
        string ans;
        // for(int i=n-1; i>=0;i--){

        for (int i = 0; i < n; i++)
        {
            if (S[i] != '#')
            {
                ans.push_back(S[i]);
            }
        }
        if (dir == 1)
        {
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    bool isFrequencyUnique(int n, int arr[]) {
        std::unordered_map<int, int> frequencyMap;
        std::vector<int> frequencyCount(n + 1, 0);

        // Count the frequency of each element in the array
        for (int i = 0; i < n; i++) {
            frequencyMap[arr[i]]++;
        }

        // Count the frequency count
        for (const auto& entry : frequencyMap) {
            frequencyCount[entry.second]++;
        }

        // Check if any frequency count is greater than 1
        for (int i = 0; i < n + 1; i++) {
            if (frequencyCount[i] > 1) {
                return false;
            }
        }

        return true;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
public:
#define ll long long int

vector<long long> smallerSum(int n, vector<int>& nums) {
    // find the maximum value in the array
    int maxValue = *max_element(nums.begin(), nums.end());

    // create an array to store the frequency of each number
    int freq[maxValue+1] = {0};

    for (int i = 0; i < n; i++) {
        freq[nums[i]]++;
    }

    // calculate the prefix sum for each number in the array
    ll prefixSum[maxValue+1] = {0};
    ll currentSum = 0;

    for (int i = 1; i <= maxValue; i++) {
        prefixSum[i] = currentSum;
        currentSum += freq[i] * i; 
    }

    // calculate the sum of all elements smaller than the current element
    vector<ll> result;

    for (int i = 0; i < n; i++) {
        ll currentResult = prefixSum[nums[i]];
        result.push_back(currentResult);
    }

    return result;
}
};

//T.c O(n +  maxValue)
//S.c O(1)



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends

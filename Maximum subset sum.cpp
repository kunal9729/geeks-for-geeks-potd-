//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
public:
    long long findMaxSubsetSum(int N, std::vector<int>& A) {
       vector<vector<long long>> dp(N + 1, vector<long long>(2, -1));

        function<long long(int, int)> f = [&](int ind, int flag) {
            if (ind == N) return 0LL;
            if (dp[ind][flag] != -1) return dp[ind][flag];

            long long nottake = -1e9;
            if (flag == 0) {
                nottake = f(ind + 1, 1);
            }

            long long take = A[ind] + f(ind + 1, 0);
            return dp[ind][flag] = max(take, nottake);
        };

        return f(0, 0);
    }
};



 


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends

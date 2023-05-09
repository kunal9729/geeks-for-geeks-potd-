//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  #define MOD (int)(1e9+7)
   unordered_map<long, long> fibonacci{{0, 1}, {1, 1}};
   long long calculateFibonacci(long long n){
       if (fibonacci.find(n) != fibonacci.end())
        return fibonacci[n];
         long k = n / 2;
         long long fibonacci_k = calculateFibonacci(k);
         long long fibonacci_k_minus_1 = calculateFibonacci(k - 1);
         long long result;
          if (n % 2 == 0)
           result = (fibonacci_k * fibonacci_k + fibonacci_k_minus_1 * fibonacci_k_minus_1) % MOD;
            else
            
            result = (fibonacci_k * calculateFibonacci(k + 1) + fibonacci_k_minus_1 * fibonacci_k) % MOD;
            fibonacci[n] = result;
             return result;
             
   }
   
   int countStrings(long long int n) {
        return calculateFibonacci(n + 1);
        
   }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends

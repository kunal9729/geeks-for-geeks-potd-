// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
     
    vector<int> ans(n + 1);
    
    iota(ans.begin(), ans.end(), 0);
    
    for (int i = 2; i * i <= n; i++) {
        if (ans[i] == i) {
            for (int j = i + i; j <= n; j += i)
                ans[j] = min(ans[j], i);
        }
    }
    
    return ans;
       
    }
};

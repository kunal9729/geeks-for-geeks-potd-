
class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        vector<int> pre(N+1), res(N+1);
        
        partial_sum(A.begin(), A.end(), pre.begin() + 1);
        partial_sum(A.rbegin(), A.rend(), res.rbegin() + 1);
        
        for(int i = 1; i <= N; ++i) {
            
            if(pre[i-1] == res[i]) {
                
                return i;
            }
        }
        
        return -1;
    }
};

// Time Complexity = O(N^2)
// Space Complexity = O(N)


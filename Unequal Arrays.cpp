
class Solution {
    #define ll long long
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        
        ll res = 0;
        vector<int> oddA, evenA, oddB, evenB;
        for(int i=0; i<N; i++){
            res += A[i]-B[i];
            if(abs(A[i])%2==0) 
            evenA.push_back(A[i]);
            else 
            oddA.push_back(A[i]);
            if(abs(B[i])%2==0)
            evenB.push_back(B[i]);
            else
            oddB.push_back(B[i]);
        }
        
        if(res != 0 || oddA.size() != oddB.size()){
            return -1;
        }
        
        ll ans = 0;
        sort(oddA.begin(), oddA.end());
        sort(oddB.begin(), oddB.end());
        for(int i=0; i<oddA.size(); i++){
            ans += abs(oddA[i]- oddB[i])/2;
        }
        
        sort(evenA.begin(), evenA.end());
        sort(evenB.begin(), evenB.end());
        for(int i=0; i<evenA.size(); i++){
            ans += abs(evenA[i]- evenB[i])/2;
        }
        
        return ans/2;
    }
};

//T.c O(nlogn)
//S.c O(n)


// User function Template for C++
// T.C = O(n)
// S.C = O(1)


class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        
        int ans =0, count =0;
        vector<pair<int, int>> gfg(N*2);
        
        for(int j=0; j<N; j++){
            gfg[2*j] = make_pair(lines[j][0], 1);
            gfg[2*j+1] = make_pair(lines[j][1]+1, -1);
        }
        
        sort(gfg.begin(), gfg.end());
        
        for(int j=0; j<N*2; j++){
            
            count += gfg[j].second;
            
            ans = max(ans, count);
        }
        
        return ans;
        // Code here
    }
};

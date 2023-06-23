class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        vector<int> f(26, 0);
        
        for(auto i : tasks)
            ++f[i - 'A'];
            
        int nax = -1;
        int count = 0;
        
        for(int i = 0; i < 26; i++){
            if(f[i] == nax)
                ++count;
            else if(f[i] > nax){
                nax = f[i];
                count = 1;
            }
        }
        
        int ans = max(N, nax + (nax - 1) * K + count - 1);
        
        return ans;
    }
};

class Solution {
  public:
    int setBits(int N) {
        int ans = 0;
        
        while(N){
            ++ans;
            N &= (N - 1);
        }
        
        return ans;
    }
};

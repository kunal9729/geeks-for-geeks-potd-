// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> &color, vector<int> &radius) {
        stack<pair<int, int>> s;
        for(int j=0; j<N; j++){
        int f = 1;
        pair<int, int> current = {color[j], radius[j]};
        while(!s.empty() && s.top() == current){
            f = 0;
            s.pop();
        }
        if(f==1)
        s.push(current);
        
        }
          
        return s.size();
    }
};

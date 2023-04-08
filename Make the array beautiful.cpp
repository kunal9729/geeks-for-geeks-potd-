

class Solution {
  public:
    vector<int> makeBeautiful(vector<int>& arr) {
        // code here
        
        int b = -1;
        for(int a = 0; a < arr.size(); ++a) {
            if( b >= 0 && ((arr[b] < 0) != (arr[a] < 0)))
            b--;
            else
            arr[++b] = arr[a];
        }
        
        arr.resize(b+1);
        
        return arr;
    }
};

// T.C O(n)
// S.C O(1)






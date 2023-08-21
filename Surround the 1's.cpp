class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
        int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
        
        int ans = 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
                
            return matrix[x][y] == 0;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]){
                    int cur = 0;
                    for(int k = 0; k < 8; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        
                        cur += valid(x, y);
                    }
                    
                    if(cur)
                        ans += !(cur & 1);
                }
            }
        }
        
        return ans;
    }
};

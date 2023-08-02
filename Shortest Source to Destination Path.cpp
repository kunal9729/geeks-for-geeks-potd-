class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0)
            return -1;
            
        vector<vector<int>> d(N, vector<int> (M, 500));
        d[0][0] = 0;
        
        queue<pair<int,int>> q;
        q.push({0, 0});
        
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                auto valid = [&]() -> bool {
                    if(nx < 0 or nx >= N or ny < 0 or ny >= M)
                        return 0;
                    
                    return A[nx][ny] == 1;
                };
                
                if(valid() and d[nx][ny] > d[x][y] + 1){
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        return d[X][Y] == 500 ? -1 : d[X][Y];
    }
};

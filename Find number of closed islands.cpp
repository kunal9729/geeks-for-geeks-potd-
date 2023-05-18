//User function Template for C++

#include <vector>
#include <functional>

class Solution {
public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        vector<vector<bool>> vis(N, vector<bool>(M, false));

        auto valid = [&](int x, int y) -> bool {
            if (x < 1 || x >= N - 1 || y < 1 || y >= M - 1)
                return false;

            if (vis[x][y] || !matrix[x][y])
                return false;

            return true;
        };

        auto closed = [&](int x, int y) -> bool {
            if (x == 0 || x == N - 1 || y == 0 || y == M - 1)
                if (matrix[x][y])
                    return false;

            return true;
        };

        std::function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            vis[x][y] = true;

            bool ok = true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!closed(nx, ny)) {
                    ok = false;
                }

                if (valid(nx, ny)) {
                    ok &= dfs(nx, ny);
                }
            }

            return ok;
        };

        int ans = 0;
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (valid(i, j)) {
                    ans += dfs(i, j);
                }
            }
        }

        return ans;
    }

private:
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, -1, 1};
};

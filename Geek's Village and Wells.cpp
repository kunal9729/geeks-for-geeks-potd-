//User function Template for C++

class Solution{
public:
// dx and dy arrays represent the four possible directions
// that can be taken from a given position
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// This function returns a matrix of distances from each 'H' position to the nearest 'W' position
vector<vector<int>> chefAndWells(int numRows, int numCols, vector<vector<char>> &grid)
{
    vector<vector<int>> distances(numRows, vector<int>(numCols, -1)); // initialize all distances to -1
    vector<vector<bool>> visited(numRows, vector<bool>(numCols, false)); // initialize all cells as unvisited
    queue<pair<int, int>> q;

    // Add all 'W' positions to the queue and mark them as visited
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            if (grid[row][col] == 'W')
            {
                q.push({row, col});
                visited[row][col] = true;
            }
            if (grid[row][col] == 'W' || grid[row][col] == '.' || grid[row][col] == 'N')
            {
                distances[row][col] = 0;
            }
        }
    }

    int currDist = 2;
    while (!q.empty())
    {
        int currSize = q.size();
        while (currSize--)
        {
            auto currPos = q.front();
            q.pop();
            int row = currPos.first, col = currPos.second;
            for (int dir = 0; dir < 4; dir++)
            {
                int newRow = row + dx[dir], newCol = col + dy[dir];
                if (newRow >= 0 && newCol >= 0 && newRow < numRows && newCol < numCols && !visited[newRow][newCol] && grid[newRow][newCol] != 'N')
                {
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                    if (grid[newRow][newCol] == 'H')
                    {
                        distances[newRow][newCol] = currDist;
                    }
                }
            }
        }
        currDist += 2;
    }

    return distances;
}
    
};

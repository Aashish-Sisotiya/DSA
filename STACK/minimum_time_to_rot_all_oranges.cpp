class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                    time[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        if (q.size() >= 0 && fresh == 0)
        {
            return 0;
        }
        if (q.size() == 0 && fresh > 0)
        {
            return -1;
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            pair p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = p.first + delRow[i];
                int newCol = p.second + delCol[i];
                if ((newRow >= 0 && newRow < n && newCol < m && newCol >= 0) && !visited[newRow][newCol] && grid[newRow][newCol] == 1)
                {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = true;
                    if (time[newRow][newCol] >= time[p.first][p.second] + 1)
                    {
                        time[newRow][newCol] = time[p.first][p.second] + 1;
                    }
                }
            }
        }

        int minTime = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && visited[i][j])
                {
                    minTime = max(minTime, time[i][j]);
                }
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    return -1;
                }
            }
        }

        return minTime;
    }
};
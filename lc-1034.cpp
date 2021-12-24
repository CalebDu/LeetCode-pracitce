#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using std::vector;
using std::pair;
using std::queue;

class Solution
{
    using PII = pair<int, int>;
    vector<PII> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j, int origin, vector<PII> &boundary)
    {
        int m = grid.size(), n = grid[0].size();
        bool isBoundary = false;
        for (auto [x, y] : direct)
        {
            int nx = i + x, ny = j + y;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != origin)
                isBoundary = true;
            else if (!vis[nx][ny])
            {
                vis[nx][ny] = true;
                dfs(grid, vis, nx, ny, origin, boundary);
            }
        }
        if (isBoundary)
            boundary.emplace_back(i, j);
    }
    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j, int origin, vector<PII> &boundary)
    {
        queue<PII> q;
        int m = grid.size(), n = grid[0].size();
        q.push({i, j});
        while (!q.empty())
        {
            bool isBoundary = false;
            auto [i, j] = q.front();
            q.pop();
            for (auto [x, y] : direct)
            {
                int nx = x + i, ny = y + j;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != origin)
                    isBoundary = true;
                else if (!vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            if(isBoundary)
                boundary.emplace_back(i, j);
        }
    }

public:
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        int m = grid.size(), n = grid[0].size();
        int origin = grid[row][col];
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<PII> boundary;
        vis[row][col] = true;
        // dfs(grid, vis, row, col, origin, boundary);
        bfs(grid, vis, row, col, origin, boundary);
        for (auto [x, y] : boundary)
            grid[x][y] = color;
        return grid;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<vector<int>> grid = {{1, 2, 2}, {2, 3, 2}};
    sol->colorBorder(grid, 0, 1, 3);
}
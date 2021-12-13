#include<cmath>
#include<iostream>
#include<vector>
using std::vector;
using std::max;
using std::min;

class Solution{
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<int> col(n), row(n);
        for(int i=0; i < n; i++)
        {
            for(int j=0; j < n; j++)
            {
                col[j] = max(col[j], grid[i][j]);
                row[i] = max(row[i], grid[i][j]);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans += min(col[j], row[i]) - grid[i][j];
            }
        }
        return ans;
    }
};
#include <iostream>
#include <vector>
#include <string>
#include <functional>
using std::string;
using std::vector;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m ,false));
        std::function<bool(int, int, int)> dfs = [&](int i, int j, int idx)
        {
            if(idx ==word.size())
                return true;
            if(i<0||i>=n||j<0||j>=m||vis[i][j]||word[idx]!=board[i][j])
                return false;
            vis[i][j] = true;
            bool ret = dfs(i-1,j, idx + 1)||dfs(i+1, j, idx+1)||dfs(i, j-1, idx+1)||dfs(i, j+1, idx+1);
            vis[i][j] =false;
            return ret;
        };
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(dfs(i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    Solution sol;
    vector<vector<char>> v = {{'a', 'a', 'a'}, {'b', 'c', 'c'}};
    sol.exist(v, "abc");
    return 0;
}
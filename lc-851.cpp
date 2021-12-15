#include<algorithm>
#include<vector>
#include<functional>

using std::vector;

class Solution
{

public:
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet) 
    {
        int n = quiet.size();
        vector<vector<int>> dict(n);
        vector<int> ans(n, -1);
        for(auto& v: richer)
        {
            dict[v[1]].push_back(v[0]);
        }
        std::function<void(int)> dfs = [&](int x)
        {
            if(ans[x]!=-1)
                return;
            ans[x] = x;
            for(int rich: dict[x])
            {
                dfs(rich);
                if(quiet[ans[x]]> quiet[ans[rich]])
                {
                    ans[x] = ans[rich];
                }
            }
        };
        for(int i=0; i < n; i++)
        {
            dfs(i);
        }
        return ans;
    }
};
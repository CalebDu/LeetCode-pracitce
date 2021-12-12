#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;
class Solution 
{
private:
    vector<vector<int>> ans;
    vector<int> path;
    void dfs(vector<bool>& vis, vector<int>& nums, int n)
    {
        if(n==nums.size())
        {
            ans.push_back(path);
            return;    
        }  
        for(int i=0; i<nums.size(); i++)
        {
            if(!vis[i])
            {
                vis[i] = true;
                path.push_back(nums[i]);
                dfs(vis, nums, n+1);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool> vis(n, false);
        dfs(vis, nums, 0);
        return ans;
    }
};

class Solution2 
{
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        using std::sort;
        using std::next_permutation;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        do
        {
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end())); 
        return ans;
    }
};
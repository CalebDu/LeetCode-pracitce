#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> tmp;
    vector<vector<int>> ans;
    void dfs(vector<int> &nums, int k, int target, int index, int sum)
    {
        if (k==0)
        {
            if (target == sum)
                ans.push_back(tmp);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            if (i + k - 1 >= nums.size())
                break;
            else if (sum + k * nums[i] >= target)
                break;
            else if (sum + k * nums.back() <= target)
                break;
            else if (i > index && nums[i] == nums[i - 1])
                continue;
            tmp.push_back(nums[i]);
            dfs(nums, k - 1, target, i + 1, sum + nums[i]);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 4, target, 0, 0);
        return ans;
    }
};

int main()
{
    vector<int> v = {1, 0, -1, 0, -2, 2};
    Solution sol;
    sol.fourSum(v, 0);
    return 0;
}
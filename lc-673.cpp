#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int maxLen = 1, maxCount = n;
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[j] + 1 == maxLen)
                        maxCount++;
                    else if (dp[j] + 1 > maxLen)
                    {
                        maxLen = dp[j] + 1;
                        maxCount = 1;
                    }
                }
            }
        }
        return maxCount;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> nums = {1, 2, 4, 3, 5, 4, 7, 2};
    sol.findNumberOfLIS(nums);

    return 0;
}

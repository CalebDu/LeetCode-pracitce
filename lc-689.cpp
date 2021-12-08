#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        vector<int> ans;
        int sum1 = 0, sum2 = 0, sum3 = 0;
        int maxSum1 = 0, maxSum12 = 0, totalMaxSum = 0;
        int idx[4];
        for (int i = 2 * k; i < nums.size(); i++)
        {
            sum1 += nums[i - 2 * k];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= 3 * k - 1)
            {
                if (sum1 > maxSum1)
                {
                    maxSum1 = sum1;
                    idx[0] = i - 3 * k + 1;
                }
                if (maxSum1 + sum2 > maxSum12)
                {
                    idx[1] = idx[0];
                    idx[2] = i - 2 * k + 1;
                    maxSum12 = maxSum1 + sum2;
                }
                if (maxSum12 + sum3 > totalMaxSum)
                {
                    idx[3] = i - k + 1;
                    totalMaxSum = maxSum12 + sum3;
                    ans = {idx[1], idx[2], idx[3]};
                }
                sum1 -=nums[i - 3*k +1];
                sum2 -=nums[i - 2*k +1];
                sum3 -=nums[i -k +1];
            }
        }
        return ans;
    }
};
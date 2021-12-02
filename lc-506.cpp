#include <string>
#include <vector>
#include <algorithm>
#include <utility>

class Solution
{
public:
    // * TIME COMPLEXITY O(N)
    // * SPACE COMPLEXITY O(N)
    std::vector<std::string> findRelativeRanks(std::vector<int> &scores)
    {
        int n = scores.size();
        std::vector<std::string> ans(n), dict = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        std::vector<std::pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.emplace_back(std::make_pair(-scores[i], i));
        }
        std::sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++)
        {
            if (i >= 3)
                ans[arr[i].second] = std::to_string(i + 1);
            else
                ans[arr[i].second] = dict[i];
        }
        return ans;
    }
};

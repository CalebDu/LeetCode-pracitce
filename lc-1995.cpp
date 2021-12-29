#include<iostream>
#include<vector>
#include<unordered_map>
using std::vector;
using std::unordered_map;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int a,b,c,d;
        int n = nums.size();

        unordered_map<int, int> cnt;
        int ans = 0;

        for (int b = n - 3; b >= 1; b--) {
            int c = b + 1;
            for (int d = c + 1; d < n; d++) {
                cnt[nums[d]-nums[c]]++;
            }
            for (int a = 0; a < b; a++) {
                ans += cnt[nums[a]+nums[b]];
            }
        }

        return ans;
    }
};


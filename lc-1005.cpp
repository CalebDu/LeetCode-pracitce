#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto itr = lower_bound(nums.begin(), nums.end(), 0);
        if(itr==nums.end()) itr = nums.end()-1;
        int idx = distance(nums.begin(), itr);
        int i, min_pos = nums[idx], min_idx = idx;
        for( i=0; i<idx && k>0; i++, k--)
        {
            nums[i] *= -1;
            if(nums[i]<min_pos)
            {
                min_idx = i;
                min_pos = nums[i];
            }
        }
        while(k>0)
        {
            nums[min_idx] *= -1;
            k--;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size(), ans = 0;
        std::sort(ages.begin(), ages.end());
        int left = 0, right = 0;
        for(int age: ages)
        {
            if(age<15)
                continue;
            while(ages[left] <= age * 0.5 +7)
                left++;
            while(right < n - 1&&ages[right+1] <= age) 
                right++;
            ans += right - left; 
        }
        return ans;
    }
};
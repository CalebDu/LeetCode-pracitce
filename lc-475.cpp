#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


// Time complexity (m + n)logm
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;
        sort(heaters.begin(), heaters.end());
        for(int house : houses)
        {
            int j = upper_bound(heaters.begin(), heaters.end(), house) - heaters.begin();
            int i = j -1;
            int leftRadius = j>=heaters.size()? INT_MAX: heaters[j] - house;
            int rightRadius = i<0? INT_MAX: house - heaters[i];
            ans = max(min(leftRadius, rightRadius), ans);
        }
        return ans;
    }
};
class Solution2 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for(int i=0, j=0; i<houses.size(); i++)
        {
            int currRadius = abs(houses[i] - heaters[j]);
            while(j<heaters.size() - 1&& abs(houses[i]-heaters[j])>= abs(houses[i]-heaters[j+1])) 
            {
                currRadius = abs(houses[i] - heaters[j+1]);
                j++;
            }
            ans = max(ans, currRadius);
        }
        return ans;
    }
};
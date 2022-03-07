#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> win;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            win.insert(nums[i]);
            if(win.size()==k)
                ans.push_back(*win.end());
            else if(win.size()>k){
                win.erase(win.find(nums[i-k]));
                ans.push_back(*win.end());
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> v = {1,3,-1,-3,5,3,6,7};
    auto ans = sol.maxSlidingWindow(v, 3);
    ostream_iterator<int> out(cout, " ");
    copy(ans.begin(), ans.end(), out);
    return 0;
}
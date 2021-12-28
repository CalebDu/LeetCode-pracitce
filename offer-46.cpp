#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;
class Solution {
public:
    int translateNum(int num) {

        string s = std::to_string(num);
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<=s.size(); i++)
        {
            int x = stoi(s.substr(i-2, 2));
            dp[i] = dp[i - 1] + ((x<=25&&s[i-2]!='0')? dp[i-2]: 0);
        }
        return dp.back();
    }
};
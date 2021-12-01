#include<iostream>
#include<vector>
#include<string>
#include<cmath>

class Solution
{
public:
    int maxpower(std::string s)
    {
        int cur_ans = 1, ans = 1;
        for(int i=1; i<s.size(); i++)
        {
            if(s[i]==s[i-1])
            {
                cur_ans++;
            }
            else 
            {
                ans = std::max(ans, cur_ans);
                cur_ans = 1;
            }
        }
        return std::max(cur_ans, ans);
    }
};
#include<string>

class Solution
{
public:
    std::string truncateSentence(std::string s, int k)
    {
        std::string ans = "";
        int wStart = 0, wEnd = 0;
        for(; wEnd<s.size(); wEnd++)
        {
            if(s[wEnd]==' ')
            {
                std::string word = s.substr(wStart, wEnd - wStart);
                wStart = wEnd + 1;
                ans += word;
                if(--k>0)
                    ans += " ";
                else 
                    break;
            }
        }
        if(k>0)
            ans += s.substr(wStart, wEnd - wStart);
        return ans;
    }
};
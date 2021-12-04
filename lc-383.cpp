#include<iostream>
#include<vector>


class Solution
{
public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        std::vector<int> dict(26);
        for(char c: magazine)
            dict[c-'a']++;
        for(char c:ransomNote)
        {
            if(--dict[c-'a']<0)
                return false;
        }
        return true;
    }
};
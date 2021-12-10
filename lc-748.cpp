#include <iostream>
#include <cctype>
#include <vector>
using std::string;
using std::vector;
class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        int shortest = INT_MAX;
        string ans;
        vector<int> dict(26, 0);
        for (char c : licensePlate)
        {
            if (isalpha(c))
                dict[tolower(c) - 'a']++;
        }
        for (string word : words)
        {
            vector<int> tmp(dict);
            int len = 0;
            bool isContinue = false;
            for (char c : word)
            {
                if (--tmp[c - 'a'] >= 0)
                    len++;
            }
            for (int cnt : tmp)
            {
                if (cnt > 0)
                {
                    isContinue = true;
                    break;
                }
                    
            }
            if(isContinue)
                continue;
            if (word.size() - len < shortest)
            {
                shortest = word.size() - len;
                ans = word;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> words({"of"});
    string ans = sol.shortestCompletingWord("Ah71752", words);
    std::cout << ans;
    return 0;
}

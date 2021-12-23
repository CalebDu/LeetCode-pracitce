#include<iostream>
#include<vector>
#include<unordered_set>

using std::string;
class Solution
{
public:
    string longestDupSubstring(string s)
    {
        unsigned long long PRIME = 31;
        int n = s.size();
        int l=1, r=n-1;
        int pos = -1, len = 0;
        auto find = [&](int mid)
        {
            unsigned long long hash = 0, power = 1;
            for(int i=0; i<mid; i++)
            {
                hash = hash*PRIME + (s[i] - 'a');
                power *= PRIME;
            }
            std::unordered_set<unsigned long long> set = {hash};
            for(int i=mid; i<n; i++)
            {
                hash = hash * PRIME - power*(s[i-mid] - 'a') + s[i] - 'a';
                if(set.count(hash))
                    return i - mid + 1;
                set.insert(hash);
            }
            return -1;
        };
        while(l<=r)
        {
            int mid = l + (r - l) / 2;
            int ret = find(mid);
            if(ret == -1)
                r = mid - 1;
            else
            {
                pos = ret;
                len = mid;
                l = mid + 1;
            }
        }
        if(pos==-1)
            return "";
        return s.substr(pos, len);
    } 
};
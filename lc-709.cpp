#include <iostream>
#include <string>

using std::string;

class Solution
{
public:
    string toLowerCase(string s)
    {
        for(char& c: s){
            c = std::tolower(c);
            c = (1<<5)|c;
        }
        return s;
    }
};
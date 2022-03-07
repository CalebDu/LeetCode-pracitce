#include <iostream>
#include <string>
#include <map>
using namespace std;


class Solution {
private:
    map<int, int> calendar = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11,30}, {12, 31}};
    
    int parse_date(string date)
    {
        int year = stoi(date.substr(0, 4)), mounth = stoi(date.substr(5,2)), day = stoi(date.substr(8, 2));
        int ret = 0;
        for(int i = 0; i < year; i++)
        {
            if(check(i))
                ret += 366;
            else
                ret += 365;
        }
        for(int i = 1; i < mounth; i++)
        {
            ret += calendar[i];
            if(check(year) && i==2)
                ret += 1;
        }
        return ret + day;
    }
    
    bool check(int year){
        if(year%100!=0)
            return year%4 == 0;
        else 
            return year%400 == 0;
        
    }
public:
    int daysBetweenDates(string date1, string date2) {
        int day1 = parse_date(date1), day2 = parse_date(date2);

        return abs(day1 - day2);
    }
};


int main()
{
    Solution sol;
    sol.daysBetweenDates("2020-01-15", "2019-12-31");
    return 0;
}
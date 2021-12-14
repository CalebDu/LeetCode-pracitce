#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using std::vector;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto cmp = [](const auto& v1, const auto& v2)
        {
            return v1[1]<v2[1];
        };
        std::sort(courses.begin(), courses.end(), cmp);
        std::priority_queue<int> q;
        int time = 0;
        for(auto& course: courses)
        {
            int duration = course[0], ddl = course[1];
            if(time+duration<=ddl)
            {
                time += duration;
                q.push(duration);
            }
            else if(!q.empty() && q.top()>duration)
            {
                time -= q.top() - duration;
                q.pop();
                q.push(duration);
            }
        }
        return q.size();
    }
};
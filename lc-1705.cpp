#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using std::vector;
using std::pair;
using PII = pair<int, int>;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        std::priority_queue<PII, vector<PII>, std::greater<PII> > q;
        int n=apples.size(), i = 0, ans = 0;
        while(i < n)
        {
            while(!q.empty()&&q.top().first<=i)
                q.pop();

            int rotten = i + days[i];
            int apple = apples[i];
            if(apple>0)
                q.push({rotten, apple});
            if(!q.empty())
            {
                PII curr = q.top();
                q.pop();
                curr.second--;
                if(curr.second)
                    q.push(curr);
                ans ++;
            }
            i++;
        } 
        while(!q.empty())
        {
            while(!q.empty() && q.top().first<=i)
                q.pop();
            if(q.empty())
                break;
            auto [rotten, apple] = q.top();
            q.pop();
            apple = min(rotten - i, apple);
            i+=apple;
            ans+=apple;
        }
        return ans;
    }
};
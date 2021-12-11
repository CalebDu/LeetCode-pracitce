#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

class TopVotedCandidate
{
private:
  using PII = pair<int, int>;
  vector<PII> winner;
  int max_person;

public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times)
  {
    max_person = *max_element(persons.begin(), persons.end());
    vector<int> counts(max_person+1, 0);
    int max_vote = 0;
    for(int i=0; i<persons.size(); i++)
    {
      if(++counts[persons[i]]>=max_vote)
      {
        max_vote = counts[persons[i]];
        winner.emplace_back(times[i], persons[i]);
      }
    }
  }

  int q(int t)
  {
    auto it = lower_bound(winner.begin(), winner.end(), make_pair(t+1, 0));
    return (--it)->second;
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
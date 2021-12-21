#include<vector>
#include<iostream>
using std::vector;

class Solution {
private:
    vector<vector<int>> P = {{1, 1}, {1, 0}};
    const int MOD  = 1000000007;
    vector<vector<int>> matmul(vector<vector<int>>& m1, vector<vector<int>>& m2)
    {
        int n = m1.size();
        vector<vector<int>> ret(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                for(int k=0; k<n; k++)
                {
                    ret[i][j] = (0L+ret[i][j]+ 1L*m1[i][k]*m2[k][j])%MOD;
                }
            }
        }
        return ret;
    }
public:
    int fib(int n) {
        if(n==0)
            return 0;
        vector<vector<int>> m = P;
        vector<vector<int>> ans = {{1, 0}, {0, 1}};
        n = n-1;
        while(n)
        {
            if(n%2==1)
            {
                ans = matmul(ans, m);
            }
            m = matmul(m, m);
            n = n/2;
        }
        return (0L + ans[1][0] + ans[1][1])%MOD;
    }
};

int main()
{
    int n=50;
    Solution sol;
    sol.fib(n);
    return 0;
}
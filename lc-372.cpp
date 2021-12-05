#include <iostream>
#include <vector>
class Solution
{
private:
    const int MOD = 1337;
    int pow(int x, int n)
    {
        int res = 1;
        while (n)
        {
            if (n % 2)
                res = (1L * res * x) % MOD;
            x = (1L * x * x) % MOD;
            n /= 2;
        }
        return res;
    }

public:
    int superPow(int a, std::vector<int> &b)
    {
        int ans = 1;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            int exp = b[i];
            ans = (1L * ans * pow(a, exp)) % MOD;
            a = pow(a, 10);
        }
        return ans;
    }
};
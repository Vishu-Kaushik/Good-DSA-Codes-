#include <iostream>
using namespace std;

// Recursive solution

int getMin(int coins[], int n, int val)
{
    if (n == 0)
    {
        return 0;
    }
    int res = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if (val - coins[i] >= 0)
        {
            int subres = getMin(coins, n, val - coins[i]);
            if (res != INT16_MAX)
            {
                res = min(res, subres + 1);
            }
        }
    }
    return res;
}

// DP based solution using Tabulation method
// Time complexity is theta(n*val) and auxiliary space is theta(val)
int getMin1(int coins[], int n, int val)
{
    int dp[val + 1] = {INT16_MAX};
    dp[0] = 0;
    for (int i = 1; i <= val; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                int subres = dp[i - coins[j]];
                if (subres != INT16_MAX)
                {
                    dp[i] = min(dp[i], subres + 1);
                }
            }
        }
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{

    return 0;
}

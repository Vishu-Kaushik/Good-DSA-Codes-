#include <iostream>
#include <vector>
using namespace std;

// Recursive solution --> Time complexity is exponential which is O(3^n)

int maxCuts(int n, int a, int b, int c)
{
    if (n < 0)
    {
        return -1;
    }
    if (n == 0)
    {
        return 0;
    }
    int x = maxCuts(n - a, a, b, c);
    int y = maxCuts(n - b, a, b, c);
    int z = maxCuts(n - c, a, b, c);
    int res = max(x, max(y, z));
    if (res == -1)
    {
        return res;
    }
    else
    {
        return (res + 1);
    }
}

// DP based solution using Tabulation method so the time complexity is theta(n) and auxiliary space is theta(n)

int maxCutsDp(int n, int a, int b, int c)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        if ((i - a) >= 0)
        {
            dp[i] = max(dp[i], dp[i - a]);
        }
        if ((i - b) >= 0)
        {
            dp[i] = max(dp[i], dp[i - b]);
        }
        if ((i - c) >= 0)
        {
            dp[i] = max(dp[i], dp[i - c]);
        }
        if (dp[i] != -1)
        {
            dp[i]++;
        }
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

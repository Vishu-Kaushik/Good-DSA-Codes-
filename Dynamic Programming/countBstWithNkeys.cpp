#include <iostream>
using namespace std;
// TC= O(N^2) and AS=O(N )
int count(int n)
{
    int dp[n + 1] = {0};
    dp[0] = 1;
    // i varies the number of keys
    for (int i = 1; i <= n; i++)
    {
        // j becomes the root node
        for (int j = 0; j <= i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

// Also can be solved using catalan number series which is (2n!/(n+1*n!))

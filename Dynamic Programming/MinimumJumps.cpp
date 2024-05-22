#include <iostream>
using namespace std;
// Recursive solution which has time complexity of O()
// IDEA --> Here we check that can we reach to (n-1)th index from the current ith index and then take the min. number of jumps
int minJumps(int arr[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    int res = INT16_MAX;
    for (int i = 0; i <= n - 2; i++)
    {
        if (i + arr[i] >= n - 1)
        {
            int subres = minJumps(arr, i + 1);
            if (subres != INT16_MAX)
            {
                res = min(res, subres + 1);
            }
        }
    }
    return res;
}

// Dp based solution Which has time complexity of theta(n^2) and auxiliary space as theta(n)

int minJump(int arr[], int n)
{
    int dp[n] = {INT16_MAX};
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] + j >= i)
            {
                if (dp[i] != INT16_MAX)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    return dp[n - 1];
}

#include <iostream>
#include <utility>
using namespace std;

// THis is a  iterative solution and Time Complexity is O(n*sum) = auxiliary space
// We do not take dp[n+1][sum+1] becoz for a given sum we do not consider every coin but for a given coin we
//  go through every sum and that leads to extra solution in our matrix
int coinChange(int coin[], int n, int sum)
{
    int dp[sum + 1][n + 1]; // No. of combinations we can get with sum i and coins from 1 to j
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (coin[j - 1] <= i)
            {
                dp[i][j] += dp[i - coin[j - 1]][j];
            }
        }
    }
    return dp[sum][n];
}
// Recursive Solution --> In this we start comparing sum from the last element in the coins array
// Idea --> // Either we include a coin or not include
// Given that a single coin is given infinite number of times
int coin1(int coins[], int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    int res = coin1(coins, n - 1, sum); // THis is not including coin
    if (coins[n - 1] <= sum)
    {
        res = res + coin1(coins, n, sum - coins[n - 1]); // case of including a coin
    }
    return res;
}

int main(int argc, char const *argv[])
{

    return 0;
}

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

// Recursive solution with Time Complexity of theta(2^n)

int subsetSum(int arr[], int n, int sum)
{
    if (n == 0)
    {
        return (sum == 0) ? 1 : 0;
    }
    return subsetSum(arr, n - 1, sum) + subsetSum(arr, n - 1, sum - arr[n - 1]);
}

// Optimized solution -- using dynamic programming

/* Idea --> We make 2d vector as two parameters are changing which is size and sum
dimensions of 2d vector are n+1 and sum+1

dp[n+1][sum+1]
where dp[i][j] = Count of subsets in arr[0....i-1] with sum j
Time complexity is theta(n*sum) and space complexity is also theta(n*sum)

*/



int countSubset(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
            }
        }
    }
    return dp[n][sum];
}

int main(int argc, char const *argv[])
{

    return 0;
}
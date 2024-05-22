#include <iostream>
using namespace std;

// Recursive Solution where time complexity is O(2^n)
int knapsack(int w, int wt[], int val[], int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] > w)
    {
        return knapsack(w, wt, val, n - 1);
    }
    else
    {
        return max(knapsack(w, wt, val, n - 1), val[n - 1]                                      // Not including an element case
                                                    + knapsack(w - wt[n - 1], wt, val, n - 1)); // Including an element case
    }
}

//  For a dp based solution  the number of parameters changing are two n and w so the dimension of dp array will be 2 and parameters are from 0 to n-1 and from 0 to w-1
// here dp[i][j] = maximum value that we can collect with first 'i' items and knapsack capacity 'j'
// Auxiliary space is theta(nw) and TC is also theta(nw)
int knapSack(int w, int wt[], int val[], int n)
{
    int dp[n + 1][w + 1];
    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }
    return dp[n][w];
}

int main(int argc, char const *argv[])
{
    int wt[] = {5, 4, 6, 3};
    int val[] = {10, 40, 30, 50};
    int w = 10;
    int n = 4;
    cout << knapsack(w, wt, val, n);
    return 0;
}

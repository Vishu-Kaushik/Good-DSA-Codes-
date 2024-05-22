#include <iostream>
#include <math.h>
using namespace std;
// We need to find the minimun number of attempts to find the threshold floor under the worst case (max value of the two calls (break and not break))
// f--> floor and e--> egg
int eggDrop(int f, int e)
{
    if (f == 1 || f == 0)
    {
        return f;
    }
    if (e == 1)
    {
        return f;
    }
    int m = INT16_MAX;
    for (int i = 1; i <= f; i++)
    {
        // int x1 = eggDrop(i - 1, e - 1);
        // int x2 = eggDrop(f - i, e);
        int temp = max(eggDrop(i - 1, e - 1), eggDrop(f - i, e));
        m = min(m, temp);
    }
    return m + 1;
}
// Dynamic Programming solution
// Time complexity is O(ef^2) and auxiliary space (fe)
int eggDropsss(int f, int e)
{
    int dp[f + 1][e + 1];
    for (int i = 1; i <= e; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    for (int i = 1; i <= f; i++)
    {
        dp[i][1] = i;
    }
    for (int i = 2; i <= f; i++)
    {
        for (int j = 2; j <= e; j++)
        {
            dp[i][j] = INT16_MAX;
            for (int x = 1; x <= i; x++)
            {
                dp[i][j] = min(dp[i][j], 1 + max(dp[x - 1][j - 1], dp[i - x][j]));
            }
        }
    }
    return dp[f][e];
}
int main(int argc, char const *argv[])
{
    int f = 6;
    int e = 2;
    cout << eggDropsss(6, 2);
    return 0;
}

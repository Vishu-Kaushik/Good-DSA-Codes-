#include <iostream>
#include <string>
using namespace std;
//  Time complexity is clearly theta(m*n) and auxiliary space is theta(n*m)
int editDistance(string s1, string s2, int m, int n)
{
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) // Filling the first column
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char const *argv[])
{
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    int m = s1.size(), n = s2.size();
    cout << editDistance(s1, s2, m, n);
    return 0;
}

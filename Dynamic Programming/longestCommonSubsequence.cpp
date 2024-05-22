#include <iostream>
#include <utility>
using namespace std;

// Subsequence  --> we can take zero or any number of character which may or may not be contiguous but in the same order as they appear in input string

//  The dimension of the memo array will be 2 as two parameters are changing (length of both the strings)
// Memoization based solution
class dynamic
{
private:
    int m, n;
    int **memo;

public:
    dynamic(int x, int y)
    {
        m = x;
        n = y;
        memo = new int *[m + 1];
        for (int i = 0; i <= m; i++)
        {
            memo[i] = new int[n + 1];
            for (int j = 0; j <= n; j++)
            {
                memo[i][j] = -1;
            }
        }
    }
    //  Here we are comparing from the last element in both the strings
public:
    int lcs(string &s1, string &s2, int m, int n)
    {
        if (memo[m][n] != -1)
        {
            return memo[m][n];
        }
        if (m == 0 || n == 0)
        {
            memo[m][n] = 0;
        }
        else
        {
            if (s1[m - 1] == s2[n - 1])
            {
                memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1);
            }
            else
            {
                memo[m][n] = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
            }
        }
        return memo[m][n];
    }
};
//  Tabulation based solution --> where tc is O(m*n)
int lcs1(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0; // initializing 1st column as zero
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0; // initializing 1st row as zero
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main(int argc, char const *argv[])
{
    string s1 = "AXYZ";
    string s2 = "BAZ";
    int m = s1.size();
    int n = s2.size();
    dynamic d1(m, n);
    cout << d1.lcs(s1, s2, m, n) << endl;
    cout << lcs1(s1, s2);
    return 0;
}
/*
    Some Questions related to lcs concept
    1.Diff Utility
    2.Minimum insertions and deletions to convert s1 into s2
    3.Shortest Common Supersequence
    4.Longest palindromic subsequence
    5.Longest Repeating subsequence
    6.Space optimized DP solution of LCS
    7.Printing LCS
*/
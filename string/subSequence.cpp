#include <iostream>
#include <string>
using namespace std;
// Iterative
bool subsequence(const string &s1, const string &s2)
{
    int n = s1.length();
    int m = s2.length();
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (s1[i] == s2[j])
        {
            j++;
        }
    }
    return (j == m);
}
// Recursive Solution

bool subSqn(string &s1, string &s2, int n, int m)
{
    if (m == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (s1[n - 1] == s2[m - 1])
    {
        return subSqn(s1, s2, n - 1, m - 1);
    }
    else
    {
        return subSqn(s1, s2, n - 1, m);
    }
}
int main(int argc, char const *argv[])
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << subsequence(s1, s2) << endl;
    int n = s1.length();
    int m = s2.length();
    cout << subSqn(s1, s2, n, m);
    return 0;
}

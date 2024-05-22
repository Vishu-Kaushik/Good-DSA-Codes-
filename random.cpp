#include <bits/stdc++.h>
using namespace std;

#define mod 10000000007

int countWays(string s, string t, int k)
{
    int n = s.size();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        string p = s.substr(i, n - i) + s.substr(0, i);
        if (p == t)
            a++;
        else
            b++;
    }
    vector<long long> dp1(k + 1), dp2(k + 1);
    if (s == t)
    {
        dp1[0] = 1;
        dp2[0] = 0;
    }
    else
    {
        dp1[0] = 0;
        dp2[0] = 1;
    }

    for (int i = 1; i <= k; i++)
    {
        dp1[i] = ((dp1[i - 1] * (a - 1)) % mod + (dp2[i - 1] * a) % mod) % mod;

        dp2[i] = ((dp1[i - 1] * (b)) % mod + (dp2[i - 1] * (b - 1)) % mod) % mod;
    }
    return dp1[k] % mod;
}

int main()
{
    string s, t;
    cin >> s >> t;

    int k;
    cin >> k;

    cout << countWays(s, t, k);
    return 0;
}
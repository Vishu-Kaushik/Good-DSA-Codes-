#include <iostream>
using namespace std;

class dp
{
private:
    int n;
    int *memo;

public:
    dp(int a)
    {
        n = a + 1;
        memo = new int[n];
        for (int i = 0; i < n; i++)
        {
            memo[i] = -1;
        }
    }

public:
    int maxCuts(int n, int a, int b, int c)
    {
        if (n < 0)
        {
            memo[n] = -1;
            return memo[n];
        }
        else if (n == 0)
        {
            memo[n] = 0;
            return memo[n];
        }
        if (memo[n] != -1)
        {
            return memo[n];
        }
        int x = maxCuts(n - a, a, b, c);
        int y = maxCuts(n - b, a, b, c);
        int z = maxCuts(n - c, a, b, c);
        int res = max(x, max(y, z));
        if (res == -1)
        {
            memo[n] = -1;
        }
        else
        {
            memo[n] = res + 1;
        }
        return memo[n];
    }
};

int main(int argc, char const *argv[])
{
    dp d(5);
    cout << d.maxCuts(5, 1, 2, 3);
    return 0;
}

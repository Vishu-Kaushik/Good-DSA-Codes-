#include <iostream>
using namespace std;

// Simply solving the Fibonacci series problem
// WE create a memoization array
// The number of dimensions in memo array == NO. of parameters that we change in the recursive function calls and
// size of those dimensions is also dependent upon the values that you are changing
// also size is defined by minimun and maximum value in the parameter
// Time Complexity is O(n) and space complexity is O(N)+ O(N)(One of them is using recursion stack space)
class dynamic
{
private:
    int x;
    int *memo;
    // Also this is very easy to implement once we have a recursive solution and just following some rules only.

public:
    dynamic(int a)
    {
        x = a;
        memo = new int[x + 1];
        for (int i = 0; i <= x; i++)
        {
            memo[i] = -1;
        }
    }
    int fibonacci(int n)
    {
        if (memo[n] == -1)
        {
            int res;
            if (n == 0 || n == 1)
            {
                res = n;
            }
            else
            {
                res = fibonacci(n - 1) + fibonacci(n - 2);
            }
            memo[n] = res;
        }
        return memo[n];
    }
};
// Top down Approach --> We go from required ans to base cases to find the final ans.
int main(int argc, char const *argv[])
{
    int x, n;
    cin >> x;
    cin >> n;
    dynamic a(x);
    cout << a.fibonacci(n);

    return 0;
}

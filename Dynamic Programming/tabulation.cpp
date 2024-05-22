#include <iostream>
using namespace std;

// Implementing tabulation for fibonacci problem
// Generally it is faster than memoization trick
// This is slightly trickyer to implement
// Bottom Up --> We go from the base case and then go till required ans.
int fib(int n)
{
    int table[n + 1];
    table[0] = 0;
    table[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}

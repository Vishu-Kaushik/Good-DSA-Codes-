#include <iostream>
#include <algorithm>
using namespace std;

// NOTE--> We can get the idea for the base cases for the recursion problem by checking the leaf node of the recursion tree

int maxPeices(int n, int a, int b, int c) // Time Complexity if O(3^n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }
    int res = max(maxPeices(n - a, a, b, c), max(maxPeices(n - b, a, b, c), maxPeices(n - c, a, b, c)));
    if (res == -1)
    {
        return -1;
    }
    return res + 1;
}
int main(int argc, char const *argv[])
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    cout << maxPeices(n, a, b, c);
    return 0;
}

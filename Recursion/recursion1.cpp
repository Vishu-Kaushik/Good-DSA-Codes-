#include <iostream>
using namespace std;
// Recusion --> When a fucntion calls itself until a base condition is satisfied
// Print from N to 1 using backtracking without using f(i-1,N)
void print(int i, int n)
{
    if (i > n)
    {
        return;
    }
    print(i + 1, n);
    cout << i << " ";
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    print(1, n);
    return 0;
}

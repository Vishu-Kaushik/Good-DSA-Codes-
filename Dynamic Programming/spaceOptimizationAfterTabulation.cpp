

#include <iostream>
using namespace std;
// Normally for fibonacci number
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int prev2 = 0;
    int prev = 1;
    int curri;
    for (int i = 2; i <= n; i++)
    {
        curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    cout << prev;
    return 0;
}

#include <iostream>
using namespace std;
// Ques is to find the factorial
// Parameterised way

void prod(int i, int pro)
{
    if (i == 1)
    {
        cout << pro << endl;
        return;
    }
    prod(i - 1, pro * i);
}
// Functional way
int prod2(int i)
{
    if (i == 0)
    {
        return 1;
    }
    return i * prod2(i - 1);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    prod(n, 1);
    cout << endl;
    cout << prod2(n);
    return 0;
}

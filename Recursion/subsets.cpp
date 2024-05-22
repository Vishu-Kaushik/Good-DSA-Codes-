#include <iostream>
using namespace std;
// The idea is to use the solution of the subproblem to solve the overall problem

void subsets(string str, string curr = "", int i = 0)
{
    if (i == str.length())
    {
        cout << curr << " ";
        return;
    }
    subsets(str, curr, i + 1);          // to not take an element
    subsets(str, curr + str[i], i + 1); // to take and element
}
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    subsets(s);
    return 0;
}

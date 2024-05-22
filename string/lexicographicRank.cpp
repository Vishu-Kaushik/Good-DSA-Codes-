#include <iostream>
#include <string>
using namespace std;
const int Char = 256;
// Effcient Solution with Time COmplexity of  O(Char + n + Char + n*Char)
// The idea is compute the rank is --> count lexicographic smaller strings + 1
int fact(int n)
{
    int x = 1;
    for (int i = n; i > 0; i--)
    {
        x = x * i;
    }
    return x;
}
int lexicographicRank(string &str)
{
    int res = 1;
    int n = str.length();
    int mul = fact(n);
    int count[Char] = {0};
    for (int i = 0; i < n; i++)
    {
        count[str[i]]++;
    }
    for (int i = 1; i < Char; i++) // This loop is for finding the characters which are smaller than the
    {                              // the current character which are on the right side of it
        count[i] = count[i] + count[i - 1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        mul = mul / (n - i);
        res = res + mul * count[str[i] - 1];
        for (int j = str[i]; j < Char; j++)
        {
            count[j]--;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << lexicographicRank(s);
    return 0;
}

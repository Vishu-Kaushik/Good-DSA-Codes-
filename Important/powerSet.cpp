#include <iostream>
using namespace std;

// Writing all possible substrings of a given string using concept of bit manipulation

// Time complexity is O((2^n)*n) where 2^n is for outer loop and n is for inner loop
void powerSet(string &str)
{
    int n = str.length();
    for (int num = 0; num < (1 << n); num++) // 2^(n-1)-->1<<n
    {
        string sub;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
            {
                sub += str[i];
            }
        }
        cout << sub << " ";
    }
}
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    powerSet(s);
    return 0;
}

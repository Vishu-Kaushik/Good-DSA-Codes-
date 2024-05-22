#include <iostream>
using namespace std;
// Check if the string is palindrome or not
//  Time Complexity is O(n/2) and space complexity is O(n/2)
bool palindrome(string &str, int n, int i)
{
    if (i >= n / 2)
    {
        return true;
    }
    if (str[i] != str[n - i - 1])
    {
        return false;
    }
    return palindrome(str, n, i + 1);
}
int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    int n = str.length();
    palindrome(str, n, 0);
    return 0;
}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// Naive solution --> create a stack..... push words one by one into stack.... pop words from the stack and append to output
// Efficient Approach
void reverse(char str[], int low, int high)
{
    while (low <= high)
    {
        swap(str[low], str[high]);
        low++;
        high--;
    }
}
void reverseWords(char str[], int n)
{
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        /* code */
        if (str[end] == ' ')
        {
            reverse(str, start, end - 1);
            start = end + 1;
        }
    }
    reverse(str, start, n - 1); // Explicitly reversing the last word as there we are assuming there is no space after last character.
    reverse(str, 0, n - 1);
}
// void reverse(char str[], int low, int high)
// {
//     while (low <= high)
//     {
//         swap(str[low], str[high]);
//         low++;
//         high--;
//     }
// }
int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    int length = s.length();
    char c[length + 1];
    c[length] = '\0';
    for (int i = 0; i < length; i++)
    {
        /* code */
        c[i] = s[i];
    }
    reverseWords(c, length);
    cout << c;
    return 0;
}

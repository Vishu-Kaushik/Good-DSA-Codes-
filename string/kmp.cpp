#include <iostream>
#include <string>
using namespace std;

void fillLps(string str, int lps[])
{
    int n = str.length(), len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}
void kmp(string txt, string pat)
{
    int N = txt.length();
    int M = pat.length();
    int lps[M];
    fillLps(pat, lps);
    int i = 0, j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            cout << (i - j) << " ";
            j = lps[j - 1]; // simply assining the last matched character value from the lps array
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[i - 1];
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    kmp(s1, s2);
    return 0;
}

/*
here we consider that m== length of pattern n=== is the length of the text and 1<=m<=n
Naive: Here no preprocessing is required
1. O((n-m+1)*m)
2. When all the characters of pattern are distinct--> 0(n)

Efficient: Preprocess the pattern
1. Rabin Karp: 0((n-m+1)*m)  but better than naive on average
2. KMP: 0(n)

Suffix Tree: Preprocees the text with TC 0(m)
*/

#include <iostream>
#include <string>
using namespace std;

void patternSearch(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i <= n - m; i++)
    {
        /* code */
        int j;
        for (j = 0; j < m; j++)
        {
            /* code */
            if (pat[j] != txt[i + j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout << i << " ";
        }
    }
}
int main(int argc, char const *argv[])
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    patternSearch(s1, s2);
    return 0;
}

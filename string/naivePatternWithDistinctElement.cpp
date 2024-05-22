#include <iostream>
#include <string>
using namespace std;
// THis solution works when all the elements are distinct in the pattern
//  With TC as O(n)
void patternSearch(string txt, string pat)
{
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (pat[j] != txt[i + j])
            {
                break;
            }
        }
        if (j == m)
        {
            cout << i << " ";
        }
        if (j == 0)
        {
            i++;
        }
        else
        {
            i = i + j;
        }
    }
}

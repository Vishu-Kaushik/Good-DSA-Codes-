#include <iostream>
#include <string>
using namespace std;
#define d 256      // the no. of characters that can appear in the txt
const int q = 101; // or can be a big prime number according to the pattern length
void rabinKarp(string txt, string pat, int n, int m)
{
    // Compute (d^(m-1))%q
    int h = 1;
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    // compute p and t0(tnot)
    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }
    for (int i = 0; i <= (n - m); i++)
    {
        // check for hit
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
                if (flag == true)
                {
                    cout << i << " ";
                }
            }
            // Compute ti+1 using ti
            if (i < n - m)
            {
                t = ((d * (t - txt[i] * h)) + txt[i + m]) % q;
                if (t < 0)
                {
                    t = t + q;
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

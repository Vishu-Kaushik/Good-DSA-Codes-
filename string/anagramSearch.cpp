#include <iostream>
#include <string>
const int Char = 256;
using namespace std;

// Naive approach where the TC is O((n-m+1)*m) where m is the length of pattern
// Anagram is when the pattern string and the text string are at the contiguous location
bool isPresent(string &txt, string &pat)
{
    int N = txt.length();
    int M = pat.length();
    for (int i = 0; i < N - M; i++)
    {
        if (isAnagram(txt, pat, i))
        {
            return true;
        }
    }
    return true;
}

bool isAnagram(string &txt, string &pat, int i)
{
    int count[Char] = {0};
    for (int j = 0; j < pat.length(); j++)
    {
        count[pat[j]]++;
        count[txt[i + j]]--;
    }
    for (int j = 0; j < Char; j++)
    {
        if (count[j] != 0)
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    cout << isPresent(s1, s2);

    return 0;
}

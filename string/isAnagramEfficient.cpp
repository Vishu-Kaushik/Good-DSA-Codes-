#include <iostream>
#include <string>
const int Char = 256;
using namespace std;
// The time complexity of this solution is O(m+(n-m)*Char)
bool isPresent(string &txt, string &pat)
{
    int CT[Char] = {0};
    int CP[Char] = {0};
    for (int i = 0; i < pat.length(); i++)
    {
        CT[txt[i]]++;
        CP[pat[i]]++;
    }
    for (int i = pat.length(); i < txt.length(); i++)
    {
        if (isSame(CT, CP))
        {
            return true;
        }
        CT[txt[i]]++;
        CT[txt[i - pat.length()]]--;
    }
    return false;
}
bool isSame(int ct[], int cp[])
{
    for (int i = 0; i < Char; i++)
    {
        if (ct[i] != cp[i])
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

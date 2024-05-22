#include <iostream>
using namespace std;

const int CHAR = 256;
bool anagram(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    if (n < m)
    {
        return false;
    }
    int count[CHAR] = {0};
    for (int i = 0; i < n; i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for (int i = 0; i < CHAR; i++)
    {
        if (count[i] != 0)
        {
            return false;
        }
    }
    return true;
}
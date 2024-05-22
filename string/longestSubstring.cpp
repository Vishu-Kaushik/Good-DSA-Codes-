#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int Char = 256;
// THis solution is a O(n^3) solution

bool areDistinct(string &s, int i, int j)
{
    vector<bool> visited(256);
    for (int x = i; x <= j; x++)
    {
        if (visited[s[x]] == true)
        {
            return false;
        }
        visited[s[x]] = true;
    }
    return true;
}

int longestDistinct(string &s)
{
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (areDistinct(s, i, j))
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

// Better Solution where TC is O(n^2)
int longestDis(string &s)
{
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(256);
        for (int j = 0; j < n; j++)
        {
            if (visited[s[j]] == true)
            {
                return false;
            }
            else
            {
                res = max(res, j - i + 1);
                visited[s[j]] = true;
            }
        }
    }
    return res;
}
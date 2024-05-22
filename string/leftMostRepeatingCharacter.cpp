#include <iostream>
#include <string>
using namespace std;
const int chaR = 256;
// Method-1 -> counting frequency
int rep1(string s1)
{
    int count[chaR] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        count[s1[i]]++;
    }
    for (int i = 0; i < chaR; i++)
    {
        if (count[i] > 1)
        {
            /* code */
            return i;
        }
    }
    return -1;
}

// Method-2 ->

int rep2(string s1)
{
    int count[chaR];
    fill(count, count + chaR, -1);
    int res = INT16_MAX;
    for (int i = 0; i < s1.size(); i++)
    {
        int fi = count[s1[i]];
        if (fi == -1)
        {
            count[s1[i]] = i;
        }
        else
        {
            res = min(res, fi);
        }
    }
    return (res == INT16_MAX) ? -1 : res;
}

// Method-3 ->
int rep3(string s1)
{
    bool visited[chaR];
    int res = -1;
    fill(visited, visited + chaR, false);
    for (int i = s1.length(); i >= 0; i--)
    {
        if (visited[s1[i]])
        {
            res = i;
        }
        else
        {
            visited[s1[i]] = true;
        }
    }
    return res;
}

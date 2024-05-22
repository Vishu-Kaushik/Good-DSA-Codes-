// Ques--> Given n ranges, find the maximum appearing element in these ranges
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// constraint ,,,, max size of range is 1000
int maxAppearing(int a[], int b[], int n)
{
    int vec[1000] = {0};
    for (int i = 0; i < n; i++)
    {
        vec[a[i]]++;
        vec[b[i] + 1]--;
    }
    int max = vec[0];
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        vec[i] = vec[i] + vec[i - 1];
        if (max < vec[i])
        {
            max = vec[i];
            res = i;
        }
    }
    return res;
}
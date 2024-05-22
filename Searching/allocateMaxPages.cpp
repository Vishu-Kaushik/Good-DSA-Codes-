#include <iostream>
using namespace std;

int maxPages(int arr[], int size, int k)
{
    if (k == 1)
    {
        return sum(arr, 0, size - 1);
    }
    if (size == 1)
    {
        return arr[0];
    }
    int res = INT16_MAX;
    for (int i = 0; i < size; i++)
    {
        res = min(res, max(maxPages(arr, i, k - 1), sum(arr, i, size - 1)));
    }

    return res;
}
int sum(int arr[], int b, int e)
{
    int sum = 0;
    for (int i = b; i < e; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}
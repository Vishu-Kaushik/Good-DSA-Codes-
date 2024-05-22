#include <iostream>
using namespace std;
// A popuular interview question
// TC will be O(n*log(sum-mx))
int maxPages(int arr[], int n, int m)
{
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int low = mx;
    int high = sum;
    int res = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (ifPossible(arr, n, m, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
bool ifPossible(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount < m || arr[i] > mid)
            {
                return false;
            }
            pageSum = 0;
            pageSum = arr[i];
        }
    }
    return true;
}
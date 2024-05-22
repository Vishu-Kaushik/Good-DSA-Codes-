#include <iostream>
using namespace std;

int binarySearch(int arr[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int search(int arr[], int x)
{
    if (arr[0] == x)
    {
        return 0;
    }
    int i = 1;
    while (arr[i] < x)
    {
        i = i * 2;
    }
    if (arr[i] == x)
    {
        return i;
    }
    return binarySearch(arr, x, i / 2 + 1, i - 1);
}
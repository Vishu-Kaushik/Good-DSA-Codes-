#include <iostream>
using namespace std;
// Recursive solution with TC of O(logn) with O(logn)
int lastOccurence(int arr[], int low, int high, int x, int size)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (x > arr[mid])
    {
        return lastOccurence(arr, mid + 1, high, x, size);
    }
    else if (x < arr[mid])
    {
        return lastOccurence(arr, low, mid - 1, x, size);
    }
    else
    {
        if (mid == size - 1 || arr[mid + 1] != arr[mid])
        {
            return mid;
        }
        else
        {
            return lastOccurence(arr, mid + 1, high, x, size);
        }
    }
}
// Iterative Solution where TC is O(logn) and AS as O(1)
int lastOcc(int arr[], int size, int x)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (x > arr[mid])
        {
            low = mid + 1;
        }
        else if (x < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            if (mid == size - 1 || arr[mid + 1] != arr[mid])
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return -1;
}
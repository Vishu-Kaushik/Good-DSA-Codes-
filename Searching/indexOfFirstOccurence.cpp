#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Recursive solution
int isFirst(int arr[], int low, int high, int x)
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (x > arr[mid])
    {
        return isFirst(arr, mid + 1, high, x);
    }
    else if (x < arr[mid])
    {
        return isFirst(arr, low, mid - 1, x);
    }
    else
    {
        if (mid == 0 || arr[mid - 1] != arr[mid])
        {
            return mid;
        }
        else
        { // going to the left half becoz to find first occurence
            return isFirst(arr, low, mid - 1, x);
        }
    }
}

// Iterative solution for this question
int isFirstI(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
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
            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
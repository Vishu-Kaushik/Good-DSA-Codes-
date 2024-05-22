#include <iostream>
using namespace std;
// using binary search in the random array (sorted or unsorted)
int peak(int arr[], int size)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == size - 1 || arr[mid] >= arr[mid - +1]))
        {
            return mid;
        }
        if (mid > 0 && arr[mid - 1] >= arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{

    return 0;
}

#include <iostream>
using namespace std;
// TC is O(logn) and AS is O(1)
int sortedRotated(int arr[], int size, int x)
{
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > arr[high])
        {
            if (x >= arr[low] && x < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (x > arr[mid] && x <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main(int argc, char const *argv[])
{
    int arr[] = {3, 1};
    cout << sortedRotated(arr, 2, 1);
    return 0;
}

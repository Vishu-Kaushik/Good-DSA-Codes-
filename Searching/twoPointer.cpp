#include <iostream>
using namespace std;
// To find a pair with a given sum
// Tc will be O(n) with AS of O(1)
bool pair(int arr[], int size, int sum)
{
    int low = 0, high = size - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == sum)
        {
            return 1;
        }
        else if (arr[low] + arr[high] > sum)
        {
            high--;
        }
        else
        {
            low++;
        }
    }
    return 0;
}
// To find triplet with a given sum
#include <iostream>
using namespace std;
// SubArray --> Contiguous elements picked from the array in the same order as they are present in the given array
// Naive approach With TC as O(N^2)
int maxSubarray(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr = curr + arr[i];
            res = max(res, curr);
        }
    }
    return res;
}
// Efficient SOlution --> Time Complexity O(N)
// KADANE'S ALGORITHM

int maxSum(int arr[], int n)
{
    int res = arr[0];
    int maxEnding = arr[0];
    for (int i = 1; i < n; i++)
    {
        // maxEnding += arr[i];
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;

}
// Another implementation of kadane's algorithm

int maxSum1(int arr[], int n)
{
    int sum = 0, max1 = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        // sum==0 then start=i
        sum += arr[i];

        max1 = max(sum, max1); // maxstart = start and maxend=i

        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (max1 < 0)
    {
        return 0;
    }
    return max1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {-3, 8, -2, 4, -5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n);
    return 0;
}

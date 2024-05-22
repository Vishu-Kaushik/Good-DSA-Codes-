#include <iostream>
using namespace std;

// Given an array of n integers and a number k, find the maximum sum of k concecutive elements
// Naive solution whose Time Complexity is O((n-k)*k)

int maxSum(int arr[], int n, int k)
{
    int res = INT16_MIN;
    for (int i = 0; i + k - 1 < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            sum += arr[j + i];
        }
        res = max(res, sum);
    }
    return res;
}
// Now using the Window Sliding Technique we can solve it using O(N) time
int maxSumm(int arr[], int n, int k)
{
    int curr_sum = 0;
    for (int i = 0; i < k; i++) // Calulating the sum of the first window of the array
    {
        curr_sum += arr[i];
    }
    int max_sum = INT16_MIN;
    for (int i = k; i < n; i++) // and Then calculating the sum of the next window by adding the next element and subtracting the first element of the previous window
    {
        curr_sum = curr_sum + (arr[i] - arr[i - k]); // And here i is considered as the end of the current window
        max_sum = max(curr_sum, max_sum);
    }
    return max_sum;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 8, 30, -5, 20, 7};
    cout << maxSumm(arr, 6, 3);
    return 0;
}

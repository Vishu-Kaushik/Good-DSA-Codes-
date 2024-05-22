#include <iostream>
using namespace std;

// Circular subarray --> Includes both normal subarray and also circular
// circular --> When we connect the last element with the first element of the array

// Subsequence of a given sequence is a sequence that can be derived from the given sequence by deleting some or no elements
// without changing the order of the remaining elements

// SubArray --> Contiguous elements picked from the array in the same order as they are present in the given array
// Idea --> we consider all the subarray beginning with the current element and find the max sum for every subarray
// Naive Approach with TC as O(N^2)
int maxCircularSum(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr_max = arr[i];
        int curr_sum = arr[i];
        for (int j = 1; j < n; j++)
        {
            int index = (i + j) % n;
            curr_sum += arr[j];
            curr_max = max(curr_max, curr_sum);
        }
        res = curr_sum;
    }
    return res;
}

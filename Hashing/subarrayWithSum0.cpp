#include <iostream>
#include <unordered_set>
using namespace std;

// THere is a brute force solution for checking sum for every subarray

// The time complexity of this solution is O(N) with the space complexity of O(N)

bool subarray(int arr[], int n)
{
    int preSum = 0;
    unordered_set<int> sumSet;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (sumSet.find(preSum) != sumSet.end())
        {
            return true;
        }
        if (preSum == 0)
        {
            return true;
        }
        preSum += arr[i];
    }
    return false;
}
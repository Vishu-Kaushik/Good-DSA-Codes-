#include <iostream>
using namespace std;

// Idea --> With time complexity of O(N)
/*
part1 -> Maximum sum of a normal subarray (Easy: Using Kadane's Algorithm)
part2 -> maximum sum of a circular array
        finding minimum sum subarray of the given array using kadane's Algorithm
        And then subtracting this minimum sum subarray  sum from the overall sum of the array which is given to us.
*/

// Part 1 of the IDEA
int normalmaxSum(int arr[], int n)
{
    int res = arr[0], maxEnding = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = maxEnding;
    }
    return res;
}
// Part 2 of the idea
int overallMaxSum(int arr[], int n)
{
    int max_normal = normalmaxSum(arr, n);
    if (max_normal < 0)
    {
        return max_normal;
    }
    int arrsum = 0;
    for (int i = 0; i < n; i++) // Here instead of finding the minimum sum of subarray we find the maximum sum subarray in the inverted array of the given array
    {
        arrsum += arr[i];
        arr[i] = -arr[i]; // Invering every element of the array
    }
    int max_cicrular = arrsum + normalmaxSum(arr, n); // And if we invert the elements of the array so instead of subtracting the sum ...We add the max sum in the overall sum
    return max(max_cicrular, max_normal);
}
// And that max sum subarray gives us  the minimum sum subarray or is ultimately the  minimum sum subarray that we were finding out for the max cirular sum and were
// to supposed to subtract that sum from the overalll sum .... SO we add it to overalll sum

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

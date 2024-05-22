#include <iostream>
using namespace std;

// Given an unsorted array of non-negative integers. Find if there is a subarray with given sum.

/*
We maintain two variables start and end
And we consider every index as the end of the current window and check the following according to the code
*/

bool isSubSum(int arr[], int n, int sum)
{
    int curr_sum = arr[0], s = 0;
    for (int e = 1; e < n; e++)
    {
        // clearing the previous window
        while (curr_sum > sum && s < e - 1)
        {
            curr_sum -= arr[s];
            s++;
        }
        if (curr_sum == sum)
        {
            return true;
        }
        if (e < n)
        {
            curr_sum += arr[e];
        }
    }
    return (curr_sum == sum);
}

/*
More ques on this technique:
1. N-bonacci Numbers: Print first M N-bonacci numbers
2. Print distinct elements in every window of size k
*/

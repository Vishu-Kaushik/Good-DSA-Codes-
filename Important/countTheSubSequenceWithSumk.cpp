#include <iostream>
using namespace std;
//  Important technique(pattern) that we have to keep in mind
//  Time Complexity is O(2^n)
int sub(int arr[], int n, int sum, int s, int ind)
{
    // Slight Optimization
    // if array contains positives only
    if (s > sum) // condition not satisfied
    {
        return 0;
    }
    if (ind == n)
    {
        // Condition satisfied
        if (s == sum)
        {
            return 1;
        }
        // Condition not satisfied
        else
        {
            return 0;
        }
    }
    // s += arr[ind];
    // Pick Condition
    int l = sub(arr, n, sum, s + arr[ind], ind + 1); // summarrize the recursion sum
    // s -= arr[ind];
    // Not pick condtion
    int r = sub(arr, n, sum, s, ind + 1);
    return l + r;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 2;
    cout << sub(arr, n, sum, 0, 0);
    return 0;
}

/*
Technique: return 1 and return 0 and add them
*/

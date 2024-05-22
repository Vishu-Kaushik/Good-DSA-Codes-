#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

// Recursive Solution

int maxSum(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    else if (n == 2)
    {
        return max(arr[0], arr[1]);
    }
    else
    {
        return max(maxSum(arr, n - 1),               // Case for not including the last element and the calling the function again for the n-1 elements
                   maxSum(arr, n - 2) + arr[n - 1]); // Case for including the last element in the sum and the calling the function again for the remaining n-2 elements
    }
}

// Tabulation based solution --> where tc is O(n) and auxiliary space is O(n)

int maxSumTab(int arr[], int n)
{
    int dp[n + 1];
    dp[0] = arr[0];
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    // dp[i] = stores the  result for an array of lenght 'i' in the tabulation based solution
    for (int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
    }
    return dp[n];
}

// Solution with --> Time Complexity O(n) and Space Complexity O(1)
int maxSumOp(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    int prev1 = arr[0];
    int prev2 = max(arr[1], arr[0]);
    int res = prev2;
    for (int i = 3; i <= n; i++)
    {
        res = max(prev2, prev1 + arr[i - 1]);
        prev1 = prev2;
        prev2 = res;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int arr[] = {10, 5, 15, 20};
    cout << maxSumOp(arr, 4) << endl;
    cout << maxSumTab(arr, 4);
    return 0;
}
#include <iostream>
using namespace std;
// Recursive solution 1 --> Which is not easy to convert into dynamic prog. based solution .. as we will need a parameter sum which can be very large in some case
//                          so the space req. will become very large
int sol(int arr[], int i, int j, int sum)
{
    if (j == i + 1)
    {
        return max(arr[j], arr[i]);
    }
    return max(sum - sol(arr, i + 1, j, sum - arr[i]), // HEre we are making recursive call for the opponent and then checking for his optimized choice and then
                                                       //  subtracting from the sum
               sum - sol(arr, i, j - 1, sum - arr[j]));
}

int sumsol(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sol(arr, 0, n - 1, sum);
}
// Recursive Solution 2 --> Which is easy to convert into dp solution
// Idea --> we will choose max value among the two corner elements of the array and then opponent will choose the max value for himself resulting in giving us minimum
//          value and then we have to optimize our value from the remaining elements

int maxValue(int arr[], int i, int j)
{
    if (i + 1 == j)
    {
        return max(arr[i], arr[j]);
    }
    return max(arr[i] + min(maxValue(arr, i + 2, j), maxValue(arr, i + 1, j - 1)),
               arr[j] + min(maxValue(arr, i, j - 2), maxValue(arr, i + 1, j - 1)));
}

// Dynamic Programming solution using tabulation method
// Time Complexity is theta(n^2) and space complexity is also theta(n^2)
int maxVal(int arr[], int n)
{
    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]); // filling the dp matrix according to the base case solution
    }
    // int j;
    for (int gap = 3; gap < n; gap = gap + 2)
    {
        for (int i = 0; i + gap < n; i++)
        {
            int j = i + gap; // According to the values in recursive solution
            dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    return dp[0][n];
}
int main(int argc, char const *argv[])
{
    int arr[] = {20, 5, 4, 6};
    cout << sumsol(arr, 4);
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// TIme complexity of this solution is theta(n^2) with auxiliary space of theta(n)
// THis is the DP based solution
int longestLcs(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    int res = lis[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, lis[i]);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 5, 18, 7, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << longestLcs(arr, size);
    return 0;
}

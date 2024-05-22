#include <iostream>
#include <vector>
using namespace std;

// Q.1 --> Given an array of integers find if if has an equilibrium point
bool isEq(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int l_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (l_sum == sum - arr[i])
        {
            return true;
        }
        l_sum += arr[i];
        sum -= arr[i];
    }
    return false;
}

// Q.2 --> Given n ranges, find the maximum appearing element in the ranges

int maxAppearing(int l[], int r[], int n)
{
    int arr[1000] = {0};

    for (int i = 0; i < n; i++)
    {
        arr[l[i]]++;
        arr[r[i] + 1]--;
    }
    int maxm = arr[0], res = 0;
    for (int i = 1; i < 1000; i++)
    {
        arr[i] += arr[i - 1];
        if (maxm < arr[i])
        {
            maxm = arr[i];
            res = i;
        }
    }
    return res;
}
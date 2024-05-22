#include <iostream>
using namespace std;
// We do not evaluate for the corner two bars becoz there is no support for the water to be tapped on the left or right

// Naive Solution with TC=theta(N^2) and AS=O(1)

int trapping1(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int lmax = arr[i];
        for (int j = 0; j < i; i++)
        {
            lmax = max(lmax, arr[j]);
        }
        int rmax = arr[i];
        for (int j = i; j < n; j++)
        {
            rmax = max(rmax, arr[i]);
        }
        res = res + (min(lmax, rmax) - arr[i]);
    }
    return res;
}

// Efficient Solution with TC=theta(N) and AS = theta(N)
int trapping2(int arr[], int n)
{
    int res = 0;
    int lmax[n], rmax[n];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lmax[i] = max(arr[i], lmax[i - 1]);
    }
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rmax[i] = max(arr[i], rmax[i + 1]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        res += (min(lmax[i], rmax[i]) - arr[i]);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int arr[] = {3, 0, 1, 2, 5};
    cout << trapping2(arr, 5);
    return 0;
}

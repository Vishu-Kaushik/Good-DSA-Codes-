#include <iostream>
using namespace std;

// To find if there is an equilibrium point in the array
// Naive solution with TC of O(n^2)
bool equilibrium(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int lsum = 0;
        int rsum = 0;
        for (int j = 0; j < i; j++)
        {
            lsum += arr[j];
        }
        for (int k = i + 1; k < size; k++)
        {
            rsum += arr[k];
        }
        if (lsum == rsum)
        {
            return true;
        }
    }
    return false;
}
// Efficient solution where TC is O(n) with aux space as O(1)
//  without computing the prefix sum array
bool eqpoint(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    int lsum = 0;
    for (int i = 0; i < size; i++)
    {
        if (lsum == sum - arr[i])
        {
            return true;
        }
        lsum += arr[i];
        sum -= arr[i];
    }
    return false;
}
int main(int argc, char const *argv[])
{

    // input array
    return 0;
}

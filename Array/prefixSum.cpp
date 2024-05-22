#include <iostream>
using namespace std;
// prefix sum technique
int getSum(int arr[], int size, int l, int r)
{
    int prefixSum[size];
    prefixSum[0] = arr[0];
    for (int i = 1; i < size; i++)
    {
        prefixSum[i] = arr[i] + prefixSum[i - 1];
    }
    if (l != 0)
    {
        return (prefixSum[r] - prefixSum[l - 1]);
    }
    else
    {
        return prefixSum[r];
    }
}
int main(int argc, char const *argv[])
{
    // dekhlo input likhlo

    return 0;
}

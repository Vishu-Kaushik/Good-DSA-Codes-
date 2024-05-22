#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
// TC id O(logn1)
// condition where n<=m
int median(int arr[], int brr[], int n1, int n2)
{
    int low = 0;
    int high = n1;
    while (low <= high)
    {
        int i1 = (low + high) / 2;
        int i2 = floor((n1 + n2 + 1) / 2) - i1;
        int mn1 = (i1 == n1) ? INT16_MAX : arr[i1];
        int mx1 = (i1 == 0) ? INT16_MIN : arr[i1 - 1];
        int mn2 = (i2 == n2) ? INT16_MAX : brr[i2];
        int mx2 = (i2 == 0) ? INT16_MIN : brr[i2 - 1];
        if (mx1 <= mn2 && mx2 <= mn1)
        {
            if ((n1 + n2) / 2 == 0)
            {
                return ((double)max(mx1, mx2) + min(mn1, mn2)) / 2;
            }
            else
            {
                return (double)max(mx1, mx2);
            }
        }
        else
        {
            if (mx1 > mn2)
            {
                high = i1 - 1;
            }
            else
            {
                low = i1 + 1;
            }
        }
    }
}
int main(int argc, char const *argv[])
{

    return 0;
}

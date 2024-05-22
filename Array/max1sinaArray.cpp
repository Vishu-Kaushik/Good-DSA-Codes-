#include <iostream>
using namespace std;
// Efficient solution With time complexity of O(N) and auxiliary space as O(1)
int max1s(bool arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == 0)
            {
                curr = 0;
            }
            else
            {
                curr++;
                res = max(curr, res);
            }
        }
    }
    return res;
}
// Naive solution where time Complexity is O(N^2) and auxiliary space as O(N)
int max1(bool arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 1)
            {
                curr++;
            }
            else
            {
                break;
            }
        }
        res = max(res, curr);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    bool arr[] = {0, 1, 1, 1, 0, 1, 1};
    int n = 7;
    cout << max1(arr, 7);
    return 0;
}

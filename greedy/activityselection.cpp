#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
bool mycmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}
// TC is O(n logn)
int maxActivity(pair<int, int> arr[], int size)
{
    int res = 1;
    sort(arr, arr + size, mycmp);
    // res++;
    int prev = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i].first >= arr[prev].second)
        {
            res++;
            prev = i;
        }
    }
    return res;
}
int main()
{
    pair<int, int> arr[] = {make_pair(12, 25), make_pair(10, 20), make_pair(20, 30)};

    int n = 3;

    cout << maxActivity(arr, n);

    return 0;
}
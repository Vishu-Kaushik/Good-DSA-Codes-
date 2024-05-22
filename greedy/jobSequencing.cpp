#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool mycmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

int jobSequencing(pair<int, int> arr[], int size)
{
    sort(arr, arr + size, mycmp);
    int res = 0;
    int counter = 0;
    int max = arr[0].first;
    for (int i = 1; i < size; i++) // max deadline nikal di
    {
        if (arr[i].first > max)
        {
            max = arr[i].first;
        }
    }
    bool a[max] = {false};
    for (int i = 0; i < size; i++)
    {
        int profit = arr[i].second;
        int deadline = arr[i].first;
        for (int k = deadline - 1; k >= 0; k--) // loop is to gice the last possible slot in the boolean array
        {
            if (a[k] == false)
            {
                counter++;
                a[k] = true;
                res = res + profit;
                break;
            }
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    pair<int, int> p[] = {{2, 100}, {1, 50}, {2, 10}, {1, 20}, {3, 30}};
    cout << jobSequencing(p, 5);
    return 0;
}

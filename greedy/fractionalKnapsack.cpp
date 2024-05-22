#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool mycmp(pair<int, int> p1, pair<int, int> p2)
{
    int a = p1.second / p1.first;
    int b = p2.second / p2.first;
    return a > b;
}

double knapSack(pair<int, int> arr[], int size, int cap)
{
    sort(arr, arr + size, mycmp);
    double res = 0;
    // int amount = cap;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].first <= cap)
        {
            cap -= arr[i].first;
            res = res + arr[i].second;
        }
        else
        {
            res = res + (double(cap) / arr[i].first) * arr[i].second;
            break;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    pair<int, int> arr[] = {make_pair(30, 120), make_pair(20, 100), make_pair(10, 60)};

    int size = 3, W = 50;

    cout << knapSack(arr, size, W);

    return 0;
}

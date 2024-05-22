#include <iostream>
#include <unordered_set>
using namespace std;

bool isSUm(int arr[], int size, int sum)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (pre_sum == sum) // for the subarray with the first element of array
        {
            return true;
        }
        if (s.find(pre_sum - sum) != s.end())
        {
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}
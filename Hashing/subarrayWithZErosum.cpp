#include <iostream>
#include <unordered_set>
using namespace std;

bool subarray0sum(int a[], int n)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += a[i];
        if (s.find(pre_sum) != s.end())
        {
            return true;
        }
        if (pre_sum == 0) // pre_sum-sum==sum
        {
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}
int main(int argc, char const *argv[])
{

    return 0;
}

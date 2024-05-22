#include <iostream>
#include <vector>
using namespace std;
// Using fucntional calls
// Very Very Important Technique that should be kept in mind
bool printSub(int arr[], int n, int ind, vector<int> v, int sum, int s)
{
    if (ind == n)
    {
        // Condition satisfied
        if (s == sum)
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
        // Condition not satisfied
        else
        {
            return false;
        }
    }
    v.push_back(arr[ind]);
    s += arr[ind];
    // Pick Condition
    if (printSub(arr, n, ind + 1, v, sum, s))
    {
        return true;
    }
    s -= arr[ind];
    v.pop_back();
    // Not pick Condition
    if (printSub(arr, n, ind + 1, v, sum, s))
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    int sum = 2;
    printSub(arr, n, 0, v, 2, 0);
    return 0;
}
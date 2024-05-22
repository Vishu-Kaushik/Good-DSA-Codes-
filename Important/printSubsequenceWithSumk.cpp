#include <iostream>
#include <vector>
using namespace std;
// Using fucntional calls
void printSub(int arr[], int n, int ind, vector<int> v, int sum, int s)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }
    v.push_back(arr[ind]);
    s += arr[ind];
    // Pick Condition
    printSub(arr, n, ind + 1, v, sum, s);
    s -= arr[ind];
    v.pop_back();
    // Not pick Condition
    printSub(arr, n, ind + 1, v, sum, s);
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

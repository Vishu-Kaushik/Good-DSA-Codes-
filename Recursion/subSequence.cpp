#include <iostream>
#include <vector>
using namespace std;

// Subsequence --> A contiguous or non-contiguous sequences which follows the order

// Idea is to take an element or not to take it
// Time complexity is O((2^n)*n) with the space complexity of O(n) where n will the depth of recursion tree or only 3 calls will be waiting in the recursion tree
void subsequence(int arr[], int n, int ind, vector<int> &v)
{
    if (ind == n)
    {
        int x = v.size();
        for (auto i : v)
        {
            cout << i << " ";
        }
        if (v.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // take or pick the particular index into the subsequence
    v.push_back(arr[ind]);
    subsequence(arr, n, ind + 1, v);
    v.pop_back();
    // Not pick, or not take condition, this element id not added to your subsequence
    subsequence(arr, n, ind + 1, v);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v;
    subsequence(arr, n, 0, v);
    return 0;
}

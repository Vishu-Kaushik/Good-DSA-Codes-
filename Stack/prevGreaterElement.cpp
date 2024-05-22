#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Actually we have to find closest greater element

// Naive Solution --> With Time Complexity of O(N^2)

vector<int> prevGreater(int arr[], int n)
{
    vector<int> ans;

    ans.push_back(-1);
    for (int i = 1; i < n; i++)
    {
        // bool flag = false;
        int greater = -1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                // flag = true;
                greater = arr[j];
                break;
            }
        }
        ans.push_back(greater);
    }
    return ans;
}

// Efficient Solution : Using Stack and the Time Complexity becomes O(N) and with the worst case Space Complexity of O(N)

vector<int> prevGreatEfficient(int arr[], int n)
{
    stack<int> stak;
    vector<int> ans;

    stak.push(arr[0]);
    ans.push_back(-1);

    for (int i = 1; i < n; i++)
    {
        while (!stak.empty() && stak.top() <= arr[i])
        {
            stak.pop();
        }
        if (stak.empty() == true)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(stak.top());
        }
        stak.push(arr[i]);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    vector<int> ans = prevGreatEfficient(arr, 8);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

// Idea for Naive solution is same as prev. greater element

// Efficient SOlution --> Here we traverse the array from the right side and the process them as same as prev. greater element

vector<int> nextGreater(int arr[], int n)
{
    vector<int> ans;
    stack<int> stak;

    // We will traverse the array from the right side
    // Doing this we will get our output in reverse order.
    stak.push(arr[n - 1]);
    ans.push_back(-1);

    for (int i = n - 2; i >= 0; i--)
    {
        while (!stak.empty() && stak.top() <= arr[i])
        {
            stak.pop();
        }
        int great = (stak.empty()) ? (-1) : stak.top();
        ans.push_back(great);
        stak.push(arr[i]);
    }
    // To deal with the problem of reverse sequence
    reverse(ans.begin(), ans.end());
    return ans;
}
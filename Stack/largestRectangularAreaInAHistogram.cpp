#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Naive Solution in which Time Complexity is theta(N^2)

int maxArea(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
            {
                curr += arr[i];
            }
            else
            {
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
            {
                curr += arr[i];
            }
            else
            {
                break;
            }
        }
        res = max(res, curr);
    }
    return res;
}

// Better Solution where TC becomes O(N) but with 3 traversals of the given array which need some preprocessing
// Here in this two arrays we store indexes instead of actual elements.
void prevSmall(int arr[], int ps[], int n)
{
    stack<int> st;
    st.push(0);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            ps[i] = -1;
        }
        else
        {
            ps[i] = st.top();
        }
        st.push(i);
    }
}

void nextSmall(int arr[], int ns[], int n)
{
    stack<int> st;
    st.push(n - 1);

    for (int i = n - 1; i > 0; i--)
    {
        while (!st.empty() && arr[i] <= arr[st.top()])
        {
            st.pop();
        }
        if (st.empty())
        {
            ns[i] = n;
        }
        else
        {
            ns[i] = st.top();
        }
        st.push(i);
    }
    // reverse(ns, ns + n);
}

// ABove two functions were for the preprocessing
// Now this function will Actually give us the max Area of the histogram

int maxAreaHistogram(int arr[], int n)
{
    int ps[n], ns[n];

    prevSmall(arr, ps, n);
    nextSmall(arr, ns, n);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];

        curr += (i - ps[i] - 1) * arr[i];
        curr += (ns[i] - i - 1) * arr[i];

        res = max(res, curr);
    }
    return res;
}

// Efficient Solution with the Time Complexity of O(N) with only one traversal

int maxAreaEff(int arr[], int n)
{
    stack<int> st;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        // This loop is for those elements which have previous smaller element and also the next smaller element
        // This loop finds the largest area of the rectangle that can form with the removed item from the stack with the current index of the array
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            int tp = st.top();
            st.pop();
            int curr = arr[tp] * (st.empty() ? i : (i - st.top() - 1));
            res = max(res, curr);
        }
        // This loop now evaluates those elements which do no have next smaller elements
        while (!st.empty())
        {
            int tp = st.top();
            st.pop();
            int curr = arr[tp] * (st.empty() ? n : (n - st.top() - 1));
            res = max(res, curr);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    cout << maxAreaHistogram(arr, 7);
    return 0;
}

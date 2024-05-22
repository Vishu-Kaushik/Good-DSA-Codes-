#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Naive Solution :
// Where the Time Complexity of the solution is O(N^2)

vector<int> spanArray(int arr[], int n)
{
    vector<int> stock;
    stock.push_back(1);
    for (int i = 1; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[i])
            {
                break;
            }
            span++;
        }
        stock.push_back(span);
    }
    return stock;
}

/* Idea for Efficient Solution:
    If there is a greater element :
    Span : (Index of Current Element) - (Index of closest greater element on left Side)
    else
    --> So for storing this we will need a stack so in that stack we will have :
    -> current element at top then its previous greater element then its previous greater element and so on


The Time Complexity is theta(n) and auxiliary space is O(n)


*/

vector<int> stockSpan(int arr[], int n)
{
    vector<int> ans;
    stack<int> st;

    // We will push indexes instead of element itself.

    st.push(0);
    ans.push_back(1);

    for (int i = 1; i < n; i++)
    {
        while (st.empty() == false && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        int span;
        if (st.empty())
        {
            span = i + 1;
        }

        else
        {
            span = i - st.top();
        }

        ans.push_back(span);
        st.push(i);
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    // vector<int> ans = spanArray(arr, 10);
    vector<int> ans = stockSpan(arr, 10);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}

#include <iostream>
#include <unordered_set>
using namespace std;

// Naive Solution where TC is O(m*(m+n)) with Auxiliary space of O(1)
int intersectionNaive(int a[], int b[], int m, int n)
{
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        bool flag = false;
        for (int j = 0; j < i - 1; j++)
        {
            if (a[i] == a[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
        {
            continue;
        }
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                count++;
                break;
            }
        }
    }
    return count;
}

// Efficient Solution where TC is O(m+n) with Auxiliary space of O(m)

int intersectionE(int a[], int b[], int m, int n)
{
    int count = 0;
    unordered_set<int> st;
    for (int i = 0; i < m; i++)
    {
        st.insert(a[i]);
    }

    for (int j = 0; j < n; j++)
    {
        if (st.find(b[j]) != st.end())
        {
            count++;
            st.erase(b[j]);
        }
    }
    return count;
}
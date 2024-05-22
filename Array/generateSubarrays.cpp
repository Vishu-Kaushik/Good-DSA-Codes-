#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

// TC of O(N^2) with space complexity of O(1)
// Idea is to generate all  the subarrays by
int maxLen(vector<int> &A, int n)
{
    // Your code here
    // Brute Force
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += A[j];
            if (sum == 0)
            {
                len = max(len, (j - i + 1));
            }
        }
    }
    return len;
}

int main(int argc, char const *argv[])
{

    return 0;
}
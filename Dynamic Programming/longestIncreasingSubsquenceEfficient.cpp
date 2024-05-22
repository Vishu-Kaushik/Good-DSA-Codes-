#include <iostream>
#include <vector>
using namespace std;
// THis solution uses binary search
int ceilInd(vector<int> &tail, int l, int r, int x)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (tail[m] >= x)
        {
            r = m;
        }
        else
        {
            l = m + 1;
        }
    }
    return r;
}
// Time Complexity is O(nlog n) and Auxiliary Space is O(n)
int longestIncreasingSubsequence(int nums[], int n)
{
    vector<int> tail;
    tail.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > tail[len - 1])
        {
            tail[len] = nums[i];
            len++;
        }
        else
        {
            int c = ceilInd(tail, 0, len - 1, nums[i]);
            tail[c] = nums[i];
        }
    }
    return len;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 5, 18, 7, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubsequence(arr, size);
    return 0;
}

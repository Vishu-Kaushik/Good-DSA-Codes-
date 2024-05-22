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

int longestSubarray(vector<int> &a, long long k)
{
    // map is of type such that it stores sum and index till which this is the sum
    // THis solution only works for positve and negatives but not for positves and zeroes
    // TC while using  ordered map is O(NlogN) and while using unordered_map is O(N) but if there are overlaping sum then the TC becoms O(N^2)
    map<long long, int> presummap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        if (sum == k)
        {
            maxLen = i + 1;
        }
        long long rem = sum - k;
        if (presummap.find(rem) != presummap.end())
        {
            int len = i - presummap[rem];
            maxLen = max(maxLen, len);
        }
        if (presummap.find(sum) == presummap.end())
        {
            presummap[sum] = i;
        }
    }
    return maxLen;
}

// When the array contains only positives and zereos then the optimal solution would be of using two pointers algorithm\
// Here the Time Complexity will become O(2N) and Space COmplexity will be O(1)
int longestSubarray(vector<int> &a, long long k)
{
    int left = 0;
    int right = 0;

    int maxLen = 0;
    long long sum = 0;
    int size = a.size();
    while (right < size)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        sum += a[right];
    }
    return maxLen;
}

int main(int argc, char const *argv[])
{

    return 0;
}
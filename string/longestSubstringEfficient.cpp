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

// This is a technique of checkning that current element of the string has occured previously before the starting
// index of current window ...
int longestSubstring(string &str)
{
    vector<int> prev(256, -1);
    int res = 0;
    int i = 0;
    int n = str.length();
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[str[j]] = j;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << longestSubstring(s);
    return 0;
}
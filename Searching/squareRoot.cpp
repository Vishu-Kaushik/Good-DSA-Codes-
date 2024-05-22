#include <iostream>
using namespace std;
// This ques can be solved using Binary search
int sqRoot(int x)
{
    int low = 1, high = x;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int sq = mid * mid;
        if (sq == x)
        {
            return ans;
        }
        else if (sq > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int y;
    cin >> y;
    cout << sqRoot(y);
    return 0;
}

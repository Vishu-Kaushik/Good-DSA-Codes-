#include <iostream>
using namespace std;

// Naive Solution-- > uses two loops finding number of groups and then finding minimun of it
void grps(int arr[], int n)
{
    int grp1 = 0, grp0 = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i - 1] == 1)
            {
                grp1++;
            }
            else
            {
                grp0++;
            }
        }
    }
    if (arr[n - 1] == 1)
    {
        grp1++;
    }
    else
    {
        grp0++;
    }
    cout << grp1 << " " << grp0;
}

// Efficient Solution --> Uses one loop with TC O(N) and O(1) aux. space
/* Idea --> There are only two possibilities:
            1. Groups Counts  of 0's and 1's differ by one --> So the element which is at 1st position that group is more in number so 2nd group that appear should be
            changed or fliped
            2. Group counts are same
*/

int minFlips(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
            {
                cout << "From " << i << "to";
            }
            else
            {
                cout << i - 1 << endl;
            }
        }
    }
    if (arr[n - 1] != arr[0])
    {
        cout << n - 1 << endl;
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0};
    grps(arr, 12);
    return 0;
}

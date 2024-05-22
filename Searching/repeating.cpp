#include <iostream>
using namespace std;

// THis is a bit different ques . where the smallest element in the array is 1 in place of 0
/*Conditions:
1. Array size, n>=2
2. Only one element Repeats (Any number of times)
3. All the elements from 0 to max(arr) are present therefore 1<= max(arr) <=n-1
*/
// solution is O(N) and O(1) auxiliary space

int repeating(int arr[], int size)
{
    int slow = arr[0], fast = arr[0];
    do // here we move fast by two steps nd slow by 1 step
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
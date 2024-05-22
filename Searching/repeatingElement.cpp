#include <iostream>
using namespace std;
/*Conditions:
1. Array size, n>=2
2. Only one element Repeats (Any number of times)
3. All the elements from 0 to max(arr) are present therefore 0<= max(arr) <=n-2
*/
// Solution with O(n) time and space
int repeatingElement(int arr[], int n)
{
    bool visited[n - 1] = {false};
    for (int i = 0; i < n; i++)
    {
        if (visited[arr[i]])
        {
            return arr[i];
        }
        visited[arr[i]] = true;
    }
    return -1;
}
// Efficient Solution
int repeating(int arr[], int n)
{
    int slow = arr[0] + 1, fast = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast]] + 1;
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    }
    return slow - 1;
}
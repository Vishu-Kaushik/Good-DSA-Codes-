#include <iostream>
using namespace std;
// Majority Element is the element which appears more than size/2 times
// Moore's voting algorithm
int majorityElement(int arr[], int n)
{
    int maj = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[maj] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            maj = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[maj] == arr[i])
        {
            count++;
        }
    }
    if (count <= n / 2)
    {
        maj = -1;
    }
    return maj;
}
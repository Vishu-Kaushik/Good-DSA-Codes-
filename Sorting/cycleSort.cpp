#include <iostream>
#include <algorithm>

using namespace std;
/*
1. A worst case O(n^2) algorithm
2. Does minimum memory writes and can be useful where memory writes are costly
3. In-Place and Not Stable
4. ques. like to find minimum no. of swaps required to sort an array
5. Task: To make changes in sort function for repetitive elements....-> Not done
*/
// This function is for distinct elements only
void cycleSort(int arr[], int n)
{
    // count number of memory writes
    int writes = 0;
    // traverse array elements and put it to on
    // the right place
    for (int cs = 0; cs < n - 1; cs++)
    {
        // initialize item as starting point
        int item = arr[cs];
        // Find position where we put the item. We basically
        // count all smaller elements on right side of item.
        int pos = cs;
        for (int i = cs + 1; i < n; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }
        // If item is already in correct position
        if (pos == cs)
            continue;

        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;
        // put the item to it's right position
        if (pos != cs)
        {
            swap(item, arr[pos]);
            writes++;
        }

        while (pos != cs)
        {
            pos = cs;
            for (int i = cs + 1; i < n; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
            }
            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;
            // put the item to it's right position
            if (item != arr[pos])
            {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
}
/* Method 2 -- > This method is only applicable when given array values or elements are in the range of 1 to N or  0 to N. In this method, we do not need to
rotate an array

Approach : All the given array values should be in the range of 1 to N or 0 to N. If the range is 1 to N  then every array element’s correct position will
be the index == value-1 i.e. means at the 0th index value will be 1 similarly at the 1st index position value will be 2 and so on till nth value.

similarly for 0 to N values correct index position of each array element or value will be the same as its value i.e. at 0th index 0 will be there 1st position 1
will be there.
*/
void cyclicSort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        // as array is of 1 based indexing so the
        // correct position or index number of each
        // element is element-1 i.e. 1 will be at 0th
        // index similarly 2 correct index will 1 so
        // on...
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct])
        {

            // if array element should be lesser than
            // size and array element should not be at
            // its correct position then only swap with
            // its correct position or index value
            swap(arr[i], arr[correct]);
        }
        else
        {

            // if element is at its correct position
            // just increment i and check for remaining
            // array elements
            i++;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cycleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
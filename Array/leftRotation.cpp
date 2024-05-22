#include <iostream>
using namespace std;
// My method So TC is O(n) and Auxiliary Space is Theta(n)
void leftRotate(int arr[], int n, int d)
{
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[(i + 2) % n];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr2[i];
        cout << arr[i] << " ";
    }
}
/*Method 1--> is to rotate the array by one d times....This takes TIme complexity of Theta(nd)
and auxiliary space of O(1) */
void leftRotatebyone(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}
void leftRotateByD(int arr[], int n, int d)
{
    for (int i = 0; i < d; i++)
    {
        leftRotatebyone(arr, n);
    }
}
// Method 2 --> WIth TC of O(n+d) and aux Space as O(d)
void leftRotateByD2(int arr[], int n, int d)
{
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[n - d + i] = temp[i];
    }
}

// Method 3 --> Reversal Algorithm

void reverse(int arr[], int low, int high)
{
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

void leftrotate(int arr[], int n, int d)
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    leftrotate(a, 5, 2);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

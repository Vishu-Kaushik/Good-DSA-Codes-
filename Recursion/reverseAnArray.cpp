#include <iostream>
using namespace std;
// Using double POinters
void swapp(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    swap(arr[low], arr[high]);
    low++;
    high--;
    swapp(arr, low, high);
}
// Using single Variable
void s(int arr[], int i, int n)
{
    if (i >= n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    s(arr, i + 1, n);
}
int main(int argc, char const *argv[])
{
    int n;
    int arr[] = {1, 2, 4, 5, 2};
    n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    swapp(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    s(arr, 0, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

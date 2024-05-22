#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}
int main(int argc, char const *argv[])
{
    // int n=10;

    int arr[10];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubbleSort(arr, 10);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

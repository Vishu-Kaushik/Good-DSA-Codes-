#include<iostream>
using namespace std;
// This sorting Algorithm is not a stable algorithm
//TC is theta(n^2) and auxiliary space is theta(n)
void selectionSort(int arr[],int n)
{
    int temp[n];
    for(int i=0;i<n;i++)
    {
        int min_ind=i;
        for (int j = 1; j < n; j++)
        {
            if(arr[j] <  arr[min_ind])
            {
                min_ind=j;
            }
        }
        temp[i]=arr[min_ind];
        arr[min_ind]=INT8_MAX;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i]=temp[i];
    }
}
// In Place Implementation Where AS is O(1)
void selectionSort1(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {
        int min_ind=i;
        for (int j = 0; j < n; j++)
        {
            if(arr[j] < arr[min_ind])
            {
                min_ind=j;
            }
        }
        swap(arr[i],arr[min_ind]);   
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    selectionSort(arr,n);
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

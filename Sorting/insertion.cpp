#include<iostream>
using namespace std;

/*
1. Worst case Time Complexity is theta(n^2)
2. Best case time complexity is theta(n)
3. overall it is O(n^2)
4. stable and inplace algorithm
5. better for small sized arrays
*/
void insertionSort(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    {   
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionSort(arr,n);
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

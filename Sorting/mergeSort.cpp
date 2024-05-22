/*Merge Sort
1. It is a divide and conquer algoritm 
2. It is a stable algorithm
3. Time complexity is O(n logn ) and auxiliary space is O(n)
4. Well suited for linked list and works in O(1) time
5. Used in external Sorting
6. In general for arrays , Quicksort outperforms it. 
7. For elements in power of 2 work done by this algorithm is levels*O(n)
8. For elements not in power of 2 work done by this algorithm is floor(levels)*O(n)
*/
#include<iostream>
using namespace std;

void merge(int arr[], int low , int mid, int high)
{
    int left=mid-low+1;
    int right= high-mid;
    int lh[left], rh[right];
    for(int i=0;i<left;i++)
    {
        lh[i]=arr[i+low];
    }
    for(int i=0;i<right;i++)
    {
        rh[i]=arr[left+i];
    }
    int i=0,j=0,k=0;
    while(i<left && j< right)
    {
        if(lh[i]<=rh[j])
        {
            arr[k]=lh[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=lh[j];
            k++;
            j++;
        }
    }
    while(i<left)
    {
        arr[k]=lh[i];
            k++;
            i++;
    }
    while(j<right)
    {
        arr[k]=lh[j];
            k++;
            j++;
    }
}

void mergeSort(int arr[], int low,int high)
{
    if(low<high)
    {   
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
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
    mergeSort(arr,1,7);
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
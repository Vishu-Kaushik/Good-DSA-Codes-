#include <iostream>
using namespace std;
//  it takes O(nlogn) time and uses concept of heap data structure
// It is used as simmpler algorithm in hybrid algorithm
void maxHeapify(int a[],int size,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<size && a[left]>a[largest])
    {
        largest=left;
    }
    if(right<size && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        maxHeapify(a,size,largest);
    }
}

void buildHeap(int a[],int n)
{
    for (int i = (n-2)/2; i >=0; i--)
    {
        maxHeapify(a,n,i);
    }
}
void heapSort(int a[],int n)
{
    buildHeap(a,n);
    for (int i = n-1; i >0; i--)
    {
        swap(a[0],a[i]);
        maxHeapify(a,i,0);
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
    heapSort(arr,n);
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
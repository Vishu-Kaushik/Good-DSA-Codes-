// this is quick sort implementation using lomuto partition
#include<iostream>
using namespace std;

int lomuto(int a[], int l,int h)
{
    int pivot=a[h];
    int i=l-1;
    for(int j=l;j<=h-1;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],pivot);
    return i+1;
}

void qsort(int a[], int low,int high)
{
    if(low<high)
    {
        int p = lomuto(a,low,high);
        qsort(a,low,p-1);
        qsort(a,p+1,high);
    }
}
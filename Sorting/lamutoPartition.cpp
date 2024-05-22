#include<iostream>
using namespace std;
/*
1. Not a stable algorithm
2. TC is O(n) and AS is O(1)

*/
int lamuto(int a[], int l, int h)
{ 
    // Default we assume that the pivot is the last element ... If it is not last element the do this
    // swap(arr[p],arr[h]) --> then continue the lamuto partition technique
    int pivot=a[h]; // We consider that pivot elemnt is always at last i.e-->h 
    int i=l-1;  // window of smaller elements
    for (int j = l; j <= h-1; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],pivot);  // window of the small elements than pivot are l to i
    return i+1;         // index of the pivot element after swappings
    
}

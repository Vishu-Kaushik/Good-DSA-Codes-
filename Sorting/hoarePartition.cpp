#include<iostream>
using namespace std;
/*
1. It is not stable algorithm
2. Does less swapping than lomuto partition
3. TC is O(n) and AS is O(1)
4. It is seen that it works 3 times faster than lomuto partition
*/
int hoare(int a[], int l, int h)
{
    // Here we assume that the pivot is the first element and if it is not then we swap the given pivot
    // with arr[l] i.e swap(arr[p],arr[l])
    int pivot=a[l];
    int i=l-1;
    int j=h+1;
    int res;
    while(i<=j)
    {
        do
        {
            i++;
        } while (a[i]<pivot);
         do
        {
            j--;
        } while (a[j]>pivot);
        if(i>=j)
        {
            res= j;
            break;
        }
        swap(a[i],a[j]);
    }
    return res;
}
int main(int argc, char const *argv[])
{
    // int n;
    // cin>> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }
    int arr[]{40,7,21,69,9,10};
    cout<<hoare(arr,0,6)<<endl;
     for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
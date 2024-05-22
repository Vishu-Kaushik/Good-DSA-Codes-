#include <iostream>
#include<algorithm>
#include<random>
using namespace std;
/*
1. TC for best case is O(n logn)....... T(n)=2T(n/2)+ theta(n)
2. TC for worst case is O(n^2)........  T(n)=T(n-1)+ theta (n)
3. TC for avearge case is O(n logn)
4. AS for worst case is O(n)
5. AS for best case is O(log n)  .... both require space for recursion call stack only 
*/

int hoare (int a[], int l,int h)
{
    int pivot=a[l];
    int i=l-1,j=h+1;
    while(true)
    {
        do
        {
            i++;
        } while (a[i]<pivot);
        
        do
        {
            j--;
        } while (a[j]>pivot);
        if(i>=j){
            return j;
        }
        swap(a[i],a[j]);
    }
}

void qSort(int a[],int l,int h)
{
    // Begin:
    if(l<h)
    { 
        // For adversary analysis we generate a random number from l to h
        
        // int p= rand(l,h);
        // swap(a[l],a[p]);
        int p=hoare(a,l,h);
        qSort(a,l,p);
        qSort(a,p+1,h);        
        // Tail recursive approach --> this is done to optimize the space is requires for sorting
        // We can replace this with the part which take more space or have more elements
        /* l=p+1;
           goto Begin:*/
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
    qSort(arr,0,n);
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
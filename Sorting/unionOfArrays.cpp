#include<iostream>
using namespace std;
// TC is O(m+n) and AS is O(1)
void union1( int a[],int b[], int m, int n)
{
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(i>0 && a[i]==a[i-1])
        {
            i++;
            continue;
        }
        if(j>0 && a[j]==a[j-1])
        {
            j++;
            continue;
        }
        if(a[i]<b[j]){
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]>b[j]){
            cout<<b[j]<<" ";
            j++;
        }
        else {
            cout<<a[i]<<" ";
            i++;
            j++;
        }
    }
    while(i<n && a[i]!=a[i-1])
    {
        cout<<a[i]<<" ";
        i++;
    }
    while(j<m && b[j] != b[j-1])
    {
        cout<<a[i]<<" ";
        i++;
    }
}
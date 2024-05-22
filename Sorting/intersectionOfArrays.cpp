#include<iostream>
using namespace std;
// Naive approach theta(m*n)
void intersection(int a[],int b[], int m, int n) 
{
    for (int  i = 0; i < m; i++)
    {
        if(i>0 && a[i]==a[i-1])// to handle same elements
        {
            i++;
            continue;
        }
        for (int j = 0; j < m; j++)
        {
             if(a[i]==b[j])
             {
                cout<<a[i]<<" ";
                break;
             }
        }
    }   
}
// efficient approach theta(m+n)
void intersection1(int a[],int b[], int m, int n)
{
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(i>0 && a[i]==a[i-1]){
            i++;
            break;
        }
        if(a[i]>b[j]){
            j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else {
            cout<< a[i]<<" ";
            i++;
            j++;
            break;
        }
    }
}
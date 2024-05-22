#include<iostream>
using namespace std;
//TC is clearly theta(n) == AS
void merge(int arr[],int low , int mid, int high)
{
    int left=mid-low+1;
    int right=high-mid;
    int lh[left];
    int rh[right];
    for (int i = 0; i < mid; i++)
    {
        lh[i]=arr[low+i];
    }
    for (int j=0;j<right;j++)
    {
        rh[j]=arr[left+j];
    }
    int i=0,j=0;
    int a=0;
    while(left< mid && right< high)
    {
        if(lh[i]<=rh[j])
        {
            arr[a]=lh[i];
            a++;
            i++;
        }
        if(lh[i]>rh[j])
        {
            arr[a]=rh[j];
            a++;
            j++;
        }
    }
    while(i<mid){
        arr[a]=lh[i];
        a++;
        i++;
    }
    while(j<right){
        arr[a]=rh[j];
        a++;
        j++;
    }

}
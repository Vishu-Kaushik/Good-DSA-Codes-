#include<iostream>
using namespace std;

//Method 1 --> naive Method with TC as O(n^2)
void twoOdd(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }
            
        }
        if(count%2!=0)
        {
            cout<<arr[i]<<" ";
        }
    }
}
//Method 2 --> With TC of O(n)
// Idea is behind is XOR of all the elements then finding the right most set bit of the XOR element
void twooOdd(int arr[],int n)
{
    int XOR=0,res1=0,res2=0;
    for (int i = 0; i < n; i++)
    {
        XOR=XOR^arr[i]; 
    }
    int s=XOR&(~(XOR-1));  // Rightmost Bit is 1 
    for(int i=0;i<n;i++)
    {
        if((arr[i]&s)!=0)
        {
            res1=res1^arr[i];   // Divinding them into 2 groups where rightmost bit is 1 and where the other bit has bit as zero
        }
        else{
            res2=res2^arr[i];
        } 
    }
    cout<<res1<<" "<<res2;    
}
int main(int argc, char const *argv[])
{
    int arr[]={3,4,3,4,5,4,4,6,7,7};
    twooOdd(arr,10);
    return 0;
}

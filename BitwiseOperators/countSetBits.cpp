#include<iostream>
using namespace std;
// Naive Solution --> Time Complexity is theta(total bits in x)

int countSetBits (int x)
{
    int res=0;
    while(x>0)
    {
        if((x&1)==1)
        {
            res++;
            x=x>>1;
        }
    }
    return res;
}
//Method 2 --> Brian Kerningan's Algorithm
// It turns off last set bit from right to zero from 1 and all the zereos from last set bit are changed to 1
int countSetBits1(int x)
{
    int res=0;
    while(x>0)
    {
        x=x&(x-1);
        res++;
    }
    return res;
} 
// Method 3 --> Lookup Table .....Watch it

int main(int argc, char const *argv[])
{
    int x=7;
    cout<<countSetBits(7);
    return 0;
}

#include<iostream>
using namespace std;
//Method 1 --> Naive method
bool powerOfTwo(int x)
{
    if(x==0)
    {
        return false;
    }
    while (x!=0)
    {
        if(x%2!=0)
        {
            return false;
        }
        x=x/2;
    }
    return true;
}
//Method 2 --> using brian kerningan's Method
bool powerOfTwo1 (int n)
{
    if(n==0)
    {
        return false;
    }
    return (n&(n-1)==0);
}
//Another Optimization is --->>  return (n!=0) && (n&(n-1)==0); 
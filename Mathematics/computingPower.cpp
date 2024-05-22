#include<iostream>
using namespace std;
/*This concept is based upon the binary representation of the power number.... We simply ignore 
the zero bit and wherever 1 bit is present we just multiply it with the res variable in order 
to compute the power of the number*/
int computation (int x, int n)// Time COmplexity is O(log n) ans auxiliary space is O(1)
{
    int  res=1;
    while (n>0)
    {
        if(n%2!=0)
        {
            res*=x;
        }
        x=x*x;
        n=n/2;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    int x,n;
    cin>>x>>n;
    cout<<computation(x,n);
    return 0;
}

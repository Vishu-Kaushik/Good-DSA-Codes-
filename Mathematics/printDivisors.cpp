#include <iostream>
using namespace std;

void divisors(int n) //Time Complexity is theta(sq.rt(n))
{
    int i=1;
    for (i = 1; i*i < n; i++)
    {
        if(n%i==0)
        {
            cout<<i<<" "; 
        }
    }
    for (; i >=1; i--)
    {
        if(n%i==0)
        {
            cout<<n/i<<" ";
        }
    }
     
}

int main(int argc, char const *argv[])
{
    int a;
    cin>>a;
    divisors(a);
    return 0;
}

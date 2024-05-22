#include<iostream>
#include<algorithm>
using namespace std;
bool checkPrime(int a)
{
    bool flag=true;
    if(a==1)
    {
        return false;
    }
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        {
            flag=false;
            break;
        }
    }
    return flag;
}
void factorsPrime(int a)        //Most Optimized Solution
{
    if(a<=1){return ;}
    for(int i=2;i<a;i++)
    {
        while(a%i==0)
        {
            cout<<i<<" ";
            a=a/i;
        }
    }
    if(a>1)
    {
        cout<<a;
    }
}
//Most Optimized Solution With Time Complexity of O(sq.rtof(n))
void opPrime(int n)
{
    if(n<=1){return ;}
    while(n%2==0)
    {
        cout<<2<<" ";
        n=n/2;
    }
    while(n%3==0)
    {
        cout<<3<<" ";
        n=n/3;
    }
    for(int i=5;i*i<n;i=i+6)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
        while(n%(i+2)==0)
        {
            cout<<i+2<<" ";
            n=n/(i+2);
        }
    }
    if (n>3)
    {
        cout<<n;
    }
    
}
void printPrime(int a)// Time Complexity of this solution is O(nlogn)
{
    for(int i=2;i*i<a;i++)
    {
        if(checkPrime(i))
        {
            int x=i;
            while (a%x==0)
            {
                cout<<i<<" ";
                x=x*i;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int a;
    cin>>a;
   opPrime(a);
    return 0;
}

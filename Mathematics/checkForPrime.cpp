#include<iostream>
#include<algorithm>
using namespace std;
//Naive Method with Time complexity of O(n)
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
/*Efficient Method where Time Complexity of the solution is O(n^1/2)
The idea behind is that factors for a number appear in a pair
such that (x,y) where x*y=number.... so instead of checking it till 
n-1 we check it upto sq.root of n */
bool Eprime (int a)
{
    if (a==1)
    {
        return false;
    }
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            return false;
        }
    }
    return true;
    
}
//most Optimized solution 
bool optPrime(int a)
{
    if(a==1)    {return false;}
    if(a==2 || a==3)   {return true;}
    if(a%2==0 || a%3==0)    {return false;}
    for(int i=5;i*i<=a;i=i+6)
    {
        if(a%i==0 || a%(i+2)==0)    {return false;}
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int a;
    cin>>a;
    if(checkPrime(a))
    {
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
    return 0;
}

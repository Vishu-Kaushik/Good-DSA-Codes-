#include<iostream>
#include<vector>
using namespace std;

void seive(int n)// Time Complexity is O(n*sq.rtof(n))
{
    vector <bool> isprime(n+1,true);
    for (int i = 2; i*i<=n; i++)
    {
        if(isprime[i])
        {
            for(int j=2*i;j<=n;j=j+i)
            {
                isprime.at(j)=false;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            cout<<i<<" ";
        }
    }
    
}
//Efficient Solution with Time Complexity of O(n log logn) --> Which grows very slowly
void opseive(int n)
{
    vector<bool> isprime(n+1, true);
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            cout<<i<<" ";
            for(int j=i*i;j<=n;j=j+i)
            {
                isprime[j]=false;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int a;
    cin>>a;
    opseive(a);
    return 0;
}


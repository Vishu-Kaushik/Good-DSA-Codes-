#include<iostream>
using namespace std;

int jos(int n, int k)
{
    if(n==1)
    {
        return 0;
    }
    else {
        return ((jos(n-1,k)+k)%n);
    }
}
// if the numbering starts from 1 then 
int jos1(int n,int k)
{
    return jos(n,k)+1;
}
int main(int argc, char const *argv[])
{
    cout<<jos(3,2);
    return 0;
}

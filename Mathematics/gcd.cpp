#include<iostream>
#include<algorithm>
using namespace std;
//Efficient Solution 
//Eucledian algorithm --> which says that if b<a then gcd(a,b)==gcd(a-b,b)
int egcd(int a, int  b)
{
    while (a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else {
            b=b-a;
        }
    }
    return a;
}
//optimized Eucledian Algorithm with the Time Complexity ----> log(min(a,b))
int eogcd(int a,int b)
{
    if (b==0)
    {
        return a;
    }
    else{
    return (eogcd(b,a%b));}
} 


//naive solution with Time Complexity of O(min(a,b)).......

int gcd(int a,int b)
{
    int res=min(a,b);
    while (res>0)
    {
        if(a%res==0 && b%res==0)
        {
            break;
        }
        res--;
    }
    return res;

}
int main(int argc, char const *argv[])
{
    int a ,b;
    cin>>a>>b;
    cout<<
    eogcd(a,b);
    return 0;
}
 

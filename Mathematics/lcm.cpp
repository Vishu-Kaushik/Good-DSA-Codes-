#include<iostream>
#include<algorithm>
using namespace std;
//Naive solution where Time complexity is ----> O(a*b-max(a,b))
int lcm(int a,int b)
{
    int res=max(a,b);
    while(true)
    {
        if(res%a==0 && res%b==0)
        {
            return res;
        }
        res++;
    }
    // return res;
}
//Efficient solution using the concept a*b=gcd(a,b)*lcm(a,b).....
//Finding gcd using eucledian Algorithm
int eogcd(int a,int b)
{
    if (b==0)
    {
        return a;
    }
    else{
    return (eogcd(b,a%b));}
} 
int oplcm(int a,int b)
{
    return (a*b)/eogcd(a,b);
}
int main(int argc, char const *argv[])
{
    int a ,b;
    cin>>a>>b;
    cout<<oplcm(a,b);
    return 0;
}
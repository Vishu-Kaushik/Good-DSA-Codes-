#include<iostream>
using namespace std;
/*Rules:1--> Only one disk can be moved at a time
2.No larger Disc above smaller
3.Only the top disc of the tower can be moved
-->This solution needs total of (2^n - 1) Steps
Also here a is source tower , b is auxiliary and c is destination tower
*/
void TOH(int n,char A,char B,char C)
{
    if(n==1)
    {
        cout<<"Move 1 from " << A << " to "<< C<< endl;
        return ;
    }
    TOH(n-1,A,C,B);
    cout<<"Move " <<n<<" from " << A <<" to "<< C << endl;
    TOH(n-1,B,A,C);
}
int main(int argc, char const *argv[])
{
    int n;
    char a,b,c;
    cin>>n;
    TOH(n,'a','b','c');
    return 0;
}

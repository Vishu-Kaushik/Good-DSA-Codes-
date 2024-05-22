#include <iostream>
using namespace std;
// Functional Recursion --> this is method where you want your function to return a value witout using parameters
//                          Very much used in DP where we need a value instead of printing
int suma(int i)
{
    if (i == 0)
    {
        return 0;
    }
    return i + suma(i - 1);
}
// Parameterised Recursion --> This is a method where we pass parameters or we alter the values of the parameters passed in functions
//                              Or we just need to print the value . Also here we use parameters to get our ans.
void suma2(int i, int sum)
{
    if (i == 0)
    {
        cout << sum;
        return;
    }
    suma2(i - 1, sum + i);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << suma(n) << endl;
    suma2(n, 0);
    return 0;
}
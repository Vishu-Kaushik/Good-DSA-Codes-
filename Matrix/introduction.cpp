#include <iostream>
using namespace std;

/*
1. Elements can be stored in row major order(C++ follows this order)
    int arr[m][n]  where m is the number of rows and n is the number of columns
2. Internal curly brackets are optional : int arr[3][2] ={10,20,30,40,50,60}
3. Only the first dimension can be ommitted when we initialize.
    int arr[][2]={{1,2}{3,4}}
    int arr[][2][2]={{{1,2},{3,4}},{{5,6},{7,8}}}
*/
int main(int argc, char const *argv[])
{
    int arr[3][2] = {{10, 20},
                     {30, 40},
                     {50, 60}};
    for (int i = 0; i < 3; i++) // Traversing the rows
    {
        for (int j = 0; j < 2; j++) // Traversing the columns
        {
            cout << arr[i][j] << " ";
        }
    }
    return 0;
}

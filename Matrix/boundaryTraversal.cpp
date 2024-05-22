#include <iostream>
#include <vector>
using namespace std;
const int R = 4; // Number of Rows
const int C = 4; // Number of Columns

void boundaryTraversal(int mat[R][C])
{
    if (R == 1) // Corner Case where number of Rows is 1 to avoid repetition
    {
        for (int i = 0; i < C; i++)
        {
            cout << mat[0][i] << " ";
        }
    }
    else if (C == 1) // Corner Case where number of columns is 1 to avoid repetition
    {
        for (int i = 0; i < R; i++)
        {
            cout << mat[i][0] << " ";
        }
    }
    else
    {
        for (int i = 0; i < C; i++)
        {
            cout << mat[0][i] << " ";
        }
        for (int i = 1; i < R; i++)
        {
            cout << mat[i][C - 1] << " ";
        }
        for (int i = C - 2; i >= 0; i--)
        {
            cout << mat[R - 1][i] << " ";
        }
        for (int i = R - 2; i >= 1; i--)
        {
            cout << mat[i][0] << " ";
        }
    }
}

int main(int argc, char const *argv[])
{
    int mat[R][C] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    boundaryTraversal(mat);
    return 0;
}

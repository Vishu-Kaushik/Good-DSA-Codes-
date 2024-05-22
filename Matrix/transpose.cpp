#include <iostream>
#include <vector>
using namespace std;
const int R = 4;
const int C = 4;
void transpose(int mat[R][C])
{
    int arr[R][C];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            arr[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            mat[i][j] = arr[i][j];
            cout << mat[i][j] << " ";
        }
    }
}
// Efficient Solution also it is inplace way to solve the problem and one Traversal
void transpose1(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = i; j < C; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
}

int main(int argc, char const *argv[])
{
    int mat[R][C] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    transpose1(mat);
    return 0;
}
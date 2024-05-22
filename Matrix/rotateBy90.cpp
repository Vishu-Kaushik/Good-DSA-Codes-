#include <iostream>
using namespace std;
const int R = 3;
// const int C=3;
// Naive Solution where TC is theta(n^2) and AS is Thete(n^2)
// Idea --> 1.last column becomes first row
//          2.First row becomes inverted first column
void rotate(int mat[R][R])
{
    int temp[R][R];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            temp[i][j] = mat[j][R - i - 1]; // temmp[n-j-1][i]=mat[i][j]
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            mat[i][j] = temp[i][j];
        }
    }
}
// Efficient Solution --> TC is O(n^2) and is inplace Algorithm
// Idea --> Step 1 -> Take the transpose of the given matrix
//          Step 2 -> Reverse the column elements
void rotateE(int mat[R][R])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = i + 1; j < R; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }
    for (int i = 0; i < R; i++)
    {
        int low = 0, high = R - 1;
        while (low < high)
        {
            swap(mat[low][i], mat[high][i]);
            low++;
            high--;
        }
    }
}
int main(int argc, char const *argv[])
{
    int mat[R][R] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    rotateE(mat);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
    return 0;
}

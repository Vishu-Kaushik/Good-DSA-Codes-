#include <iostream>
using namespace std;
const int R = 4;
const int C = 5;
// Time Complexity if theta(R*C)
// Idea is to maintain the row Variables(top and bottom) and Column Variables(left and right)
void spiral(int mat[][C], int R)
{
    int left = 0, right = C - 1;
    int top = 0, bottom = R - 1;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++) // print the top row
        {
            cout << mat[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++) // print the right column
        {
            cout << mat[i][right] << " ";
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--) // print the bottom row
            {
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--) // print the left column
            {
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }
}
int main(int argc, char const *argv[])
{
    int mat[R][C] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    spiral(mat, R);
    return 0;
}

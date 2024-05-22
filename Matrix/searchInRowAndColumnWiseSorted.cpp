#include <iostream>
using namespace std;
const int R = 4;
/* Naive Solution --> Traversing Every element and comparing , if we find it then print its index and if not then return it
        with time Complexity of O(R*C)
*/

/*
Efficient Solution with time complexity of O(R+C)
        Idea :  1. Start from top right corner
                2. if x is same then print the position and return
                3. If x is smaller then go to left
                4. If x if greater then go down
            : We can also start from bottom left and go right and up accordingly
*/
// Given that the matrix is row wise and column wise sorted with Time complexity of O(R+C)
void search(int mat[R][R], int x)
{
    // int start = mat[0][R];
    int i = 0, j = R - 1;
    // int end = mat[R][0];
    // Slight optimization
    if (x < mat[0][0] || x > mat[R - 1][R - 1])
    {
        cout << "Element not found";
    }
    while (i < R && j >= 0)
    {
        if (mat[i][j] == x)
        {
            cout << i << " " << j;
            return;
        }
        else if (mat[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    cout << "Element not found";
}
int main(int argc, char const *argv[])
{
    int mat[R][R] = {10, 20, 30, 40, 15, 25, 35, 45, 27, 29, 37, 48, 32, 33, 39, 50};
    search(mat, 29);

    return 0;
}

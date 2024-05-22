#include <iostream>
#include <vector>
using namespace std;
// here we are considering that the sudoku size is 9
class solution
{
    void solveSoduko(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] = '.')
                {
                    for (int c = 1; c <= 9; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;
                            if (solve(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, int c)
    {

        // here we are multiplying with the 3 becoz size of smaller board will be 3x3 only
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            // checking for row
            if (board[row][i] == c)
            {
                return false;
            }
            // checking for column
            if (board[i][col] == c)
            {
                return false;
            }
            // checking for the particular board
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            {
                return false;
            }
        }
        return true;
    }
};
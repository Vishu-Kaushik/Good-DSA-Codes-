#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    /*
    1-->   Here remaining motion of the queen are discarded becoz we are placing the queens from left to right so all the motion of right upper diagonal ,right row, 
    right lower diagonal will surely not have the queen placed there.
    2-->   And the right column motion up and down are not checked becoz we are now trying to check and fill the possible slot to place the queen so there will not be 
            any queen there also.
    
    */
    bool isSafe(int row, int col, vector<string> board, int n)
    {
        int duprow = row;
        int dupcol = col;
        // upper diagonal motion
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] != '.')
            {
                return false;
            }
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        // left row motion
        while (col >= 0)
        {
            if (board[row][col] != '.')
            {
                return false;
            }
            col--;
        }
        row = duprow;
        col = dupcol;
        while (col >= 0 && row < n)
        {
            if (board[row][col] != '.')
            {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }

public:
    void solve(int col, vector<string> board, vector<vector<string>> ans, int n)
    {
        // base case
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveQueen(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(0, board, ans, n);
        return ans;
    }
};

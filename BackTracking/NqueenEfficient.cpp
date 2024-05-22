#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    void solve(int col, vector<string> board, vector<vector<string>> ans, vector<int> leftrow, vector<int> upperdiagonal, vector<int> lowerdiagnoal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && upperdiagonal[n - 1 + col - row] == 0 && lowerdiagnoal[row + col] == 0)
            {
                leftrow[row] = 1;
                upperdiagonal[n - 1 + col - row] == 1;
                lowerdiagnoal[row + col] = 1;
                solve(col + 1, board, ans, leftrow, upperdiagonal, lowerdiagnoal, n);
                leftrow[row] = 0;                      // the following three steps are the backtracking steps which says that when going in we manipulate or alter the
                upperdiagonal[n - 1 + col - row] == 0; //  or alter the data Structure and when coming back to the previous call we
                lowerdiagnoal[row + col] = 0;          //  reverse the changes that we made that we made while going in to find the possible solution
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
        vector<int> leftRow(n, 0), upperdiagonal(2 * n - 1, 0), lowerdiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftRow, upperdiagonal, lowerdiagonal, n);
        return ans;
    }
};

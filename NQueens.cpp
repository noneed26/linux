#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int row, int col, vector<string> &board, int n)
{
    // Check column
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q')
            return false;
    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;
    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;
    return true;
}
bool solve(int row, vector<string> &board, int n)
{
    if (row == n)
    {
        // Print the board
        for (int i = 0; i < n; i++)
            cout << board[i] << endl;
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            if (solve(row + 1, board, n))
                return true;
            board[row][col] = '.'; // Backtrack
        }
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter number of queens (N): ";
    cin >> n;
    vector<string> board(n, string(n, '.'));
    if (!solve(0, board, n))
    {
        cout << "No solution exists.\n";
    }
    return 0;
}
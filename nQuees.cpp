#include <iostream>
#include <vector>
using namespace std;

class NQueen
{

    int n;
    vector<vector<int>> board;

public:
    NQueen(int size)
    {

        n = size;

        board.resize(n, vector<int>(n, 0));
    }

    // Check whether queen can be placed
    bool isSafe(int row, int col)
    {

        // Check upper column
        for (int i = 0; i < row; i++)
        {

            if (board[i][col] == 1)
                return false;
        }

        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {

            if (board[i][j] == 1)
                return false;
        }

        // Check upper right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {

            if (board[i][j] == 1)
                return false;
        }

        return true;
    }

    // Solve row wise
    bool solve(int row)
    {

        // All queens placed
        if (row >= n)
            return true;

        // Try all columns in current row
        for (int col = 0; col < n; col++)
        {

            if (isSafe(row, col))
            {

                // Place queen
                board[row][col] = 1;

                // Move to next row
                if (solve(row + 1))
                    return true;

                // Backtracking
                board[row][col] = 0;
            }
        }

        return false;
    }

    // Print board
    void printBoard()
    {

        cout << "\nSolution Board:\n"
             << endl;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                if (board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }

            cout << endl;
        }
    }

    void start()
    {

        if (solve(0))
            printBoard();
        else
            cout << "Solution does not exist." << endl;
    }
};

int main()
{

    int n;

    cout << "Enter number of queens: ";
    cin >> n;

    NQueen q(n);

    q.start();

    return 0;
}
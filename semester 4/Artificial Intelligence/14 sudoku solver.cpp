#include <bits/stdc++.h>
using namespace std;

#define n 9
bool findEmptyLocation(int grid[][n], int &row, int &col)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;

                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int grid[][n], int row, int col, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeInColumn(int grid[][n], int row, int col, int num)
{

    for (int i = 0; i < n; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    return true;
}

bool isSafeInGrid(int grid[][n], int row, int col, int num)
{

    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + rowFactor][j + colFactor] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int grid[][n], int row, int col, int num)
{
    if (isSafeInRow(grid, row, col, num) && isSafeInColumn(grid, row, col, num) && isSafeInGrid(grid, row, col, num))
    {
        return true;
    }
    return false;
}

bool solveSudoku(int grid[][n])
{
    int row, col;
    if (!findEmptyLocation(grid, row, col))
    {
        return true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;

            if (solveSudoku(grid))
            {

                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}
int main()
{

    int grid[n][n];

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    bool ans = solveSudoku(grid);
    if (ans == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    cout << endl;

    if (ans == true)
    {

        for (int i = 0; i < n; i++)
        {
            if (i % 3 == 0)
            {
                for (int k = 0; k < 7; k++)
                {
                    cout << " _ ";
                }
                cout << endl;
            }
            for (int j = 0; j < n; j++)
            {
                if (j % 3 == 0)
                {
                    cout << "|";
                }

                cout << grid[i][j] << " ";
            }

            cout << endl;
        }
    }
}

// /*
// 8 0 0 0 2 0 7 5 0
// 6 3 0 0 5 0 0 4 0
// 0 3 0 4 0 0 0 1 0
// 2 0 8 0 0 0 0 0 0
// 0 7 0 5 0 9 0 6 0
// 0 0 0 0 0 0 4 0 1
// 0 1 0 0 0 5 0 8 0
// 0 9 0 0 7 0 0 0 4
// 0 8 2 0 4 0 0 0 6
// */
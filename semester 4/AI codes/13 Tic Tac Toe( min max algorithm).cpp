#include <bits/stdc++.h>
using namespace std;

int player = 'x';
int opponent = 'o';

class Move
{
public:
    int row;
    int col;

    Move()
    {
    }
};

int evaluate(char board[3][3])
{

    for (int row = 0; row < 3; row++)
    {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
        {

            if (board[row][0] == 'x')
                return 10;
            else if (board[row][0] == 'o')
                return -10;
        }
    }
    for (int col = 0; col < 3; col++)
    {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
        {

            if (board[0][col] == 'x')
                return 10;
            else if (board[0][col] == 'o')
                return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == player)
            return +10;
        else if (board[0][0] == opponent)
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == player)
            return +10;
        else if (board[0][2] == opponent)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}
bool MovesLeft(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

int minmax(char board[3][3], int depth, int isMax)
{
    int score = evaluate(board);

    if (score == 10 || score == -10)
        return score;

    if (MovesLeft(board) == 0)
        return 0;

    if (isMax)
    {
        int best = INT_MIN;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = player;

                    best = max(best, minmax(board, depth + 1, !isMax));
                    board[i][j] = '_';
                }
            }
        }

        return best;
    }

    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == '_')
                {
                    // Make the move
                    board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                               minmax(board, depth + 1, !isMax));

                    // Undo the move
                    board[i][j] = '_';
                }
            }
        }
            return best;
    }
}
    Move findMove(char board[3][3])
    {

        int bestVal = INT_MIN;
        Move bestMove;
        bestMove.row = -1;
        bestMove.col = -1;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = player;
                }

                int moveVal = minmax(board, 0, false);
                board[i][j] = '_';

                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
        cout << "BestVal: " << bestVal << endl;
        return bestMove;
    }

    int main()
    {

        char board[3][3]{

            {'x', 'o', 'x'},
            {'o', '_', 'x'},
            {'_', 'o', '_'},
        };

        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         cin>>board[i][j];
        //     }

        // }

        Move bestMove = findMove(board);

        cout << "The Solution is :- " << endl;
        cout << "Row " << bestMove.row << "Col :" << bestMove.col << endl;

        return 0;
    }

    // x o x
    // o o x
    // _ _ _
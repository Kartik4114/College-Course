#include <bits/stdc++.h>
using namespace std;

void print(int **solution, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solution[i][j] << " ";
        }
    }
        cout << endl;
}

void mazeHelp(int maze[][18], int n, int **solution, int x, int y)
{

    if (x == n - 1 && y == n - 1)
    {
		solution[x][y]=1;
        print(solution, n);
		solution[x][y]=0;
        return;
    }

    if (x >=n || x < 0 || y >=n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1)
    {
        return;
    }

    solution[x][y] = 1;                    // it is because so that  movement at every index, we can make again all indexes with 1.
    mazeHelp(maze, n, solution, x - 1, y); // for upside movement
    mazeHelp(maze, n, solution, x + 1, y); // for downside movement
    mazeHelp(maze, n, solution, x, y - 1); // for left movement
    mazeHelp(maze, n, solution, x, y + 1); // for right movement

    solution[x][y] = 0; // it is because so that after movement we can make again all indexes with zero.
}

void ratInMaze(int maze[][18], int n)
{

    int **solution = new int *[n];

    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
    }

    mazeHelp(maze, n, solution, 0, 0);
}

int main()
{
    int n;
    cin>>n;

    int maze[18][18];
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>maze[i][j];
        }
        
    }

    ratInMaze(maze,n);
    

    return 0;
}
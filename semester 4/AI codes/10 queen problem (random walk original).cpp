#include <bits/stdc++.h>
#include <vector>
using namespace std;

int board[11][11];

bool isPossible(int n, int row, int col) {
    // checking along col
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

void nqueen_helper(int n, int row, vector<vector<int>>& output) {
    if (row == n) {
        // we have reached some solution.
        // print the matrix.
        vector<int> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // v.push_back(board[i][j]);
                cout<<board[i][j]<<" ";
            }
            cout<<endl;

        }
        cout<<endl;
        // output.push_back(v);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isPossible(n, row, j)) {
            board[row][j] = 1;
            nqueen_helper(n, row + 1, output);
            // as our work has completed at that position, so we will backtrack
            // so that we can check at the next position by placing Q there.
            board[row][j] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> output;
    nqueen_helper(n, 0, output);
    return output;
}

int main() {
    int n;
    cin >> n;

    vector<int>v(n,1);
    vector<vector<int>>input;
    input.push_back(v);

    for (int i = 0; i < n-1; i++)
    {
        vector<int>v1(n,0);
        input.push_back(v1);
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
        
    }
    cout<<endl;

    cout<<"Output: "<<endl;
    
    vector<vector<int>> result;
    result = nQueens(n);


    return 0;
}

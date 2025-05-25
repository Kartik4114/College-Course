#include <iostream>
#include <queue>
using namespace std;

// remember , this is the code for graph which is disconnected also.
// means it has more than one graph component.
// this is the final complete code for any graph

// depth first traversal
void printDFS(int **edges, int n, int sv, bool *visited)
{ // here sv is starting vertex
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (sv == i)
        {
            continue;
        }

        if (edges[i][sv] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

// breadth first traversal
void printBFS(int **edges, int n, int sv, bool *visited) // here sv is starting vertex
{
    queue<int> pendingvertices;

    pendingvertices.push(sv);
    visited[sv] = true;

    while (!pendingvertices.empty())
    {
        int currentvertex = pendingvertices.front();
        pendingvertices.pop();
        cout << currentvertex << endl;

        for (int i = 0; i < n; i++)
        {
            if (i == sv)
            {
                continue; // here we have written this if statement bec. we don't want to check
                          //  that sv(i.e 0) has edge to someone.
            }

            if (edges[currentvertex][i] == 1 && !visited[i])
            {
                pendingvertices.push(i);
                visited[i] = true;
            }
        }
    }
}
// function for DFS traversal in disconnected graph
void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

// function for BFS traversal in disconnected graph
void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }

    delete[] visited;
}

// here we are doing BFS traversal
// here we are using queues for this.

// remember if we have more than 1 edges than we will go to that edge with lower no. of vertex
//  bec. loop is running from 0 to n.
int main()
{
    int n; // vertex
    int e; // edge
    cout << "enter the no. of vertex :" << endl;
    cin >> n;
    cout << "enter the no. of edges :" << endl;
    cin >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];

        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    // inputing the edges which are the vertex
    for (int i = 0; i < e; i++)
    {
        int f; // first vertex
        int s; // second vertex

        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout << "DFS :" << endl;
    DFS(edges, n);
    cout << "BFS :" << endl;
    // BFS(edges, n);
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
// DIJKSTRA ALGORITHM
// this algo. is used to find shortest distance between two nodes.
// in this algo we can hav cycles but no negative weights allowed. (IMP.)
// here in this code time complexity will be O(n^2);
// but we can improve it.
// IMPROVISATION IS MENTIONED IN CODE ITSELF JUST GO THROUGH THAT
// AFTER IMPROVISATION TIME COMPLEXITY WILL BE (E+V)LOG(V).
//               JUST CODE IT BRO!!!!
// Prefer to go through prims algorithm .You will have better understanding.

#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *distance, bool *visited, int n)
{

    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minvertex == -1 || distance[i] < distance[minvertex]))
        {
            minvertex = i;
        }
    }
    return minvertex;
}
void dijkstra(int **edges, int n)
{

    int *distance = new int[n];
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minvertex = findMinVertex(distance, visited, n);
        visited[minvertex] = true;

        for (int j = 0; j < n; j++)
        {
            if (edges[minvertex][j] != 0 && !visited[j])
            {
                int dist = distance[minvertex] + edges[minvertex][j];

                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }
    delete[] visited;
    delete[] distance;
}

int main()
{
    int n, E; // here n=no. of vertices and E is edges
    cin >> n >> E;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // inputting the weights.
    for (int i = 0; i < E; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;

        edges[f][s] = weight;
        edges[s][f] = weight;
    }

    cout << endl;

    dijkstra(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
// 5 7 
// 0
// 0 1 4
// 0 2 8
// 1 3 6
// 1 2 2
// 2 3 3
// 2 4 9
// 3 4 5
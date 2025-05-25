#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int V; // No. of vertices
    struct Node** adj; // Array of adjacency lists
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; ++i)
        graph->adj[i] = NULL;
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int v, int w) {
    struct Node* newNode = createNode(w);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;

    newNode = createNode(v);
    newNode->next = graph->adj[w];
    graph->adj[w] = newNode;
}

// Function to detect cycle in the graph using DFS
int isCyclicUtil(struct Graph* graph, int v, int* visited, int parent) {
    visited[v] = 1; // Mark the current node as visited

    struct Node* current = graph->adj[v];
    while (current != NULL) {
        int neighbor = current->data;

        if (!visited[neighbor]) {
            // If an adjacent vertex is not visited, then recur for that adjacent
            if (isCyclicUtil(graph, neighbor, visited, v))
                return 1;
        } else if (neighbor != parent) {
            // If an adjacent vertex is visited and is not the parent of the current vertex, then there exists a cycle
            return 1;
        }

        current = current->next;
    }

    return 0;
}

// Function to check if there is a cycle in the graph
int isCyclic(struct Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));

    for (int i = 0; i < graph->V; i++)
        visited[i] = 0; // Mark all the vertices as not visited

    for (int u = 0; u < graph->V; u++) {
        if (!visited[u]) {
            // Don't recur for u if it is already visited
            if (isCyclicUtil(graph, u, visited, -1))
                return 1; // Cycle detected
        }
    }

    free(visited);

    return 0; // No cycle detected
}

// Driver program to test above functions
int main() {
    struct Graph* g1 = createGraph(5);
    addEdge(g1, 1, 0);
    addEdge(g1, 0, 2);
    addEdge(g1, 2, 1);
    addEdge(g1, 0, 3);
    addEdge(g1, 3, 4);
    isCyclic(g1) ? printf("Graph contains cycle\n") : printf("Graph doesn't contain cycle\n");

    struct Graph* g2 = createGraph(3);
    addEdge(g2, 0, 1);
    addEdge(g2, 1, 2);
    isCyclic(g2) ? printf("Graph contains cycle\n") : printf("Graph doesn't contain cycle\n");

    // Free allocated memory
    free(g1->adj);
    free(g1);
    free(g2->adj);
    free(g2);

    return 0;
}

// Time Complexity: O(V+E), The program does a simple DFS Traversal of the graph 
// which is represented using an adjacency list. So the time complexity is O(V+E).
// Auxiliary Space: O(V), To store the visited array O(V) space is required.
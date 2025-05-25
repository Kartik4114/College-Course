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
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Function to check if there is a cycle in the graph
int isCycle(struct Graph* graph) {
    // Create an array to store in-degrees of all vertices
    int* in_degree = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; ++i)
        in_degree[i] = 0;

    // Traverse adjacency lists to fill in-degrees of vertices
    for (int u = 0; u < graph->V; ++u) {
        struct Node* current = graph->adj[u];
        while (current != NULL) {
            in_degree[current->data]++;
            current = current->next;
        }
    }

    // Create a queue and enqueue all vertices with in-degree 0
    int* queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = -1;

    for (int i = 0; i < graph->V; ++i) {
        if (in_degree[i] == 0)
            queue[++rear] = i;
    }

    // Initialize count of visited vertices
    int cnt = 1;

    // Traverse the queue and enqueue adjacent vertices if in-degree becomes 0
    while (front <= rear) {
        int u = queue[front++];
        struct Node* current = graph->adj[u];
        
        // Iterate through all adjacent nodes of dequeued node u
        while (current != NULL) {
            // If in-degree becomes zero, enqueue it
            if (--in_degree[current->data] == 0) {
                queue[++rear] = current->data;
                // Increment the count
                cnt++;
            }
            current = current->next;
        }
    }

    // Check if there was a cycle
    int result = (cnt != graph->V);

    // Free allocated memory
    free(in_degree);
    free(queue);

    return result;
}

// Driver program to test above functions
int main() {
    // Create a graph given in the above diagram
    struct Graph* g = createGraph(6);
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);

    if (isCycle(g))
        printf("Yes\n");
    else
        printf("No\n");

    // Free allocated memory
    free(g->adj);
    free(g);

    return 0;
}

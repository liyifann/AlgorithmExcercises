#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 9

// find the vertex with minimum distance value,
// from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// print shortest path from source to j
// using parent array (recursive)
void printPath(int parent[],int j) {
    // if j is source
    if (parent[j]==-1)
        return;

    printPath(parent,parent[j]);

    printf("%d ", j);
}

// print the construted distance array
int printSolution(int dist[], int parent[])
{
    int src=0;
    printf("Vertex\t  Distance\tPath");
    for (int i=1;i<V;i++)
    {
        printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i], src);
        printPath(parent, i);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];    // The output array. dist[i] will hold the shortest
                    // distance from src to i

    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                    // path tree or shortest distance from src to i is finalized/

    int parent[V];  // parent array to store shortest path tree
    parent[0] = -1;

    // The idea is to create a separate array parent[]. 
    // Value of parent[v] for a vertex v stores parent vertex of v
    // in shortest path tree. Parent of source vertex is -1.
    // Whenever we find shorter path through a vertex u,
    // we make u as parent of current vertex.

    // Initialize
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }   
    }
    printSolution(dist, parent);
}

int main() {
    int graph[V][V] = {{0, 4,  0, 0,  0,  0,  0, 8,  0},
                       {4, 0,  8, 0,  0,  0,  0, 11, 0},
                       {0, 8,  0, 7,  0,  4,  0, 0,  2},
                       {0, 0,  7, 0,  9,  14, 0, 0,  0},
                       {0, 0,  0, 9,  0,  10, 0, 0,  0},
                       {0, 0,  4, 14, 10, 0,  2, 0,  0},
                       {0, 0,  0, 0,  0,  2,  0, 1,  6},
                       {8, 11, 0, 0,  0,  0,  1, 0,  7},
                       {0, 0,  2, 0,  0,  0,  6, 7,  0}};

    dijkstra(graph, 0);
    return 0;
}
#include <iostream>
#include <climits>

using namespace std;
#define V 5

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        if (sptSet[i] == false && dist[i] < min)
            min = dist[i], min_index = i;
    return min_index;
}

void printSolution(int dist[], int n) {
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < n; i++)
        cout << i + 1 << "         " << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    // Initialize
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, V);
}

int main() {
    int graph[V][V] = {{0, 10, 0,  30, 100},
                       {0, 0,  50, 0,  0},
                       {0, 0,  0,  0,  10},
                       {0, 0,  20, 0,  60},
                       {0, 0,  0,  0,  0}};
    dijkstra(graph, 0);
    return 0;
}
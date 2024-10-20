#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(vector<double>& dist, vector<bool>& sptSet, int N)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < N; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance
void printSolution(vector<double> dist, int N)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " \t\t\t\t" << dist[i] << endl;
    }
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(vector<vector<double>>& graph, int src, int N)
{
    vector<double> dist(N, INT_MAX); // dist[i] will hold the shortest distance from src to i
    vector<bool> sptSet(N, false); // sptSet[i] will be true if vertex i is included in shortest path

    dist[src] = 0;    // Distance of source vertex from itself is 0

    // Find shortest path for all vertices
    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, sptSet, N); // Pick the minimum distance vertex
        sptSet[u] = true;

        for (int v = 0; v < N; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // Print the constructed distance array
    printSolution(dist, N);
}

bool getGraph(vector<vector<double>>& graph, int& N) {
    cout << "Please enter the graph dimension (N*N): \nN = ";
    cin >> N;

    if (N <= 0) {
        cout << "Error: Invalid graph size (N must be greater than 0)." << endl;
        return false;
    }

    graph.resize(N, vector<double>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Enter value for edge (" << i << "," << j << "): ";
            cin >> graph[i][j];

            if (graph[i][j] < 0) {
                cout << "Error: Dijkstra's algorithm does not support negative weights!" << endl;
                return false;
            }
        }
    }
    return true;
}

int main() {
    
    int N, src;
    vector<vector<double>> graph;

    // Get the graph first
    if (!getGraph(graph, N)) {
        return 1; // Exit if invalid graph
    }

    // Now get the source vertex after reading the graph
    cout << "Enter source vertex (0 to " << N-1 << "): ";
    cin >> src;

    if (src < 0 || src >= N) {
        cerr << "Error: Invalid source vertex." << endl;
        return 1;
    }

    // Run Dijkstra's algorithm
    dijkstra(graph, src, N);

    return 0;
}







// Part of the code is base on shivanisinghss2110 code from "greekforgreeks" for dijkstra's algorithm

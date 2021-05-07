#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(V^2)
vector<int> Dijkstra(vector<int> graph[], int V, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> vis(V, false);
    dist[src] = 0;

    for (int cnt = 0; cnt < V; cnt++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!vis[i] && (u == -1 || dist[i] < dist[u])) u = i;

        vis[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !vis[v])
                dist[v] = min(dist[v], dist[u] + graph[u][v]);
        }
    }
    return dist;
}

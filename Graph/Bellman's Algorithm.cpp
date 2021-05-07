#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(V.E)

vector<int> Bellman(int graph[][3], int V, int E, int src) {
    vector<int> dis(V, INT_MAX);
    dis[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] < graph[j][1]) {
                dis[graph[j][1]] = dis[graph[j][0]] + graph[j][2];
            }
        }
    }

    for (int i = 0; i < E; i++) {
        int x = graph[i][0];
        int y = graph[i][1];
        int wght = graph[i][2];
        // Negative Graph
        if (dis[x] != INT_MAX && dis[x] + wght < dis[y]) return {};
    }
    
    return dis;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> order; // Stores the Topological Order

// Returns 1 if there exist TopoSort, 0 if exists cycle.
bool toposort(vector<int> graph[], int V) {
    queue<int> q;
    vector<int> indeg(V + 1, 0);
    for (int i = 1; i <= V; i++)
        for (auto &it : graph[i]) indeg[it]++;

    for (int i = 1; i <= V; i++) {
        if (!indeg[i]) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto &v : graph[u]) {
            indeg[v]--;
            if (!indeg[v])
                q.push(v);
        }
    }
    return (order.size() == V);
}

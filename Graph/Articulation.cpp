#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int node, int parent, vector<int> &vis, vector<int> &tim, vector<int> &low, int timer, vector<bool> &res) {
    vis[node] = true;
    tim[node] = low[node] = timer++;
    int child = 0;

    for (auto it : adj[node]) {
        if (it == parent) continue;

        if (!vis[it]) {
            dfs(adj, it, node, vis, tim, low, timer, res);
            low[node] = min(low[node], low[it]);
            if (low[it] >= tim[node] && parent != -1) res[node] = true;
            child++;
        }
        else low[node] = min(low[node], tim[it]);
    }
    
    if (parent == -1 && child > 1) res[node] = 1;
}

vector<bool> BridgeGraph(vector<int> adj[], int V) {
    vector<int> tim(V, -1), low(V, -1), vis(V, 0);
    vector<bool> res(V, false);
    int timer = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs(adj, i, -1, vis, tim, low, timer, res);
    }
    return res;
}

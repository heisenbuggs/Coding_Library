// Find Connected Components in an undirected graph.
#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> adj, int V) {
    vector<bool> vis(V);
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            findComps(adj, vis, i);
            cout << "\n";
        }
    }
}

void findComps(vector<vector<int>> adj, vector<bool> vis, int v) {
    vis[v] = true;
    cout << v << " ";

    for(auto it: adj[v]){
        if(!vis[it]) findComps(adj, vis, it);
    }
}

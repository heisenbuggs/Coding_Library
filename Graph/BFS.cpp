#include <bits/stdc++.h>
using namespace std;
// Time Compexity = O(V+E)

const int n = 1000;

/*
*   vis : stores nodes which are visited.
*   dist : stores levels
*   ways : stores the number of ways from kth vertex 
*   to any other vertex with the shortest path taken
*   adj : adjacency list graph
*/

vector<int> vis(n,0), dist(n,0), ways(n,0), parent(n);

void bfs(vector<vector<int>> adj, int src) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    ways[src] = 1;
    parent[src] = -1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto x: adj[node]) {
            if(!vis[x]) {
                q.push(x);
                vis[x] = 1;
                dist[x] = dist[node] + 1;
                ways[x] += ways[node];
                parent[x] = node;
            }
            else {
                if(dist[node]+1==dist[x]) {
                    ways[x] += ways[node];
                }
            }
        }
    }
    return;
}

/*
* Finding the Shortest Path from source to some vertex u.
*/

vector<int> findPath(vector<int> parent, int u) {
    vector<int> path;
    if(!vis[u]) cout << "No Path\n";
    else {
        for(int v=u; v!=-1; v=parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());
    }
    return path;
}

#include <bits/stdc.h>
using namespace std;
const int n = 1000;

/*
*   vis : stores nodes which are visited.
*   dist : stores levels
*   ways : stores the number of ways from kth vertex 
*   to any other vertex with the shortest path taken
*   adj : adjacency list graph
*/

vector<int> vis(n,0), dist(n,0), ways(n,0), adj(n);

void bfs(int src) {
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    ways[src] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto x: adj[node]) {
            if(!vis[x]) {
                vis[x] = 1;
                dist[x] = dist[node] + 1;
                ways[x] += ways[node];
                q.push(x);
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

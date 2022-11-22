#include <bits/stdc++.h>
using namespace std;
 

void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}
 

bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{

    list<int> queue;
 

    bool visited[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
 
                // We stop BFS when we find
                // destination.
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}
 

void printShortestDistance(vector<int> adj[], int s,
                           int dest, int v)
{

    int pred[v], dist[v];
 
    if (BFS(adj, s, dest, v, pred, dist) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    cout << "Following is Breadth First Traversal (starting from vertex V4) Destination to V1";

    cout << "\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << "\n";
}
 

int main()
{

    int total = 5;
 
    vector<int> adj[total];

    add_edge(adj, 4,2);
    add_edge(adj, 4, 3);
    add_edge(adj, 2, 1);
    add_edge(adj, 2, 3);
    add_edge(adj, 1, 3);
    add_edge(adj, 0, 1);
    int source = 4, dest=1;
    printShortestDistance(adj, source, dest, total);
    return 0;
}

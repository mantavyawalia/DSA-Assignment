#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

class Graph {
    int V; // number of vertices
    // adjacency list: adj[u] = { {v, weight}, ... }
    vector< vector< pair<int,int> > > adj;

    // edge list for Kruskal: {weight, {u, v}}
    vector< pair<int, pair<int,int> > > edges;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        // Undirected weighted graph
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({w, {u, v}});
    }

    // ========= 1. Breadth First Search (BFS) =========
    void BFS(int src) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[src] = true;
        q.push(src);

        cout << "BFS starting from vertex " << src << ": ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (auto &p : adj[u]) {
                int v = p.first;
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << "\n";
    }

    // ========= 2. Depth First Search (DFS) =========
    void DFSUtil(int u, vector<bool> &visited) {
        visited[u] = true;
        cout << u << " ";

        for (auto &p : adj[u]) {
            int v = p.first;
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

    void DFS(int src) {
        vector<bool> visited(V, false);
        cout << "DFS starting from vertex " << src << ": ";
        DFSUtil(src, visited);
        cout << "\n";
    }

    // ========= Helper functions for Kruskal =========
    int findParent(int node, vector<int> &parent) {
        if (parent[node] == node)
            return node;
        parent[node] = findParent(parent[node], parent); // path compression
        return parent[node];
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rankArr) {
        u = findParent(u, parent);
        v = findParent(v, parent);
        if (u == v) return;

        if (rankArr[u] < rankArr[v]) {
            parent[u] = v;
        } else if (rankArr[v] < rankArr[u]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rankArr[u]++;
        }
    }

    // ========= 3A. Minimum Spanning Tree - Kruskal =========
    void KruskalMST() {
        // sort edges by weight
        sort(edges.begin(), edges.end());

        vector<int> parent(V), rankArr(V, 0);
        for (int i = 0; i < V; i++)
            parent[i] = i;

        int mstWeight = 0;
        vector< pair<int, pair<int,int> > > mstEdges;

        for (auto &e : edges) {
            int w = e.first;
            int u = e.second.first;
            int v = e.second.second;

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu != pv) {
                mstWeight += w;
                mstEdges.push_back(e);
                unionSet(pu, pv, parent, rankArr);
            }
        }

        cout << "Kruskal's MST edges (u - v : w):\n";
        for (auto &e : mstEdges) {
            cout << e.second.first << " - " << e.second.second
                 << " : " << e.first << "\n";
        }
        cout << "Total weight of MST (Kruskal) = " << mstWeight << "\n\n";
    }

    // ========= 3B. Minimum Spanning Tree - Prim =========
    void PrimMST(int start) {
        vector<int> key(V, INT_MAX);   // min weight to connect
        vector<int> parent(V, -1);     // store MST
        vector<bool> inMST(V, false);  // added to MST or not

        // Min-heap: {key, vertex}
        priority_queue< pair<int,int>, 
                        vector<pair<int,int>>, 
                        greater<pair<int,int>> > pq;

        key[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (!inMST[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        cout << "Prim's MST edges (u - v : w):\n";
        int mstWeight = 0;
        for (int v = 0; v < V; v++) {
            if (parent[v] != -1) {
                cout << parent[v] << " - " << v << " : " << key[v] << "\n";
                mstWeight += key[v];
            }
        }
        cout << "Total weight of MST (Prim) = " << mstWeight << "\n\n";
    }

    // ========= 4. Dijkstra's Shortest Path =========
    void Dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Min-heap: {distance, vertex}
        priority_queue< pair<int,int>, 
                        vector<pair<int,int>>, 
                        greater<pair<int,int>> > pq;

        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue; // skip old entry

            for (auto &p : adj[u]) {
                int v = p.first;
                int w = p.second;

                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra's shortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";
            if (dist[i] == INT_MAX)
                cout << "INF\n";
            else
                cout << dist[i] << "\n";
        }
        cout << "\n";
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges as: u v w  (0-based vertices)\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. Kruskal's MST\n";
        cout << "4. Prim's MST\n";
        cout << "5. Dijkstra's Shortest Path\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int src;
            cout << "Enter source vertex for BFS: ";
            cin >> src;
            g.BFS(src);
        } else if (choice == 2) {
            int src;
            cout << "Enter source vertex for DFS: ";
            cin >> src;
            g.DFS(src);
        } else if (choice == 3) {
            g.KruskalMST();
        } else if (choice == 4) {
            int start;
            cout << "Enter starting vertex for Prim's MST: ";
            cin >> start;
            g.PrimMST(start);
        } else if (choice == 5) {
            int src;
            cout << "Enter source vertex for Dijkstra: ";
            cin >> src;
            g.Dijkstra(src);
        }
    } while (choice != 0);

    return 0;
}

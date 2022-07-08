#include <iostream>
#include <iomanip>
#include <queue>
#include <list>
using namespace std;

typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> MinHeap;

struct Graph {
    vector<list<pii>> adj;
    Graph(int V) : adj(V) {}
    void addEdge(int u, int v, int w) {
        adj[u].push_back({w, v});
    }
};

void DijkstraSPT(const Graph& g, int V, int src) {
    
    vector<bool> vis(V);
    vector<char> res(V);
    vector<int> dist(V, INT_MAX);
    res[src] = '-';
    dist[src] = 0;
    
    MinHeap h;
    
    h.push({0, src});
    
    while (h.size()) {
        
        int u = h.top().second;
        h.pop();
        
        vis[u] = true;
        
        for (auto &e : g.adj[u]) {
            int w = e.first;
            int v = e.second;
            if (!vis[v] && w + dist[u] < dist[v]) {
                dist[v] = w + dist[u];
                res[v] = u + 'A';
                h.push({dist[v], v});
            }
        }
    }
    
    cout << "\n ";
    for (char i = 'A'; i <= 'E'; i++) {
        cout << setw(4) << i;
    }
    cout << "\nD";
    for (int i = 0; i < V; i++) {
        cout << setw(4) << dist[i];
    }
    cout << "\nP";
    for (int i = 0; i < V; i++) {
        cout << setw(4) << res[i];
    }
    cout << "\n";
}

int main() {
	vector<vector<int>> edges {
	    {0, 1, 10},
        {0, 2, 3},
        {1, 3, 2},
        {1, 2, 1},
        {2, 1, 4},
        {2, 3, 8},
        {2, 4, 2},
        {3, 4, 7},
        {4, 3, 9}
	};
	int V = 5;
	Graph g(V);
	for (auto &e : edges) {
	    g.addEdge(e[0], e[1], e[2]);
	}
	DijkstraSPT(g, V, 0);
	return 0;
}
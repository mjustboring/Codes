#include <iostream>
#include <iomanip>
#include <queue>
#include <list>
using namespace std;

struct Edge {
    int u, v, w;
    friend bool operator< (const Edge& a, const Edge& b) {
        return a.w < b.w;
    }
    friend bool operator> (const Edge& a, const Edge& b) {
        return a.w > b.w;
    }
};

bool operator< (const Edge&, const Edge&);
bool operator> (const Edge&, const Edge&);

struct Graph {
    vector<list<Edge>> adj;
    Graph(int V) : adj(V) {}
    void addEdge(int u, int v, int w) {
        adj[u].push_back({u, v, w});
    }
};

typedef priority_queue<Edge, vector<Edge>, greater<Edge>> MinHeap;

void PrimsMST(const Graph& g, int V) {
    
    vector<bool> vis(V);
    vector<char> res(V);
    vector<int> dist(V);
    
    MinHeap h;
    h.push({'-' - 'A', 0, 0});
    
    while (h.size()) {
        
        int u = h.top().u;
        int v = h.top().v;
        int w = h.top().w;
        h.pop();
        
        if (!vis[v]) {
            dist[v] = w;
            res[v] = u + 'A';
            vis[v] = true;
            for (auto &e : g.adj[v]) {
                if (!vis[e.v]) h.push(e);
            }
        }
    }
    
    int cost = 0;
    
    cout << "\n ";
    for (char i = 'A'; i <= 'E'; i++) {
        cout << setw(4) << i;
    }
    cout << "\nD";
    for (int i = 0; i < V; i++) {
        cout << setw(4) << dist[i];
        cost += dist[i];
    }
    cout << "\nP";
    for (int i = 0; i < V; i++) {
        cout << setw(4) << res[i];
    }
    cout << "\n\nTotal Cost = " << cost << "\n";
}

int main() {
	int V = 9;
	vector<vector<int>> edges {
	    {7, 6, 1}, {8, 2, 2}, {6, 5, 2}, {0, 1, 4},
	    {2, 5, 4}, {8, 6, 6}, {2, 3, 7}, {7, 8, 7},
	    {0, 7, 8}, {1, 2, 8}, {3, 4, 9}, {5, 4, 10},
	    {1, 7, 11}, {3, 5, 14}
	};
	Graph g(V);
	for (auto &e : edges) {
	    g.addEdge(e[0], e[1], e[2]);
	    g.addEdge(e[1], e[0], e[2]);
	}
	PrimsMST(g, V);
	return 0;
}
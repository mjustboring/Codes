#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

typedef list<int> li;
typedef vector<li> vli;

vli adj;
int V;

/*

0---1---2
|\  |   |
| | |   |
3 \ 4---5
 \ ||  /
  \\| /
    6

*/

void addEdge(int src, int dest, bool dir = false) {
    adj[src].push_back(dest);
    if (!dir) {
        adj[dest].push_back(src);
    }
}

void makeGraph() {
    adj = vli(V = 7);
    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(0, 6);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(3, 6);
    addEdge(4, 5);
    addEdge(4, 6);
    addEdge(5, 6);
}

void bfs(vector<bool>& vis, queue<int>& q, int src) {
    
    vis[src] = true;
    q.push(src);
    
    while (q.size()) {
        
        int src = q.front();
        q.pop();
        
        cout << src << " ";
        
        for (auto u : adj[src]) {
            if (!vis[u]) {
                q.push(u);
                vis[u] = true;
            }
        }
    }
}

void bfs(int src = 0) {
    vector<bool> vis(V);
    queue<int> q;
    bfs(vis, q, src);
    for (auto u = 0; u < V; u++) {
        if (!vis[u]) {
            bfs(vis, q, u);
        }
    }
}

int main() {
	
	makeGraph();
	
	bfs(0);
	
	return 0;
}
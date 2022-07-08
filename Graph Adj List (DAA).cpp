#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef list<int> li;
typedef vector<li> vli;

vli adj;
int V;

void print() {
    
    for (int u = 0; u < V; u++) {
        cout << u << " -> ";
        for (auto c : adj[u]) {
            cout << c << ", ";
        }
        cout << "\n";
    }
}

void addEdge(int src, int dest, bool dir = false) {
    adj[src].push_back(dest);
    if (!dir) {
        adj[dest].push_back(src);
    }
}

int main() {
	
	cout << "Enter the no. of Vertex : ";
	cin >> V;
	
	adj = vli(V);
	
	cout << "Enter no. of Edge : ";
	int edge;
	cin >> edge;
	
	cout << "Enter [src dest] :-\n\n";
	
	for (int i = 0; i < edge; i++) {
	    int src, dest;
	    cin >> src >> dest;
	    addEdge(src, dest);
	}
	
	print();
	
	return 0;
}
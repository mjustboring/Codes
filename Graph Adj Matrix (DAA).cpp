#include <iostream>
#include <climits>
#include <iomanip>
#include <vector>
using namespace std;

#define INF INT_MAX

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;
int V;

void print() {
    
    for (auto &r : adj) {
        for (auto c : r) {
            if (c == INF) {
                cout << setw(4) << "INF";
            } else {
                cout << setw(4) << c;
            }
        }
        cout << "\n";
    }
}

void addEdge(int src, int dest, int w = 1, bool dir = false) {
    adj[src][dest] = w;
    if (!dir) {
        adj[dest][src] = w;
    }
}

int main() {
	
	cout << "Enter the no. of Vertex : ";
	cin >> V;
	
	adj = vvi(V, vi(V, INF));
	
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
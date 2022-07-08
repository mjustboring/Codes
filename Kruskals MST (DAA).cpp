#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DS {
    
    vector<int> root;
    DS(int V) : root(V,-1) {}
    
    void Union(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (root[rx] > root[ry]) {
            swap(rx, ry);
        }
        root[rx] += root[ry];
        root[ry] = rx;
    }
    int Find(int x) {
        if (root[x] < 0) {
            return x;
        }
        return root[x] = Find(root[x]);
    }
};

struct Edge {
    int u, v, w;
};

vector<Edge> KruskalMST(vector<Edge>& edges, const int V) {
    
    sort(
        edges.begin(), edges.end(),
        [](const Edge& a, const Edge& b) -> bool {
            return a.w <= b.w;
        }
    );
    
    DS ds(V);
    
    vector<Edge> res;
    
    for (const auto &e : edges) {
        int x = ds.Find(e.u);
        int y = ds.Find(e.v);
        if (x != y) {
            ds.Union(x, y);
            res.push_back(e);
        }
    }
    
    return res;
}

void printResult(const vector<Edge>& res) {
    
    int cost = 0;
    
    for (auto &e : res) {
        cout << e.u << " -> " << e.v << " : " << e.w << "\n";
        cost += e.w;
    }
    cout << "\nTotal Cost : " << cost << "\n";
}

int main() {
	int V = 9;
	vector<Edge> edges {
	    {7, 6, 1}, {8, 2, 2}, {6, 5, 2}, {0, 1, 4},
	    {2, 5, 4}, {8, 6, 6}, {2, 3, 7}, {7, 8, 7},
	    {0, 7, 8}, {1, 2, 8}, {3, 4, 9}, {5, 4, 10},
	    {1, 7, 11}, {3, 5, 14}
	};
	printResult(KruskalMST(edges, V));
	return 0;
}
#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

struct Graph {
	
	int n;
	vector<vector<int>> adj;
	map<pair<int, int>, int> city;
	
	vector<int> mx;
	vector<int> ans;
	
	Graph(int n, const vector<vector<int>> &edges) : n(n), adj(n) {
		for (auto &e : edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		dfs();
	}
	
	int dfs1(int u, int d, int p = -1) {
		
		int m = d;
		
		for (auto v : adj[u]) {
		    
			if (v != p) {
			    
			    city[{u, v}] = city[{v, u}] = v;
			    
				int t = dfs1(v, d+1, u);
				
				m = max(m, t);
			}
		}
		
		return mx[u] = m;
	}
	
	void dfs2(int u, int m, int d, int p = -1) {
	    
	    ans[u] = m;
	    
	    int x = m, xv = -1;
	    int y = m, yv = -1;
	    
	    for (auto v : adj[u]) {
		    
			if (v != p) {
				if (mx[v] > x) {
				    y = x;
				    yv = xv;
				    x = mx[v];
				    xv = v;
				} else if (mx[v] > y) {
				    y = mx[v];
				    yv = v;
				}
			}
		}
		
		for (auto v : adj[u]) {
		    
			if (v != p) {
			    
			    if (v != xv) {
			        dfs2(v, max(x, d), d+1, u);
			    } else {
			        dfs2(v, max(y, d), d+1, u);
			    }
			}
		}
	}
	
	int dfs() {
		ans = mx = vector<int>(n);
		dfs1(0, 0);
		dfs2(0, 0, 0);
	}
	
	int get(const vector<int> &v) {
		return ans[city[{v[0], v[1]}]];
	}
};

struct Solution {

    vector<int> solve(int n, int m, vector<vector<int>> &e, vector<vector<int>> &q) {
        
        Graph g(n, e);
        
        vector<int> ans;
        
        for (auto x : q) {
            ans.push_back(g.get(x));
        }
        
        return ans;
    }
};

void solve() {
	
	int n[] = {5, 3, 8};
	int q[] = {2, 1, 4};
	vector<vector<int>> edge[] = {
	   {{0, 1},
        {0, 2},
        {1, 3},
        {1, 4}},
       {{0, 1}, 
        {0, 2}},
       {{2, 3},
		{3, 5},
		{4, 6},
		{2, 6},
		{4, 7},
		{0, 7},
		{1, 7}}
	};
	vector<vector<int>> query[] = {
	   {{0, 1},
        {1, 4}},
       {{0, 1}},
       {{1, 7},
		{0, 7},
		{0, 7},
		{3, 5}}
	};
	
	for (int i = 0; i < 3; ++i) {
		cout << "Case " << i+1 << ": " << Solution().solve(n[i], q[i], edge[i], query[i]) << "\n";
	}
}

/*
Case 1: 1 2

        0
       / \
      1   2
     / \
    3   4

Case 2: 1

	  0
	 / \
	1   2

Case 3: 6 0 0 5

	  0
	  |
	  7
	 / \
	1   4
	    |
	    6
	    |
	    2
	    |
        3
	    |
	    5
*/

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
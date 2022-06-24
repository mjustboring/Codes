#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

;int dp[50][50][50];

struct Solution {
    
    int n;
    vector<vector<int>> a;
    
// -----------------------------------------------

    int goto0(int i, int j) {
        
        if (i < 0 || j < 0 || a[i][j] == -1) {
            return -1;
        }
        
        if (i == 0 && j == 0) {
            return a[i][j];
        }
        
        bool cherry = a[i][j];
        a[i][j] = 0;
        
        int x = goto0(i-1, j);
        int y = goto0(i, j-1);
        
        a[i][j] = cherry;
        
        return cherry + max(x, y);
    }
    
    int gotoN(int i, int j) {
        
        if (i > n || j > n || a[i][j] == -1) {
            return -1;
        }
        
        if (i == n && j == n) {
            bool cherry = a[i][j];
            a[i][j] = 0;
            int ans = goto0(n, n);
            a[i][j] = cherry;
            return cherry + ans;
        }
        
        bool cherry = a[i][j];
        a[i][j] = 0;
        
        int x = gotoN(i+1, j);
        int y = gotoN(i, j+1);
        
        a[i][j] = cherry;
        
        x = max(x, y);
        
        if (x == -1) return -1;
        
        return cherry + x;
    }

// -----------------------------------------------

    int go2bt(int u, int v, int x, int y) {
        
        if (u > n || v > n || x > n || y > n || a[u][v] == -1 || a[x][y] == -1) {
            return -1e9;
        }
        
        if ((u == n && v == n) || (x == n && y == n)) {
            return a[n][n];
        }
        
        int ans = -1e9;
        
        bool c1 = a[u][v];
        bool c2 = a[x][y];
        
        a[u][v] = a[x][y] = 0;
        
        ans = max(ans, go2bt(u+1, v, x, y));
        ans = max(ans, go2bt(u, v+1, x, y));
        ans = max(ans, go2bt(u, v, x+1, y));
        ans = max(ans, go2bt(u, v, x, y+1));
        
        a[u][v] = c1;
        a[x][y] = c2;
        
        if (u != x || v != y) {
            ans += a[u][v];
        }
        ans += a[x][y];
        
        return ans;
    }
    
// -----------------------------------------------
/*
    int go2(int u, int v, int x, int y) {
        
        if (u > n || v > n || x > n || y > n || a[u][v] == -1 || a[x][y] == -1) {
            return -1e9;
        }
        
        if (dp[u][v][x][y] != -1) return dp[u][v][x][y];
        
        if ((u == n && v == n) || (x == n && y == n)) {
            return a[n][n];
        }
        
        int ans = -1e9;
        
        ans = max(ans, go2(u+1, v, x+1, y));
        ans = max(ans, go2(u+1, v, x, y+1));
        ans = max(ans, go2(u, v+1, x+1, y));
        ans = max(ans, go2(u, v+1, x, y+1));
        
        if (u != x || v != y) {
            ans += a[u][v];
        }
        ans += a[x][y];
        
        return dp[u][v][x][y] = ans;
    }
*/
// -----------------------------------------------

    int go2(int u, int v, int x) {
        
        int y = u + v - x;
        
        if (u > n || v > n || x > n || y > n || a[u][v] == -1 || a[x][y] == -1) {
            return -1e9;
        }
        
        if (dp[u][v][x] != -1) return dp[u][v][x];
        
        if ((u == n && v == n) || (x == n && y == n)) {
            return a[n][n];
        }
        
        int ans = -1e9;
        
        ans = max(ans, go2(u+1, v, x+1));
        ans = max(ans, go2(u+1, v, x));
        ans = max(ans, go2(u, v+1, x+1));
        ans = max(ans, go2(u, v+1, x));
        
        if (u != x || v != y) {
            ans += a[u][v];
        }
        ans += a[x][y];
        
        return dp[u][v][x] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        
        a = move(grid);
        n = a.size()-1;
        
        memset(dp, -1, sizeof dp);
        
        int ans = go2(0, 0, 0);
        
        grid = move(a);
        
        return ans < 0 ? 0 : ans;
    }
};

void solve() {
    
    vector<vector<int>> a {
        {1,1,1,0,0},
        {0,0,1,0,1},
        {1,0,1,0,0},
        {0,0,1,0,0},
        {0,0,1,1,1},
    };
    
    cout << "\n" << Solution().cherryPickup(a);
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
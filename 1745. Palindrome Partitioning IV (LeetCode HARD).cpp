#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

struct Solution {

    bool checkPartitioning(string &s) {
        
        const int n = s.size();
        
        bool p[n][n];
        
        for (int i = 0; i < n; ++i) {
            p[i][i] = 1;
            if (i-1 >= 0) {
                p[i-1][i] = (s[i-1] == s[i]);
                for (int j = i-2; j >= 0; --j) {
                    p[j][i] = (s[j] == s[i]) && p[j+1][i-1];
                }
            }
        }
        
        for (int i = 0; i < n-2; ++i) {
            if (p[0][i]) {
                for (int j = i+2; j < n; ++j) {
                    if (p[j][n-1] && p[i+1][j-1]) {
                        return 1;
                    }
                }
            }
        }
        
        return 0;
    }
};

void solve() {
    
    string s = "abcbdd";
    
    cout << Solution().checkPartitioning(s);
    
    cout << '\n';
}


int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
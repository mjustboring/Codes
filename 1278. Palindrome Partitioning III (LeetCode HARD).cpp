#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

int p[100][100];
int dp[100][100];

struct Solution {
    
    int n;
    
    int fun(int i, int k) {
        
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        
        if (k == 0) {
            return p[i][n-1];
        }
        
        int ans = n;
        
        for (int j = i; j+k < n; ++j) {
            ans = min(ans, p[i][j] + fun(j+1, k-1));
        }
        
        return dp[i][k] = ans;
    }
    
    int palindromePartition(string &s, int k) {
        
        n = s.size();
        
        for (int i = 0; i < n; ++i) {
            p[i][i] = 0;
            if (i-1 >= 0) {
                p[i-1][i] = (s[i-1] != s[i]);
                for (int j = i-2; j >= 0; --j) {
                    p[j][i] = (s[j] != s[i]) + p[j+1][i-1];
                }
            }
        }
        
        memset(dp, -1, sizeof dp);
        
        return fun(0, k-1);
    }
};

void solve() {
    
    string s = "abaabcdaxyz";
    int k = 3;
    
    cout << s << endl << endl;
    
    cout << "Expected : 2\n";
    cout << "Answer : " << Solution().palindromePartition(s, k);
    
    cout << '\n';
}


int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
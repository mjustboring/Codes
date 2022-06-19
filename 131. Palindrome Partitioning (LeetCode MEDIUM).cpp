#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

bool p[16][16];

struct Solution {
    
    int n;
    string s;
    vector<string> v;
    vector<vector<string>> ans;
    
    void fun(int i) {
        
        if (i == n) {
            ans.push_back(v);
            return;
        }
        
        for (int j = i; j < n; ++j) {
            
            if (p[i][j]) {
                v.push_back(s.substr(i, j-i+1));
                fun(j+1);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string str) {
        
        n = str.size();
        this->s = move(str);
        
        for (int i = 0; i < n; ++i) {
            p[i][i] = 1;
            if (i-1 >= 0) {
                p[i-1][i] = (s[i-1] == s[i]);
                for (int j = i-2; j >= 0; --j) {
                    p[j][i] = (s[j] == s[i]) && p[j+1][i-1];
                }
            }
        }
        
        fun(0);
        
        return ans;
    }
};

void solve() {
    
    string s = "abcbaxyzyzyxmcm";
    
    for (auto &y : Solution().partition(s)) {
        for (auto &x : y) {
            cout << x << " ";
        }
        cout << '\n';
    }
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
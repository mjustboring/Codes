#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

struct Solution1 {

    vector<vector<int>> reconstructQueue(vector<vector<int>>& a) {
        
        int n = a.size();
        sort(a.begin(), a.end());
        
        while (1) {
            
            int i = n, c;
            
            for (int j = 0; j < n; ++j) {
                c = 0;
                for (int k = 0; k < j; ++k) {
                    if (a[k][0] >= a[j][0]) {
                        c += 1;
                    }
                }
                if (c < a[j][1]) {
                    i = j;
                    break;
                }
            }
            
            if (i == n) {
                break;
            }
            
            while (c < a[i][1]) {
                c += a[i+1][0] >= a[i][0];
                swap(a[i], a[i+1]);
                i += 1;
            }
        }
        
        return a;
    }
};

struct Solution {

    vector<vector<int>> reconstructQueue(vector<vector<int>>& a) {
        
        sort(a.begin(), a.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        
        int n = a.size();
        
        for (int i = 1; i < n; ++i) {
            int j = i;
            while (j > 0 && j > a[j][1]) {
                swap(a[j], a[j-1]);
                --j;
            }
        }
        
        return a;
    }
};

void solve() {
    
    // vector<vector<int>> a {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> a {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
    
    auto ans = Solution().reconstructQueue(a);
    
    for (auto &x : ans) {
        printf("(%d,%d) ", x[0], x[1]);
    }
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
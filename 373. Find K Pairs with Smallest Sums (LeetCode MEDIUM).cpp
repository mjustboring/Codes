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

    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        
        vector<vector<int>> ans;
        
        if(a.empty() || b.empty()) return ans;
        
        auto cmp = [&a, &b] (
            const pair<int, int>& x,
            const pair<int, int>& y
        ) {
            return a[x.first] + b[x.second] > a[y.first] + b[y.second]; 
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> h(cmp);
        h.emplace(0, 0);
        
        while (h.size() && k--) {
            
            auto [i, j] = h.top(); h.pop();
            
            ans.push_back({a[i], b[j]});
            
            if(i + 1 < a.size())
                h.emplace(i + 1, j);
            
            if(i == 0 && j + 1 < b.size())
                h.emplace(i, j + 1);
        }
        
        return ans;
    }
};

void solve() {
    
    vector<int> a {1,4,6,12,14};
    vector<int> b {1,2,8,10,16};
    
    int k = 10;
    
    auto ans = Solution().kSmallestPairs(a,b,k);
    
    for (auto &x : ans) {
        printf("[%d,%d], ", x[0], x[1]);
    }
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
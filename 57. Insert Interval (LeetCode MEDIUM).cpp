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
    
    int getLeftBound(vector<vector<int>> &its, int it) {
        
        int i = 0, j = its.size()-1;
        
        if (its[j].back() < it) return j+1;
        
        int ans = -1;
        
        while (i <= j) {
            int m = (i+j) >> 1;
            if (its[m].back() < it) {
                i = m+1;
            } else {
                j = m-1;
                ans = m;
            }
        }
        
        return ans;
    }
    
    int getRightBound(vector<vector<int>> &its, int it) {
        
        int i = 0, j = its.size()-1;
        
        if (its[i].front() > it) return -1;
        
        int ans = -1;
        
        while (i <= j) {
            int m = (i+j) >> 1;
            if (its[m].front() > it) {
                j = m-1;
            } else {
                i = m+1;
                ans = m;
            }
        }
        
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& its, vector<int>& it) {
        
        const int n = its.size();
        
        if (n == 0) return { it };
        
        int l = getLeftBound(its, it[0]);
        int r = getRightBound(its, it[1]);
        
        if (l >= n) {
            its.push_back(it);
            return its;
        }
        
        if (r < 0) {
            reverse(its.begin(), its.end());
            its.push_back(it);
            reverse(its.begin(), its.end());
            return its;
        }
        
        vector<vector<int>> ans;
        
        it[0] = min(its[l][0], it[0]);
        it[1] = max(its[r][1], it[1]);
        
        for (int i = 0; i < l; ++i) {
            ans.push_back(its[i]);
        }
        ans.push_back(it);
        for (int i = r+1; i < n; ++i) {
            ans.push_back(its[i]);
        }
        
        return ans;
    }
};

void solve() {
    
    vector<vector<vector<int>>> given {
        {{1,3},{6,9}},
        {{1,2},{3,5},{6,7},{8,10},{12,16}},
        {},
        {{1,2}},
        {{2,3}},
        {{1,4}},
        {{1,2},{2,3}},
        {{1,2},{5,6}}
    };
    
    vector<vector<int>> query {
        {2,5}, {4,8}, {2,3}, {2,3}, {2,3}, {2,3}, {2,3}, {3,4}
    };
    
    for (int k = 0; k < given.size(); ++k) {
        
        auto &x = given[k];
        
        cout << "G -> [";
        for (int i = 0; i < x.size(); ++i) {
            
            cout << "[" << x[i][0] << "," << x[i][1] << "]";
                 
            if (i+1 != x.size()) {
                cout << ",";
            }
        }
        cout << "]\n";
        
        cout << "Q -> [" << query[k][0] << "," << query[k][1] << "]\n";
        
        auto ans = Solution().insert(x, query[k]);
        
        cout << "A -> [";
        for (int i = 0; i < ans.size(); ++i) {
            
            cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
            
            if (i+1 != ans.size()) {
                cout << ",";
            }
        }
        cout << "]\n\n";
    }
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
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

    int maxProduct(vector<int> &a) {
        
        int pmn, mn, pmx, mx, ans;
        pmn = mn = pmx = mx = ans = a.back();
        
        for (int i = a.size()-2; i >= 0; --i) {
            mn = min(pmn * a[i], min(pmx * a[i], a[i]));
            mx = max(pmn * a[i], max(pmx * a[i], a[i]));
            ans = max(ans, mx);
            pmn = mn;
            pmx = mx;
        }
        
        return ans;
    }
};

struct Solution2 {

    int maxProduct(vector<int> &a) {
        
        int i, j = a.size()-1;
        int pfx, sfx, ans = a[0];
        i = pfx = sfx = 0;
        
        for (; j >= 0; ++i, --j) {
            pfx = (pfx ? pfx : 1) * a[i];
            sfx = (sfx ? sfx : 1) * a[j];
            ans = max(ans, max(pfx, sfx));
        }
        
        return ans;
    }
};

void solve() {
    
    srand(time(0));
    
    for (int m = 10; m; --m) {
        int n = 5 + rand() % 6;
        vector<int> a(n);
        cout << "[";
        for (int i = 0; i < n; ++i) {
            a[i] = (rand() & 1) ? -(rand()%4) : (rand()%4);
            cout << a[i];
            if (i+1 != n) cout << ",";
        }
        cout << "]" << endl;
        cout << "1 -> " << Solution1().maxProduct(a) << endl;
        cout << "2 -> " << Solution2().maxProduct(a) << endl << endl;
    }
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
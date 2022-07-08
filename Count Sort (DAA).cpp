#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int>& arr) {
    
    int mn = INT_MAX;
    int mx = INT_MIN;
    
    for (auto x : arr) {
        mn = min(mn, x);
        mx = max(mx, x);
    }
    mn = abs(mn);
    
    vector<int> c(mx + mn + 1);
    
    for (auto x : arr) c[x + mn]++;
    for (int i = 1; i < c.size(); i++) {
        c[i] += c[i-1];
    }

    vector<int> ans(arr.size());
    
    for (int i = (int) arr.size()-1; i >= 0; i--) {
        ans[--c[arr[i] + mn]] = arr[i];
    }
    
    arr = move(ans);
}

int main() {
	
	vector<int> arr {
	    -1, -2, -3, -2, -10, 6, 5, 8, 3, 5, 2, 6, 4, 5
	};
	countSort(arr);
	
	for (auto x : arr) cout << x << " ";
	return 0;
}

// -10 -3 -2 -2 -1 2 3 4 5 5 5 6 6 8
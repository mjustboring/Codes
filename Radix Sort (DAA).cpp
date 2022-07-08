#include <iostream>
#include <vector>
using namespace std;

void radixSort(vector<int>& arr) {
    
    int mx = 0;
    for (auto x : arr) mx = max(mx, x);
    
    for (int e = 0; mx >> e; e += 4) {
        
        vector<int> c(16);
        for (auto x : arr) c[(x >> e) & 15]++;
        
        for (int i = 1; i <= 15; i++) {
            c[i] += c[i-1];
        }
        
        vector<int> ans(arr.size());
        
        for (int i = (int) arr.size()-1; i >= 0; i--) {
            ans[--c[(arr[i] >> e) & 15]] = arr[i];
        }
        
        arr = move(ans);
    }
}

int main() {
	
	vector<int> arr {
	    38961, 63351, 9881, 57937, 1773, 65371, 61140
	};
	radixSort(arr);
	
	for (auto x : arr) cout << x << " ";
	return 0;
}

// 1773 9881 38961 57937 61140 63351 65371
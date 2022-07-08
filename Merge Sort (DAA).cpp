#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    
    vector<int> t; t.reserve(r-l+1);
    
    int i = l, j = m+1;
    
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) t.emplace_back(arr[i++]);
        else t.emplace_back(arr[j++]);
    }
    while (i <= m) t.emplace_back(arr[i++]);
    while (j <= r) t.emplace_back(arr[j++]);
    
    for (auto x : t) arr[l++] = x;
}

void mergeSort(vector<int>& arr, int l, int r) {
    
    if (l >= r) return;
    
    int m = l + ((r-l) >> 1);
    
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    
    merge(arr, l, m, r);
}

void mergeSort(vector<int>& arr) {
    
    mergeSort(arr, 0, (int) arr.size()-1);
}

int main() {
	
	vector<int> arr {8, 1, 6, 3, 4, 5, 9, 7, 2, 4, 6};
	
	mergeSort(arr);
	
	for (auto x : arr)
	    cout << x << " ";

	return 0;
}

// Output : 1 2 3 4 4 5 6 6 7 8 9
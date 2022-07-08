#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int l, int r) {
    
    int i = l, j = r, p = arr[l];
    
    while (i < j) {
        while (i <= j && arr[i] <= p) i++;
        while (i <= j && arr[j] > p) j--;
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    
    for (int i = l; i < j; i++) cout << arr[i] << " ";
    cout << "  " << arr[j] << "   ";
    for (int i = j+1; i <= r; i++) cout << arr[i] << " ";
    cout << "\n\n";
    return j;
}

void quickSort(vector<int>& arr, int l, int r) {
    
    if (l >= r) return;
    
    int p = partition(arr, l, r);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}

void quickSort(vector<int>& arr) {
    
    quickSort(arr, 0, (int) arr.size()-1);
}

int main() {
	
	vector<int> arr {57,63,29,74,64,20,10,15,7};
	
	for (auto x : arr)
	    cout << x << " ";
	
	cout << "\n\n";
	
	quickSort(arr);
	
	for (auto x : arr)
	    cout << x << " ";

	return 0;
}

// Output : 1 2 3 4 4 5 6 6 7 8 9

/*

partition(arr, l, r):
    
    i = l
    j = r
    p = arr[l];
    
    while i < j: do

        while i <= j and arr[i] <= p: do i += 1
        while i <= j and arr[j] > p: do j -= 1
        if i < j: do swap(arr[i], arr[j])

    swap(arr[l], arr[j]);
    return j;


quickSort(arr, l, r):
    
    if (l < r): do
        p = partition(arr, l, r)
        quickSort(arr, l, p-1)
        quickSort(arr, p+1, r)



*/
#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    
    for (int i = 1; i < arr.size(); i++) {
        
        int key = arr[i];
        int j = i-1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
}

int main() {
	
	vector<int> arr {1, 5, 3, 2, 4};
	
	insertionSort(arr);
	
	for (auto x : arr)
	    cout << x << " ";

	return 0;
}

// Output : 1 2 3 4 5
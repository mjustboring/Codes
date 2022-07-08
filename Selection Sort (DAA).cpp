#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    
    for (int i = 0; i+1 < arr.size(); i++) {
        
        int mi = i;
        for (int j = i+1; j < arr.size(); j++) {
            if (arr[j] < arr[mi]) {
                mi = j;
            }
        }
        swap(arr[i], arr[mi]);
    }
}

int main() {
	
	vector<int> arr {1, 5, 3, 2, 4};
	
	selectionSort(arr);
	
	for (auto x : arr)
	    cout << x << " ";

	return 0;
}

// Output : 1 2 3 4 5
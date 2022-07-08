#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
    
    for (int i = 0; i+1 < arr.size(); i++) {
        bool swapped = false;
        for (int j = 0; j+i+1 < arr.size(); j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) return;
    }
}

int main() {
	
	vector<int> arr {1, 5, 3, 2, 4};
	
	bubbleSort(arr);
	
	for (auto x : arr)
	    cout << x << " ";

	return 0;
}

// Output : 1 2 3 4 5
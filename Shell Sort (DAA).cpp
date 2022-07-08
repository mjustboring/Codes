#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr) {
    
    for (int g = arr.size() >> 1; g > 0; g >>= 1) {
        
        for (int i = g; i < arr.size(); i++) {
            
            int key = arr[i];
            int j = i-g;
            
            while (j >= 0 && arr[j] > key) {
                arr[j+g] = arr[j];
                j -= g;
            }
            
            arr[j+g] = key;
        }
    }
}

int main() {
	
	vector<int> arr {8, 1, 6, 3, 4, 5, 9, 7, 2, 4, 6};

	shellSort(arr);
	
	for (auto x : arr)
	    cout << x << " ";

	return 0;
}

// Output : 1 2 3 4 4 5 6 6 7 8 9
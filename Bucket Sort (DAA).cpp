#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(vector<float>& arr) {
	
	vector<float> b[10];
	
	for (auto x : arr)
	    b[(int)(x * 10)].push_back(x);

	for (int i = 0; i < 10; i++)
		sort(b[i].begin(), b[i].end());

	for (int i = 0, k = 0; i < 10; i++)
	    for (auto x : b[i]) arr[k++] = x;
}

int main() {
	
	vector<float> arr {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
	bucketSort(arr);
	
	for (auto x : arr) cout << x << " ";
	
	return 0;
}

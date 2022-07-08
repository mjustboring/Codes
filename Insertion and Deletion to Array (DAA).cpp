#include <iostream>
using namespace std;

int* arr = 0;
int size = 0;

void ins(int idx, int val) {
    if (idx > size) return;
    arr = (int*) realloc(arr, (size + 1) * sizeof(int));
    if (idx == size) arr[size] = val;
    else {
        for (int i = size; i > idx; i--) {
            arr[i] = arr[i-1];
        }
        arr[idx] = val;
    }
    ++size;
}

void del(int idx) {
    if (idx >= size) return;
    else {
        for (int i = idx; i < size; i++) {
            arr[i] = arr[i+1];
        }
        arr = (int*)realloc(arr, --size * sizeof(int));
    }
}

void print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
	
	ins(0, 5);
	print();
	ins(1, 3);
	print();
	del(0);
	print();
	
	return 0;
}
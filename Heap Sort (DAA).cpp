#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    
    vector<int> h;
    
    int lof(int i) const {
        return (i << 1) + 1;
    }
    
    int rof(int i) const {
        return (i << 1) + 2;
    }
    
    int pof(int i) const {
        return ((i-1) >> 1);
    }
    
    int midx(int i, int j) const {
        if (i >= h.size()) return j;
        if (j >= h.size()) return i;
        if (h[i] < h[j]) return i;
        return j;
    }
    
    int midx(int i, int j, int k) const {
        return midx(i, midx(j, k));
    }
    
public:

    MinHeap() {}
    MinHeap(const vector<int>& v)
    : h (v) {
        for (int i = (int) h.size()-1; i >= 0; i--) {
            heapify(i);
        }
    }
    
    int size() const {
        return h.size();
    }
        
    void push(int key) {
        
        h.push_back(key);
        
        if (h.size() == 1) return;
        
        int i = (int) h.size() - 1;
        int p = pof(i);
        
        while (i > 0 && h[i] < h[p]) {
            swap(h[i], h[p]);
            i = p;
            p = pof(i);
        }
    }
    
    int pop() {
        
        if (h.empty()) return top();
        int t = top();
        if (h.size() == 1) {
            h.pop_back();
            return t;
        }
        swap(h.front(), h.back());
        h.pop_back();
        heapify(0);
        return t;
    }
    
    int top() const {
        
        if (h.empty()) {
            cout << "Heap is empty!\n";
            return 0;
        }
        return h.front();
    }
      
    void heapify(int i) {
        
        int l = lof(i);
        int r = rof(i);
        int s = midx(i, l, r);
        
        while (l < h.size() && s != i) {
            swap(h[i], h[s]);
            i = s;
            l = lof(i);
            r = rof(i);
            s = midx(i, l, r);
        }
    }
    
    vector<int> sort() const {
        
        MinHeap t(h);
        
        vector<int> arr; arr.reserve(h.size());
        
        while (t.size()) arr.emplace_back(t.pop());
        
        return arr;
    }
};

int main() {
	
	MinHeap h({8, 1, 6, 3, 4, 5, 9, 7, 2, 4, 6});
	
	auto arr = h.sort();
	
	for (auto x : arr) cout << x << " ";
	cout << "\n";
	
	return 0;
}

// Output : 1 2 3 4 4 5 6 6 7 8 9
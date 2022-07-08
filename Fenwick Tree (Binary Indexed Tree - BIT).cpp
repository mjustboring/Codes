#include <iostream>
#include <vector>
using namespace std;

template <class T>
class BIT {
    
    vector<T> arr;
    vector<T> bit;
    
public:

    BIT(int n) : arr(n), bit(n+1) {}

    template <class Itr>
    BIT(Itr st, Itr en) : arr(st, en), bit(arr.size()+1) {
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i+1; j < bit.size(); j += (-j&j)) {
                bit[j] += arr[i];
            }
        }
    }
    
    T sum(int i) {
        long long res = 0;
        for (i += 1; i; i -= (-i&i)) {
            res += bit[i];
        }
        return res;
    }
    
    long long sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    
    void update(int i, T x) {
        x -= arr[i], arr[i] = x;
        for (++i; i < bit.size(); i += (-i&i)) {
            bit[i] += x;
        }
    }
};

void solve() {
    
    vector<int> a {1, 2, 3, 4, 5};
    BIT<int> t(a.begin(), a.end());
    
    cout << t.sum(2, 2) << '\n';
    
    t.update(2, 8);
    
    cout << t.sum(2, 2) << '\n';
    cout << t.sum(0, 4) << '\n';
    
    cout << '\n';
}

int main() {
	solve();
}
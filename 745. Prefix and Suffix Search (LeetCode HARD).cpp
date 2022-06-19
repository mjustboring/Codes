#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

struct Node {
    
    Node *baby[26];
    vector<int> idx;
    
    Node* put(int8_t c, int i) {
        c -= 'a';
        if (!baby[c]) {
            baby[c] = new Node();
        }
        baby[c]->idx.push_back(i);
        return baby[c];
    }
    
    Node* get(int8_t c) {
        return baby[c - 'a'];
    }
    
    Node() {
        memset(baby, 0, sizeof baby);
    }
    ~Node() {
        for (int i = 0; i < 26; ++i) {
            delete baby[i];
        }
    }
};

struct Trie {
    
    Node *root;
    
    Trie() : root(new Node()) {}
    
    void put(const string &s, int idx, int st, int en, int up) {
        
        Node *node = root;
        
        while (st != en) {
            
            node = node->put(s[st], idx);
            st += up;
        }
    }
    
    const vector<int>* get(const string &s, int st, int en, int up) {
        
        Node *node = root;
        
        while (st != en) {
            
            node = node->get(s[st]);
            st += up;
            
            if (node == 0) {
                return 0;
            }
        }
        
        return &node->idx;
    }
};

struct WordFilter {
    
    Trie pT, sT;
    vector<string> &a;

    WordFilter(vector<string> &a) : a(a) {
        
        for (int i = 0; i < a.size(); ++i) {
            pT.put(a[i], i, 0, a[i].size(), 1);
            sT.put(a[i], i, a[i].size()-1, -1, -1);
        }
    }
    
    int f(const string &pfx, const string &sfx) {
        
        auto x = pT.get(pfx, 0, pfx.size(), 1);
        auto y = sT.get(sfx, sfx.size()-1, -1, -1);
        
        if (!x || !y) return -1;
        
        if (x->size() > y->size()) {
            swap(x, y);
        }
        
        for (auto i = x->rbegin(); i != x->rend(); ++i) {
            
            if (binary_search(y->begin(), y->end(), *i)) {
                return *i;
            }
        }
        
        return -1;
    }
    
    void print(string x, string y) {
        for (auto x : *pT.get(x, 0, x.size(), 1)) {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : *sT.get(y, y.size()-1, -1, -1)) {
            cout << x << " ";
        }
        cout << endl;
    }
};

void solve() {
    
    vector<string> a {"apple", "ape"};
    
    WordFilter wf(a);
    
    cout << wf.f("a", "e");
    
    cout << '\n';
    
    wf.print("a", "e");
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
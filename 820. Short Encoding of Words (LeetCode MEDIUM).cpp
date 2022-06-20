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
    bool send, end;
    
    Node() : send(0), end(0) {
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
    
    void put(string &s) {
        
        Node *node = root;
        
        for (int i = s.size()-1; i >= 0; --i) {
            int x = s[i] - 'a';
            if (!node->baby[x]) {
                node->baby[x] = new Node();
            }
            node = node->baby[x];
            node->end = 0;
        }
        
        node->send = node->end = 1;
    }
    
    void gen(string &s, vector<int> &id) {
        
        string cs = "#";
        vector<int> cid;
        
        function<void (Node*, int)> fun;
        
        fun = [&](Node *node, int i) -> void {
            
            if (node->end) {
                
                int n = s.size();
                
                s.append(cs);
                id.push_back(n+i);
                
                for (auto x : cid) {
                    id.push_back(n+i-x);
                }
                return;
            }
            
            for (int k = 0; k < 26; ++k) {
                
                if (node->baby[k]) {
                    
                    cs.push_back(k + 'a');
                    
                    if (node->send) {
                        cid.push_back(i);
                    }
                    
                    fun(node->baby[k], i+1);
                    
                    cs.pop_back();
                    
                    if (node->send) {
                        cid.pop_back();
                    }
                }
            }
        };
        
        fun(root, 0);
        
        reverse(s.begin(), s.end());
        reverse(id.begin(), id.end());
        
        int n = s.size();
        
        for (auto &x : id) {
            x = n - x;
        }
    }
};

struct Solution {

    int minimumLengthEncoding(vector<string>& words) {
        
        Trie tree;
        
        for (auto &w : words) {
            tree.put(w);
        }
        
        string s;
        vector<int> id;
        
        tree.gen(s, id);
        
        cout << s << endl;
        
        return s.size();
    }
};

void solve() {
    
    vector<string> a {"time", "me", "bell"};
    
    cout << Solution().minimumLengthEncoding(a);
    
    cout << '\n';
}


int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
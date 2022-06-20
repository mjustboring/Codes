#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

struct EngineNode {
    
    EngineNode *baby[26];
    bool end, haveBaby;
    
    EngineNode() : end(0), haveBaby(0) {
        memset(baby, 0, sizeof baby);
    }
    
    ~EngineNode() {
        for (int i = 0; i < 26; ++i) {
            delete baby[i];
        }
    }
};

struct Engine {
    
    EngineNode *root;
    
    Engine() : root(new EngineNode()) {}
    
    void put(string &s) {
        
        EngineNode *node = root;
        
        for (int i = s.size()-1; i >= 0; --i) {
            
            node->haveBaby = 1;
            
            int x = s[i] - 'a';
            if (!node->baby[x]) {
                node->baby[x] = new EngineNode();
            }
            node = node->baby[x];
        }
        
        node->end = 1;
    }
    
    void gen(string &s, vector<int> &id) {
        
        string cs = "#";
        vector<int> cid;
        
        function<void (EngineNode*, int)> fun;
        
        fun = [&](EngineNode *node, int i) -> void {
            
            if (!node->haveBaby) {
                
                int n = s.size();
                
                s.append(cs);
                id.push_back(n+i);
                
                for (auto x : cid) {
                    id.push_back(n+i-x);
                }
                return;
            }
            
            for (int k = 25; k >= 0; --k) {
                
                if (node->baby[k]) {
                    
                    cs.push_back(k + 'a');
                    
                    if (node->end) {
                        cid.push_back(i);
                    }
                    
                    fun(node->baby[k], i+1);
                    
                    cs.pop_back();
                    
                    if (node->end) {
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
            x = n - x - 1;
        }
    }
};

struct Encoder {

    int minimumLengthEncoding(vector<string>& words) {
        
        Engine tree;
        
        for (auto &w : words) {
            tree.put(w);
        }
        
        string s;
        vector<int> id;
        
        tree.gen(s, id);
        
        cout << s << endl;
        for (auto x : id) {
            cout << x << " ";
        }
        cout << endl;
        
        return s.size();
    }
};

struct Node {
    
    Node *baby[26];
    bool haveBaby;
    
    Node() : haveBaby(0) {
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
            
            node->haveBaby = 1;
            
            int x = s[i] - 'a';
            if (!node->baby[x]) {
                node->baby[x] = new Node();
            }
            node = node->baby[x];
        }
    }
    
    int gen() {
        
        int ans = 0;
        
        function<void (Node*, int)> fun;
        
        fun = [&](Node *node, int i) -> void {
            
            if (!node->haveBaby) {
                ans += i;
                return;
            }
            
            for (int k = 0; k < 26; ++k) {
                
                if (node->baby[k]) {
                    fun(node->baby[k], i+1);
                }
            }
        };
        
        fun(root, 1);
        
        return ans;
    }
};

struct Solution {

    int minimumLengthEncoding(vector<string>& words) {
        
        Trie tree;
        
        for (auto &w : words) {
            tree.put(w);
        }
        
        return tree.gen();
    }
};

void solve() {
    
    vector<string> a {"time","me","bell"};
    
    cout << Encoder().minimumLengthEncoding(a);
    
    cout << "\n\n";
    
    cout << Solution().minimumLengthEncoding(a);
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
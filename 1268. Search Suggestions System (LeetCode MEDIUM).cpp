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
    bool end;
    
    Node* put(int8_t c) {
        c -= 'a';
        if (!baby[c]) {
            baby[c] = new Node();
        }
        return baby[c];
    }
    
    Node* get(int8_t c) {
        return baby[c - 'a'];
    }
    
    Node() : end(0) {
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
    vector<string> ans;
    
    Trie() : root(new Node()) {}
    
    void put(const string &s) {
        
        Node *node = root;
        
        for (auto x : s) {
            node = node->put(x);
        }
        
        node->end = 1;
    }
    
    vector<string> get(string &s) {
        
        Node *node = root;
        
        for (auto x : s) {
            node = node->get(x);
            if (!node) return {};
        }
        
        ans.clear();
        
        getAll(node, s);
        
        return ans;
    }
    
    void getAll(Node *node, string &s) {
        
        if (node->end) {
            
            ans.push_back(s);
            
            if (ans.size() == 3) {
                return;
            }
        }
        
        for (int i = 0; i < 26; ++i) {
            
            char x = i+'a';
            
            if (node->get(x)) {
                
                s.push_back(x);
                getAll(node->get(x), s);
                s.pop_back();
                
                if (ans.size() == 3) {
                    return;
                }
            }
        }
    }
};

struct Solution {

    vector<vector<string>> suggestedProducts(vector<string>& prod, string word) {
        
        vector<vector<string>> ans;
        Trie tree;
        
        for (auto &x : prod) {
            tree.put(x);
        }
        
        string text;
        for (auto w : word) {
            text.push_back(w);
            ans.push_back(tree.get(text));
        }
        
        return ans;
    }
};

struct NodeOp {
    
    NodeOp *baby[26];
    priority_queue<string> q;
    
    NodeOp* put(int8_t c) {
        c -= 'a';
        if (!baby[c]) {
            baby[c] = new NodeOp();
        }
        return baby[c];
    }
    
    void putq(const string &s) {
        if (q.size() == 3 && s > q.top()) return;
        q.push(s);
        if (q.size() > 3) {
            q.pop();
        }
    }
    
    NodeOp* get(int8_t c) {
        return baby[c - 'a'];
    }
    
    NodeOp() {
        memset(baby, 0, sizeof baby);
    }
    ~NodeOp() {
        for (int i = 0; i < 26; ++i) {
            delete baby[i];
        }
    }
};

struct TrieOp {
    
    NodeOp *root;
    
    TrieOp() : root(new NodeOp()) {}
    
    void put(const string &s) {
        
        NodeOp *node = root;
        
        for (auto x : s) {
            node = node->put(x);
            node->putq(s);
        }
    }
    
    vector<string> get(string &s) {
        
        NodeOp *node = root;
        
        for (auto x : s) {
            node = node->get(x);
            if (!node) return {};
        }
        
        vector<string> ans;
        
        auto q = node->q;
        
        while (q.size()) {
            ans.push_back(move(const_cast<string&>(q.top())));
            q.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

struct SolutionOp {

    vector<vector<string>> suggestedProducts(vector<string>& prod, string word) {
        
        vector<vector<string>> ans;
        TrieOp tree;
        
        for (auto &x : prod) {
            tree.put(x);
        }
        
        string text;
        for (auto w : word) {
            text.push_back(w);
            ans.push_back(tree.get(text));
        }
        
        return ans;
    }
};

void solve() {
    
    vector<vector<string>> products = {
        {"mobile","mouse","moneypot","monitor","mousepad"},
        {"bags","baggage","banner","box","cloths"}
    };
    vector<string> words {"mouse", "bags"};
    
    vector<vector<vector<string>>> exp {
        {
            {"mobile","moneypot","monitor"},
            {"mobile","moneypot","monitor"},
            {"mouse","mousepad"},
            {"mouse","mousepad"},
            {"mouse","mousepad"}
        },
        {
            {"baggage","bags","banner"},
            {"baggage","bags","banner"},
            {"baggage","bags"},
            {"bags"}
        }
    };
    
    for (int i = 0; i < words.size(); ++i) {
        
        cout << "Product : ";
        for (auto &x : products[i]) {
            cout << x << ", ";
        }
        cout << "\nWord : " << words[i] << endl;
        
        cout << "Expected :-\n";
        for (auto &y : exp[i]) {
            for (auto &x : y) {
                cout << x << ", ";
            }
            cout << endl;
        }
        cout << endl;

        cout << "Answer :-\n";
        auto ans = SolutionOp().suggestedProducts(products[i], words[i]);
        for (auto &y : ans) {
            for (auto &x : y) {
                cout << x << ", ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
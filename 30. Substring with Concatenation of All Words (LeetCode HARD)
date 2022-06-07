#include <bits/stdc++.h>
#pragma GCC optimize("O2")

using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

struct Node {
    int count;
    Node *baby[26];
    Node() : count(0) {
        memset(baby, 0, sizeof(baby));
    }
};

struct Trie {
    
    Node *root;
    Trie() : root(new Node()) {}
    
    void put(string &s, int st, int en) {
        
        Node *node = root;
        
        for (int i = st; i < en; ++i) {
            int x = s[i] - 'a';
            if (node->baby[x]) {
                node = node->baby[x];
            } else {
                node = node->baby[x] = new Node();
            }
        }
        
        node->count += 1;
    }
    
    unsigned has(string &s, int st, int en) {
        
        Node *node = root;
        
        for (int i = st; i < en; ++i) {
            int x = s[i] - 'a';
            if (node->baby[x]) {
                node = node->baby[x];
            } else {
                return 0;
            }
        }
        
        return node->count;
    }
    
    void del(string &s, int st, int en) {
        
        Node *node = root;
        
        for (int i = st; i < en; ++i) {
            int x = s[i] - 'a';
            if (node->baby[x]) {
                node = node->baby[x];
            } else {
                return;
            }
        }
        
        if (node->count) {
            node->count -= 1;
        }
    }
};


struct Solution {

    vector<int> findSubstring(string &s, vector<string> &words) {
        
        Trie trie;
        int n = s.size();
        int m = words[0].size();
        int o = 0;
        
        for (auto &x : words) {
            trie.put(x, 0, m);
            o += m;
        }
        
        deque<int> q;
        vector<int> ans;
        
        for (int k = 0; k < m; ++k) {
            
            int i = k, j = o+k, x = i;
            
            while (j <= n) {
                
                x = max(x, i);
                
                int f = q.empty() ? INT_MAX : q.front();
                
                if (f < i) {
                    trie.put(s, f, f+m);
                    q.pop_front();
                }
                
                while (x < j && trie.has(s, x, x+m)) {
                    trie.del(s, x, x+m);
                    q.push_back(x);
                    x += m;
                }
                
                if (x == j) {
                    ans.push_back(i);
                }
                
                i += m, j += m;
            }
            
            while (q.size()) {
                int f = q.front();
                trie.put(s, f, f+m);
                q.pop_front();
            }
        }
        
        return ans;
    }
};

int main() {
	
	string s = "barfoothefoobarman";
    
    vector<string> w {"foo", "bar"};
    
    auto ans = Solution().findSubstring(s, w);
    
    for (auto x : ans) {
        cout << x << " ";
    }
    
    cout << '\n';
    
    return 0;
}

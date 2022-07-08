#include "/sdcard/Cxx/headers"
using namespace std;

struct Node {
    int freq;
    char chr;
    Node *left;
    Node *right;
    Node(int freq, char chr = 0)
    : freq(freq), chr(chr), left(0), right(0) {
    }
};

class MinHeap {
    vector<Node*> h;
    int minof(int i, int j) const {
        if (i < 0 || i >= h.size()) return j;
        if (j < 0 || j >= h.size()) return i;
        if (h[i]->freq < h[j]->freq) return i;
        return j;
    }
    int minof(int i, int j, int k) const {
        return minof(i, minof(j, k));
    }
    int lof(int i) const { return (i << 1) + 1; }
    int rof(int i) const { return (i << 1) + 2; }
    int pof(int i) const { return ((i-1) >> 1); }
public:
    MinHeap(const vector<pair<char, int>>& v) : h(v.size()) {
        for (int i = 0; i < v.size(); i++) {
            h[i] = new Node(v[i].second, v[i].first);
        }
        for (int i = (h.size() >> 1); i >= 0; i--) {
            heapify(i);
        }
    }
    int size() const { return h.size(); }
    void heapify(int i) {
        int l = lof(i);
        int r = rof(i);
        int s = minof(i, l, r);
        while (l < h.size() && s != i) {
            swap(h[i], h[s]);
            i = s;
            l = lof(i);
            r = rof(i);
            s = minof(i, l, r);
        }
    }
    void push(Node *node) {
        h.push_back(node);
        if (h.size() == 1) return;
        int i = (int)h.size()-1;
        int p = pof(i);
        while (i > 0 && h[i]->freq < h[p]->freq) {
            swap(h[i], h[p]);
            i = p;
            p = pof(i);
        }
    }
    void pop() {
        if (h.size() == 1) {
            h.pop_back();
            return;
        }
        swap(h.front(), h.back());
        h.pop_back();
        if (h.size() > 1) {
            heapify(0);
        }
    }
    Node *top() const {
        return h.front();
    }
};

void freeheap(Node *root) {
    if (root == 0) return;
    freeheap(root->left);
    freeheap(root->right);
    delete root;
}

Node* huffmanTree(const vector<pair<char, int>>& v) {
    MinHeap h(v);
	while (h.size() > 1) {
	    auto a = h.top(); h.pop();
	    auto b = h.top(); h.pop();
	    auto c = new Node(a->freq + b->freq);
	    c->left = a;
	    c->right = b;
	    h.push(c);
	}
	return h.top();
}

void print(Node *root, string s = "") {
    if (root == 0) return;
    if (root->left == 0 && root->right == 0) {
        cout << root->chr << " : " << root->freq << "\t" << s << "\n";
        return;
    }
    print(root->left, s + "0");
    print(root->right, s + "1");
}

int main() {
	vector<pair<char, int>> v {
	    {'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}
	};
	auto root = huffmanTree(v);
	print(root);
	freeheap(root);
	return 0;
}

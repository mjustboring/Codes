#include "/storage/emulated/0/Documents/Cxxdroid/headers"
using namespace std;

struct Node {
    int data;
    bool color;
    Node *left;
    Node *right;
    Node *parent;
    Node(int data)
    : data(data), color(1), left(0),
      right(0), parent(0) {
    }
};

class RBT {
    
    Node *root;
    bool ll,rr,lr,rl;
    
    static Node *sibof(Node *root) {
       
       if (root->parent->left == root) {
           return root->parent->right;
       }
       return root->parent->left;
    }
    
    static Node *rotate_left(Node* root) {
       
       Node *temp = root->right;
       root->right = temp->left;
       temp->left = root;
       
       if (root->right) {
           root->right->parent = root;
       }
       temp->left->parent = temp;
       
       return temp;
    }
    
    static Node *rotate_right(Node* root) {
       
       Node *temp = root->left;
       root->left = temp->right;
       temp->right = root;
       
       if (root->left) {
           root->left->parent = root;
       }
       temp->right->parent = temp;
       
       return temp;
    }
       
    Node *insert(Node *root, int data) {
        
        if (root == 0) {
            return new Node(data);
        }
        
        if (data < root->data) {
            
            root->left = insert(root->left, data);
            root->left->parent = root;
            
            if (root->color && root->left->color) {
                
                Node *sib = sibof(root);
                
                if (sib && sib->color) {
                    
                    sib->color = 0;
                    root->color = 0;
                    root->parent->color = 1;
                    
                } else {
                    
                    if (root->parent->left == root) {
                        ll = true;
                    } else {
                        rl = true;
                    }
                    
                    return root;
                }
            }
            
        } else if (data > root->data) {
            
            root->right = insert(root->right, data);
            root->right->parent = root;
            
            if (root->color && root->right->color) {
                
                Node *sib = sibof(root);
                
                if (sib && sib->color) {
                    
                    sib->color = 0;
                    root->color = 0;
                    root->parent->color = 1;
                    
                } else {
                    
                    if (root->parent->right == root) {
                        rr = true;
                    } else {
                        lr = true;
                    }
                    
                    return root;
                }
                
            }
        }
        
        if (ll) {
            
            root = rotate_right(root);
            root->right->color = 1;
            root->color = 0;
            
            ll = 0;
            
        } else if (lr) {
            
            root->left = rotate_left(root->left);
            root->left->parent = root;
            root = rotate_right(root);
            root->right->color = 1;
            root->color = 0;
            
            lr = 0;
            
        } else if (rr) {
            
            root = rotate_left(root);
            root->left->color = 1;
            root->color = 0;
            
            rr = 0;
            
        } else if (rl) {
            
            root->right = rotate_right(root->right);
            root->right->parent = root;
            root = rotate_left(root);
            root->left->color = 1;
            root->color = 0;
            
            rl = 0;
        }
        
        return root;
    }
    
    Node *remove(Node *root, int data) {
        
        if (root == 0) return 0;
        
        if (data < root->data) {
            
            root->left = remove(root->left, data);
            root->left->parent = root;
            
            if (root->color && root->left->color) {
                
                Node *sib = sibof(root);
                
                if (sib && sib->color) {
                    
                    sib->color = 0;
                    root->color = 0;
                    root->parent->color = 1;
                    
                } else {
                    
                    if (root->parent->left == root) {
                        ll = true;
                    } else {
                        rl = true;
                    }
                    
                    return root;
                }
            }
            
        } else if (data > root->data) {
            
            root->right = remove(root->right, data);
            root->right->parent = root;
            
            if (root->color && root->right->color) {
                
                Node *sib = sibof(root);
                
                if (sib && sib->color) {
                    
                    sib->color = 0;
                    root->color = 0;
                    root->parent->color = 1;
                    
                } else {
                    
                    if (root->parent->right == root) {
                        rr = true;
                    } else {
                        lr = true;
                    }
                    
                    return root;
                }
            }
            
        } else {
            Node *temp = root;
            if (root->left == 0 && root->right == 0) {
                delete temp;
                return 0;
            } else if (root->right == 0) {
                root = root->left;
                delete temp;
                return root;
            } else if (root->left == 0) {
                root = root->right;
                delete temp;
                return root;
            } else {
                Node *succ = temp->right;
                if (succ->left) {
                    while (succ->left) {
                        temp = succ;
                        succ = succ->left;
                    }
                    root->data = succ->data;
                    temp->left = succ->right;
                    delete succ;
                    return root;
                } else {
                    root->data = succ->data;
                    root->right = succ->right;
                    delete succ;
                    return root;
                }
            }
        }
        
        if (ll) {
            
            root = rotate_right(root);
            root->right->color = 1;
            root->color = 0;
            
            ll = 0;
            
        } else if (lr) {
            
            root->left = rotate_left(root->left);
            root->left->parent = root;
            root = rotate_right(root);
            root->right->color = 1;
            root->color = 0;
            
            lr = 0;
            
        } else if (rr) {
            
            root = rotate_left(root);
            root->left->color = 1;
            root->color = 0;
            
            rr = 0;
            
        } else if (rl) {
            
            root->right = rotate_right(root->right);
            root->right->parent = root;
            root = rotate_left(root);
            root->left->color = 1;
            root->color = 0;
            
            rl = 0;
        }
        
        return root;
    }
    
    void print(Node *root, int space) {
        
        if (root == 0) {
            return;
        }
        
        print(root->right, space+4);
        
        for (int i = 0; i < space; i++) {
            cout << " ";
        }
        cout << root->data << "(" << 
        (root->color ? "R": "B") << ")\n";
        
        print(root->left, space+4);
    }
    
    static bool search(Node *root, int data) {
        if (root == 0) return 0;
        if (data < root->data) {
            return search(root->left, data);
        }
        if (data > root->data) {
            return search(root->right, data);
        }
        return 1;
    }
    
public:

    RBT() : root(0),
    ll(0), rr(0), lr(0), rl(0) {
    }
    
    void insert(int data) {
        if (root == 0) {
            root = new Node(data);
            root->color = 0;
            return;
        }
        root = insert(root, data);
        root->color = 0;
        root->parent = 0;
    }
    
    void remove(int data) {
        if (root == 0) return;
        root = remove(root, data);
    }
    
    bool search(int data) {
        if (root == 0) return 0;
        return search(root, data);
    }
    
    void print() {
        if (root == 0) return;
        print(root, 0);
        cout << "\n\n";
    }
};

int main() {
	RBT t;
	vector<int> arr {10, 18, 7, 15, 16, 30, 25, 40, 60, 2, 1, 70};
	for (auto x : arr) {
	    cout << "Input : " << x << "\n\n";
	    t.insert(x);
	    t.print();
	    cout << "\n\n\n";
	}
	return 0;
}
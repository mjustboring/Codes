#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int data = 0)
    : data (data), left (0), right (0) {
    }
};

Node* ins(Node* root, int data) {
    
    if (root == 0) return new Node(data);
    
    if (data < root->data) {
        root->left = ins(root->left, data);
    } else if (data > root->data) {
        root->right = ins(root->right, data);
    }
    return root;
}

Node* del(Node* root, int data) {
    
    if (root == 0) return 0;
    
    if (data < root->data) {
        root->left = del(root->left, data);
    } else if (data > root->data) {
        root->right = del(root->right, data);
    } else {
        Node* temp = root;
        if (root->left == 0 && root->right == 0) {
            delete root;
            root = 0;
        } else if (root->left == 0) {
            root = root->right;
            delete temp;
        } else if (root->right == 0) {
            root = root->left;
            delete temp;
        } else {
            
            Node* pre = temp;
            temp = temp->right;
            
            while (temp->left)
                pre = temp, temp = temp->left;

            swap(temp->data, root->data);
            
            if (root == pre) {
                pre->right = del(pre->right, data);
            } else {
                pre->left = del(pre->left, data);
            }
        }
    }
    return root;
}

void print(Node* root) {
    if (root == 0) return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

int main() {
	Node* root = 0;
	root = ins(root, 4);
	root = ins(root, 2);
	root = ins(root, 6);
	root = ins(root, 1);
	root = ins(root, 3);
	root = ins(root, 5);
	root = ins(root, 7);
	print(root);
	cout << "\n";
	root = del(root, 4);
	root = del(root, 6);
	print(root);
	return 0;
}


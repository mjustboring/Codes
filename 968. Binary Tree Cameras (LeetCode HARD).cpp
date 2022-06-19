#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

const int null = INT_MAX;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete left;
        delete right; 
    }
};

unordered_map<TreeNode*, int> dp[2];

struct Solution {
    
    int fun(TreeNode *root, bool vis) {
        
        if (root == 0) return 0;
        
        auto itr = dp[vis].find(root);
        
        if (itr != dp[vis].end()) {
            return itr->second;
        }
        
        int ans = 1;
        ans += fun(root->left, 1);
        ans += fun(root->right, 1);
        
        if (vis) {
            
            ans = min(ans,
                fun(root->left, 0) +
                fun(root->right, 0));
                
        } else {
            
            if (root->left) {
                
                ans = min(ans,
                    fun(root->left->left, 1) +
                    fun(root->left->right, 1) +
                    fun(root->right, 0) + 1);
            }
            
            if (root->right) {
                
                ans = min(ans,
                    fun(root->left, 0) +
                    fun(root->right->left, 1) +
                    fun(root->right->right, 1) + 1);
            }
        }
        
        return dp[vis][root] = ans;
    }

    int minCameraCover(TreeNode* root) {
        
        if (root == 0) return 0;
        if (!root->left && !root->right) return 1;
        
        dp[0].clear();
        dp[1].clear();
        
        return fun(root, 0);
    }
};

enum CameraStatus {INSTALLED, MONITERED, NOT_MONITERED};

struct SolutionOp {
    
    int cameras;
    
    CameraStatus fun(TreeNode *root) {
        
        if (root == 0) return MONITERED;
        
        auto l = fun(root->left);
        auto r = fun(root->right);
        
        if (l == NOT_MONITERED || r == NOT_MONITERED) {
            cameras += 1;
            return INSTALLED;
        }
        
        if (l == INSTALLED || r == INSTALLED) {
            return MONITERED;
        }
        
        return NOT_MONITERED;
    }

    int minCameraCover(TreeNode* root) {
        
        if (root == 0) return 0;
        
        cameras = 0;
        
        if (fun(root) == NOT_MONITERED) {
            cameras += 1;
        }
        
        return cameras;
    }
};

TreeNode* makeTree(const vector<int> &a) {
    
    if (a.empty()) return 0;
    
    TreeNode *root = new TreeNode(a[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    for (int i = 1; i < a.size(); i += 2){
        
        auto n = q.front();
        q.pop();
        
        if (a[i] != null) {
            n->left = new TreeNode(a[i]);
            q.push(n->left);
        }
        
        if (i+1 < a.size() && a[i+1] != null) {
            n->right = new TreeNode(a[i+1]);
            q.push(n->right);
        }
    }
    
    return root;
}

void printTree(TreeNode *root, int s = 2) {
    if (root == 0) return;
    printTree(root->right, s+4);
    cout << setw(s) << root->val << "\n";
    printTree(root->left, s+4);
}

void solve() {
    
    vector<vector<int>> trees {
        {1},
        {0,1,null,0,0},
        {0,1,null,0,null,1,null,null,0},
        {0,1,null,null,0,0,null,null,1,0},
        {1,null,0,null,1,null,0},
        {0,null,1,null,0,null,0,null,1,0,1,null,null,0,0}
    };
    
    vector<int> exp {1,1,2,2,2,3};
    
    for (int i = 0; i < trees.size(); ++i) {
        auto tree = makeTree(trees[i]);
        printTree(tree);
        printf("Expected : %d\n", exp[i]);
        printf("Answer : %d\n", Solution().minCameraCover(tree));
        printf("AnswerOp : %d\n\n\n", SolutionOp().minCameraCover(tree));
    }
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
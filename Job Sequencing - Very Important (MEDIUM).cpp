#include "/storage/emulated/0/Documents/Cxxdroid/headers"
// #include <bits/stdc++.h>
using namespace std;

static const bool ___ = []() {
    ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	return 0;
}();

struct Job { 
    int id;	 // Job Id 
    int dead;   // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

struct Solution {

    vector<int> JobScheduling(Job a[], int n) {
        
        sort(a, a+n, [](Job &a, Job &b) {
            if (a.dead == b.dead) {
                return a.profit > b.profit;
            }
            return a.dead < b.dead;
        });
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        for (int i = 0; i < n; ++i) {
            if (a[i].dead > q.size()) {
                q.push(a[i].profit);
            } else if (q.top() < a[i].profit) {
                q.pop();
                q.push(a[i].profit);
            }
        }
        
        vector<int> ans(2);
        
        ans[0] = q.size();
        
        while (q.size()) {
            ans[1] += q.top();
            q.pop();
        }
        
        return ans;
    } 
};

void solve() {
    
    int n1 = 4;
    Job a1[] = {
        {1, 4, 20}, {2, 1, 10}, {3, 1, 40},
        {4, 1, 30}
    };
    
    int n2 = 5;
    Job a2[] = {
        {1, 2, 100}, {2, 1, 19}, {3, 2, 27},
        {4, 1, 25}, {5, 1, 15}
    };
        
    Solution s;
    
    auto ans1 = s.JobScheduling(a1, n1);
    auto ans2 = s.JobScheduling(a2, n2);
    
    cout << ans1[0] << "  " << ans1[1] << "\n\n";
    cout << ans2[0] << "  " << ans2[1];
    
    cout << '\n';
}

int main() {
	
	int t = 1;
	// cin >> t;
	
	while (t--) solve();
	
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

bool bell_ford(const vector<Edge>& edges, int V) {
   
   vector<int> dist(V, INT_MAX);
   dist[0] = 0;
   
   while (--V > 0) {
       
       for (auto &e : edges) {
           
           if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
               dist[e.v] = dist[e.u] + e.w;
           }
       }
   }
   
   for (auto &e : edges) {
           
       if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
           return true;
       }
   }
   
   return false;
}

int main() {
	int V = 3;
	vector<Edge> edges {{0,1,-1},{1,2,-2},
{2,0,3}};
    cout << bell_ford(edges, V);
	return 0;
}
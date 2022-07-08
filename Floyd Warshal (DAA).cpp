#include "/sdcard/Cxx/headers"
using namespace std;

#define N 5
#define I INT_MAX

void print(int g[N][N]) {
    
    for (int u = 0; u < N; u++) {
        for (int v = 0; v < N; v++) {
            if (g[u][v] == I)
                cout << setw(3) << "I";
            else
                cout << setw(3) << g[u][v];
        }
        cout << "\n";
    }
    cout << "\n";
}

void floyd(int g[N][N]) {
    
    cout << "D[0]\n";
    print(g);
    
    for (int k = 0; k < N; k++) {
        for (int u = 0; u < N; u++) {
            for (int v = 0; v < N; v++) {
                if (
                    g[u][k] != I && g[k][v] != I &&
                    g[u][v] > g[u][k] + g[k][v]
                ) {
                    g[u][v] = g[u][k] + g[k][v];
                }
            }
        }
        cout << "D[" << k+1 << "]\n";
        print(g);
    }
}

int main() {
	int g[N][N] = {
	    {0, 5, I, 2, I},
	    {I, 0, 2, I, I},
	    {3, I, 0, I, 7},
	    {I, I, 4, 0, 1},
	    {1, 3, I, I, 0}
	};
	floyd(g);
	return 0;
}
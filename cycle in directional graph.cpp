#include <bits/stdc++.h>
#define N 100005
#define pb push_back
#define mk make_pair
#define ff first
#define ss second
#define pr pair<int,int>
using namespace std;
vector <int> g[N];
bool color[N];
int n, par[N];
enum {white, gray, black};

void printCycle (int u, int v ) {
    cout << "Cycle detected: " << v << " ";
    int p = par[v];
    while (p != v) {
        cout << p << " ";
        p = par[p];
    }
    cout << v << "\n";
}
void dfs (int u) {
    color[u] = gray;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (color[v] == gray) {
            par[v] = u;
            printCycle(u, v);
        }
        if (color[v] == white) {
            par[v] = u;
            dfs (v);
        }
    }
    color[u] = black; //erasing from recursive stack
}
void cycleFind () {
    memset (color, 0, sizeof (color));
    for (int i = 0; i < n; i++) par[i] = -1;
    for (int i = 0; i < n; i++) {
        if (color[i] == white) dfs (i);
    }
}
int main ()
{
    n = 4;

    g[0].pb (1);
    g[0].pb (2);
    g[1].pb (2);
    g[2].pb (0);
    g[2].pb (3);
    g[3].pb (3);
    cycleFind ();
    return 0;
}

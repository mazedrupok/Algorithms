#include <bits/stdc++.h>
using namespace std;
//LCA using sparse table
//Complexity: O(NlgN,lgN)
#define mx 100002
#define pb push_back
int L[mx]; //Label
int ST[mx][33]; //Sparse Table
int P[mx]; //Parent
vector<int>g[mx];
void dfs (int u, int par, int label) {
    L[u] = label;
    P[u] = par;
    int sz = g[u].size();
    for (int i = 0; i < sz; i++) {
        int v = g[u][i];
        dfs (v, u, label+1);
    }
}
void lca_init (int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 33; j++) ST[i][j] = -1;
    }
    for (int j = 0; j < n; j++) ST[j][0] = P[j]; //2^0 th parent

    for (int j = 1; (1 << j) < n; j++)
        for (int i = 0; i < n; i++)
            if (ST[i][j-1] != -1) ST[i][j] = ST[ ST[i][j-1] ][j-1];

}
int find_lca (int u, int v) {
    if (L[u] < L[v]) swap (u, v);
    for (int i = 30; i >= 0; i--)
        if (L[u] - (1 << i) >= L[v]) u = ST[u][i]; //L[v] means in what label should go

    if (u == v) return u;

    for (int i = 30; i >= 0; i--) {
        if (ST[u][i] != -1 && ST[u][i] != ST[v][i]) {
            u = ST[u][i]; v = ST[v][i];
        }
    }
    return P[u];
}

int main()
{
    int n, e, u, v, q;
    scanf (" %d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf (" %d %d", &u, &v);
        g[u].pb (v);
    }
	memset (P, -1, sizeof (P));
	dfs (0, 0, 0); //node starting from 0
    lca_init(n);
    scanf (" %d", &q); //query
    while (q--) {
        scanf (" %d %d", &u, &v);
        printf ("%d\n", find_lca(u, v));
    }
    return 0;
}


//lightoj 1348
//Heavy Light Decomposition
//Segment tree-> 1 position update & range query
//1-indexed program
#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define MX 100005
using namespace std;

vector <int> g[MX];
int ara[MX];
int subTreeSz[MX], parent[MX], depth[MX], heavy[MX];
int chain[MX], number[MX], chainTop[MX], chainSz[MX];
int seg[270000], chainSum[270000];
int n;
void clean () {
    memset (seg, 0, sizeof (seg));
    memset (chainSum, 0, sizeof (chainSum));
    for (int i = 0; i < MX; i++) {
        heavy[i] = -1;
        chainTop[i] = -1;
        chainSz[i] = 0;
        g[i].clear();
    }
}
void dfs (int u) { //depth, heavyChild, parent, SubTreeSize
    subTreeSz[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; //child
        if (v == parent[u]) continue;

        parent[v] = u;
        depth[v] = depth[u] + 1;
        dfs (v);
        subTreeSz[u] += subTreeSz[v];
        if (heavy[u] == -1 || subTreeSz[heavy[u]] < subTreeSz[v]) heavy[u] = v; //creating heavy child
    }
} 
int cnt = 1, all = 1;
void hld (int u, int pa = -1) {
    chain[u] = cnt;
    number[u] = all++; //numbering for segment array
    if (chainSz[cnt] == 0) chainTop[cnt] = u; //chain top node
    chainSz[cnt]++;
    if (heavy[u] != -1) hld (heavy[u], u); //next heavy child

    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v == heavy[u] || v == pa) continue;
        cnt++;
        hld (v, u);
    }
}

int segQuery (int at, int st, int en, int L, int R) {
    if (L > en || R < st) return 0;
    if (st >= L && en <= R) return seg[at];
    int mid = (st+en) >> 1;
    int x = segQuery (at << 1, st, mid, L, R);
    int y = segQuery (at << 1 | 1, mid+1, en, L, R);
    return x+y;
}

void segUpdate (int at, int st, int en, int pos, int val) {
    if (st == en) {seg[at] = val; return;} //vertex is changed
    int mid = (st+en) >> 1;
    if (pos <= mid) segUpdate (at << 1, st, mid, pos, val);
    else segUpdate (at << 1 | 1, mid+1, en, pos, val);
    seg[at] = seg[at << 1] + seg[at << 1 | 1];
}

void modify (int a, int val) {
    segUpdate (1, 1, n, number[a], val);
    int L = number[chainTop[chain[a]]];
    int R = L + chainSz[chain[a]] - 1;
    chainSum[chain[a]] = segQuery (1, 1, n, L, R);
}

int go (int a, int b) {
    int res = 0; //sum
    while (chain[a] != chain[b]) { //determining LCA
        if (depth[chainTop[chain[a] ]] < depth[chainTop[chain[b] ]]) swap (a, b); //a to be large
        int start = chainTop[chain[a]]; //top node of chain
        if (number[a] == number[start] + chainSz[chain[a]] - 1) res += chainSum[chain[a]]; //fully
        else res += segQuery (1, 1, n, number[start], number[a]); //partially
        a = parent[start];
    }
    if (depth[a] > depth[b]) swap (a, b); //a to be small
    return res += segQuery (1, 1, n, number[a], number[b]);
}

int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, q, e, u, v, test;
    scanf (" %d", &tc);
    while (tc--) {
        clean ();
        scanf (" %d", &n);
        for (int i = 1; i <= n; i++) scanf (" %d", &ara[i]);
        e = n-1;
        while (e--) {
            scanf (" %d %d", &u, &v); u++; v++;
            g[u].push_back (v);
            g[v].push_back (u);
        }
        cnt = 1; all = 1; //initialization for HLD
        parent[1] = 0; depth[1] = 1; //initialization for DFS
        dfs (1);
        hld (1);
        for (int i = 1; i <= n; i++) modify (i, ara[i]);

        printf ("Case %d:\n", ++cs);
        scanf (" %d", &q);
        while (q--) {
            scanf (" %d %d %d", &test, &u, &v);
            if (test == 1) modify (u+1, v);
            else printf ("%d\n", go (u+1, v+1));
        }
    }
    return 0;
}

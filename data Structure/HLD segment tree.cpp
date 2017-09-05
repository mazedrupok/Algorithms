//spoj QTREE
//Heavy Light Decomposition
//Segment tree-> 1 position update & range query
//1-indexed program
#include <bits/stdc++.h>
#define ll long long
#define LL long long
#define MX 100005
using namespace std;

vector <int> g[MX];
vector <int> cost[MX];
int subTreeSz[MX], parent[MX], depth[MX], heavy[MX];
int chain[MX], number[MX], chainTop[MX], chainSz[MX];
int seg[270000], chainMx[270000];
int n;
void clean () {
    memset (seg, 0, sizeof (seg));
    memset (chainMx, 0, sizeof (chainMx));
    for (int i = 0; i < MX; i++) {
        heavy[i] = -1;
        chainTop[i] = -1;
        chainSz[i] = 0;
        g[i].clear();
        cost[i].clear();
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
    return max (x, y);
}

void segUpdate (int at, int st, int en, int pos, int val) {
    if (pos < st || pos > en) return;
    if (st == en && st == pos) {seg[at] = val; return;}
    int mid = (st+en) >> 1;
    segUpdate (at << 1, st, mid, pos, val);
    segUpdate (at << 1 | 1, mid+1, en, pos, val);
    seg[at] = max (seg[at << 1], seg[at << 1 | 1]);
}

void modify (int a, int val) {
    segUpdate (1, 1, n, number[a], val);
    int L = number[chainTop[chain[a]]];
    int R = L + chainSz[chain[a]] - 1;
    chainMx[chain[a]] = segQuery (1, 1, n, L, R);
}

int go (int a, int b) {
    int res = 0;
    while (chain[a] != chain[b]) { //determining LCA
        if (depth[chainTop[chain[a] ]] < depth[chainTop[chain[b] ]]) swap (a, b); //a to be large
        int start = chainTop[chain[a]]; //top node of chain
        if (number[a] == number[start] + chainSz[chain[a]] - 1) res = max (res, chainMx[chain[a]]); //fully
        else res = max (res, segQuery (1, 1, n, number[heavy[start]], number[a])); //partially
        a = parent[start];
        //normal edge calculation
        if (g[start][0] == parent[start]) res = max (res, cost[start][0]);
        else res = max (res, cost[start][1]);
    }
    if (depth[a] > depth[b]) swap (a, b); //a to be small
    return res = max (res, segQuery (1, 1, n, number[heavy[a]], number[b]));
}

struct node {
    int u, v, w;
};
node ara[100005];
int main ()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, u, v, w, a, b;
    scanf (" %d", &tc);
    while (tc--) {
        clean ();
        scanf (" %d", &n);
        for (int i = 1; i < n; i++) {
            scanf (" %d %d %d", &ara[i].u, &ara[i].v, &ara[i].w);
            u = ara[i].u;
            v = ara[i].v;
            w = ara[i].w;
            g[u].push_back (v);
            g[v].push_back (u);
            cost[u].push_back (w);
            cost[v].push_back (w);
        }
        cnt = 1; all = 1; //initialization for HLD
        parent[1] = 0; depth[1] = 1; //initialization for DFS
        dfs (1);
        hld (1);
        for (int i = 1; i < n; i++) {
            u = ara[i].u;
            v = ara[i].v;
            w = ara[i].w;
            if (heavy[u] == v) modify (v, w);
            else if (heavy[v] == u) modify (u, w);
        }

        char test[15];
        while (scanf (" %s", test) == 1) {
            if (test[0] == 'D') break;
            scanf (" %d %d", &a, &b);

            if (test[0] == 'Q') printf ("%d\n", go (a, b));
            else {
                ara[a].w = b;
                u = ara[a].u;
                v = ara[a].v;
                w = ara[a].w;
                if (g[u][0] == v) cost[u][0] = w;
                if (g[u][1] == v) cost[u][1] = w;
                if (g[v][0] == u) cost[v][0] = w;
                if (g[v][1] == u) cost[v][1] = w;

                if (heavy[u] == v) modify (v, w);
                else if (heavy[v] == u) modify (u, w);
            }
        }

    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define N 100005

vector <int> g[N];     //main graph
vector <int> rg[N];    // reversed graph
vector <int> vc;
bool vis[N];
int comp[N];               // component number of a node
int inDegree[N];           // in-degree of a component
vector <int> compo[N];      // components print
void reset () {
    for (int i = 0; i < N; i++ ) {
        g[i].clear();
        rg[i].clear();
        compo[i].clear();
    }
    vc.clear();
    memset (vis, false, sizeof vis);
    memset (inDegree, 0, sizeof inDegree);
    memset (comp, 0, sizeof comp);
}
void dfs1 (int u) {
    vis[u] = true;
    for (int i = 0; i < g [u].size(); i++ ) {
        if ( !vis[g[u][i]] ) dfs1(g[u][i]);
    }
    vc.push_back(u);
}
void dfs2 (int u, int c) {
    vis[u] = 1;
    comp[u] = c;
    for (int i = 0; i < rg[u].size(); i++) {
        if (vis[rg[u][i]] == 0) dfs2(rg[u][i], c);
    }
}
int main ()
{
    int n, e, u, v;
    int tc, cs = 0;
    reset ();
    cin >> n >> e; //no. of nodes & edges
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        // take input in "form" and "to"
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    for (int i = 0; i < n; i++ ) { //graph node 0 to n-1
        if (vis[i] == 0) dfs1 (i);
    }
    int componentId = 0;
    for (int i = 0; i <= n; i++) vis[i] = 0;
    for (int i = vc.size()-1; i >= 0; i--) {
        if (vis[vc[i]] == 0)
            dfs2(vc[i], ++componentId);
    }
    // component indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            if (comp[i] != comp[g[i][j]])
                inDegree[comp[g[i][j]]]++;
        }
    }
    // printing components
    for (int i = 0; i < n; i++) {
        compo[comp[i]].push_back (i);
    }
    for (int i = 1; i <= componentId; i++) {
        for (int j = 0; j < compo[i].size(); j++) {
            if (j == 0) cout << "{";
            cout << " " << compo[i][j];
            if (j == compo[i].size()-1) cout << " } & its Indegree: " << inDegree[i] << "\n";
        }
    }
    return 0;
}

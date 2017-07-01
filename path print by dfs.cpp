#include <bits/stdc++.h>

#define ll long long
#define sc(N) scanf (" %d", &N)
#define scc(N) scanf (" %c", &N)
#define scs(N) scanf (" %s", N)
#define For(i,N) for (int i = 0; i < N; i++)
#define pb push_back
#define mk make_pair
#define pr pair<int,int>
#define ff first
#define ss second
using namespace std;
bool seen[100005] = {0};
vector <int> g[100005];
int ara[100005], path[100005], pathSz = 0, d;
void dfs (int u) {
    seen[u] = 1;
    path[pathSz++] = u;
    if (u == d) {
        for (int i = 0; i < pathSz; i++) cout << path[i] << " ";
        cout << endl;
        seen[d] = 0;
        pathSz--;
        return;
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!seen[v]) {
            dfs (v);
        }
    }
    pathSz--;
    seen[u] = 0;
}
int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, cs = 0, n;
    sc (tc);
    while (tc--) {
        sc (n);
        For (i, n) { //input of graph
            sc (ara[i]);
            if (i == 0) continue;
            g[ara[i]].push_back (ara[i-1]);
            g[ara[i-1]].push_back (ara[i]);
        }
        //For (i, n) sort (g[i+1].begin(), g[i+1].end());
        d = ara[n-1]; //destination node
        dfs (ara[0]); //source node

        vector<int> tt[100005]; swap (tt, g);
    }
    return 0;
}

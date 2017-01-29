#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector <int> g[MAXN];
vector <int> articulation_points;
bool visit[MAXN];
int timer, start[MAXN], low[MAXN];

inline void dfs(int u){
    bool flag=0;
    int child=0;
    start[u] = ++timer;
    low[u] = start[u];
    for (int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!start[v]){
            dfs(v);
            ++child;
            low[u] = min(low[u],low[v]);
            if (low[v] >= start[u])
                flag = true;
        }
        else
            low[u] = min(low[u],start[v]);
    }
    if((u==1 && child > 1) || (u != 1 && flag))
        articulation_points.push_back(u); //u is an AP.
}
int main() {
	int n, e, u, v;
	timer = 0;
	cin >> n >> e;
	int edge_u[n], edge_v[n];
	for (int i = 0; i < e; i++) {
        cin >> u >> v;
        edge_u[i] = u;
        edge_v[i] = v;
        g[u].push_back (v);
        g[v].push_back (u);
	}
    memset (visit, 0, sizeof (visit));
	dfs (1);
	cout << "Articulation points: ";
	for (int i = 0; i < articulation_points.size(); i++) {
        cout << articulation_points[i] << " ";
	} cout << endl;

	//clear section
}

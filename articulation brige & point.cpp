#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector <int> g[MAXN];
vector <int> articulation_points;
vector <pair<int, int> > articulation_edges;
int timer = 1, start[MAXN], low[MAXN];

void dfs(int u, int P){
    bool flag=0;
    int child=0;
    start[u] = timer;
    low[u] = timer;
    timer++;
    for (int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if (v == P) continue;
        if(start[v] == 0) { //working as visited array
            dfs(v, u);
            if (low[v] > start[u])
                articulation_edges.push_back (make_pair (u, v));
            ++child;
            low[u] = min(low[u], low[v]);
            if (low[v] >= start[u]) flag = true;
        }
        else low[u] = min(low[u], start[v]);
    }
    if((u==1 && child > 1) || (u != 1 && flag))
        articulation_points.push_back(u); //u is an AP.
}
int main() {
	int n, e, u, v;
	timer = 0;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
	}
	memset (start, 0, sizeof (start));
	dfs (1, -1);
	cout << "Articulation points: ";
	for (int i = 0; i < articulation_points.size(); i++) {
        cout << articulation_points[i] << " ";
	} cout << endl;
    cout << "Articulation edges:\n";
    for (int i = 0; i < articulation_edges.size(); i++) {
        cout << articulation_edges[i].first << " " << articulation_edges[i].second << endl;
    }
	//clear section
}

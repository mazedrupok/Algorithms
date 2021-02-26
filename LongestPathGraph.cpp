#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > g;
int ans = 0;

void BT(g G, int v, int dist){
	ans = max(ans, dist);
	int tam = G[v].size();
	for(int i = 0; i < tam; i++){
		int s = G[v][i];
		if(s != -1){
			G[v][i] = -1;
			int t = G[s].size();
			bool find = false;
			for(int j = 0; j < t && !find; j++){
				if(G[s][j] == v){
					find = true;
					G[s][j] = -1;
				}
			}
			BT(G, s, dist+1);
		}
	}
}

int main(){
	int n, m; 
	while(cin >> n >> m){
		if(!n || !m) break;
		g G(n+1);
		for(int i = 0; i < m; i++){
			int a, b; cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		for(int i = 0; i < n; i++) BT(G, i, 0);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}

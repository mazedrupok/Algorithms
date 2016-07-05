/*
UVA 11396 - Claw Decomposition
bipartite check
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen ("in.txt", "r", stdin);
    int n, m, a, b;
    while(scanf(" %d", &n), n){
        vector <int> G[n+1];
        while(scanf(" %d %d", &a, &b), (a||b)){
            G[a].push_back(b);
            G[b].push_back(a);
        }
        bool bipartite;
        queue <int> q;
        map <int, int> mp; //works as visited array

        for(int i = 1; i <= n; i++) {
            if(mp.count(i)) continue;
            mp[i] = 0;
            bipartite = true;
            q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(int j = 0; j < G[u].size(); j++){
                    int v = G[u][j];
                    if(!mp.count(v)){
                        mp[v] = 1-mp[u]; //if mp[u] is 0 then mp[v] = 1
                                         //if mp[u] is 1 then mp[v] = 0
                        q.push(v);
                    }
                    else if(mp[v] == mp[u]){
                       bipartite = false;
                    }
                }
                if (bipartite == false) break;
            }
            if(!bipartite) break;
        }
        if(bipartite) printf("YES\n");
        else          printf("NO\n");
    }
    return 0;
}

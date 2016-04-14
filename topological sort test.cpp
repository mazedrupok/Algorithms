#include <bits/stdc++.h>
using namespace std;
#define mx 10005
#define white 0
#define gray  1
#define black 2

vector <int> g[mx];
map <string, int> mp;
bool cycle;
int color[mx];
void dfs_topo (int u) {
   color[u] = gray;
   for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (color[v] == white) dfs_topo(v);
      else if (color[v] == gray) {
         cycle = true;
         return;
      }
   }
   color[u] = black;
}
void dfs (int n) {
   memset (color, 0, sizeof (color));
   for (int i = 1; i <= n; i++) {
      if (cycle == true) return;
      if (color[i] == white) dfs_topo (i);
   }
}
int main ()
{
   int tc, cs = 0, m, cnt = 1;
   string s, t;
   cin >> tc;
   while (tc--) {
      cin >> m;
      cnt = 1;
      while (m--) {
         cin >> s >> t;
         if (mp[s] == 0) mp[s] = cnt++;
         if (mp[t] == 0) mp[t] = cnt++;
         g[mp[s]].push_back (mp[t]);
      }
      printf ("Case %d: ", ++cs);
      cycle = false;
      dfs (cnt-1);
      if (cycle == true) cout << "No" << endl;
      else cout << "Yes" << endl;

      vector <int> t[mx]; swap (g, t);
      mp.clear();
   }
   return 0;
}

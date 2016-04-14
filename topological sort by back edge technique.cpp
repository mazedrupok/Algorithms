/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com
           or, mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Problem: Graph (Topological Sort)
   Comment: Topological sort works for directed acyclic graph.
            Here I used DFS back edge finishing time technique :)
            Shafayet blog
*/
#include <bits/stdc++.h>
using namespace std;
#define mx 10005
#define white 0
#define gray  1
#define black 2

vector <int> g[mx];
map <string, int> mp;
vector <int> vc;
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
   vc.push_back (u);
}
void dfs (int n) {
   memset (color, 0, sizeof (color));
   for (int i = 1; i <= n; i++) { //it is used whether graph is not connected.
      if (cycle == true) return;
      if (color[i] == white) dfs_topo (i);
   }
}
int main ()
{
   int tc, cs = 0, n, e, u, v;
   cin >> tc;
   while (tc--) {
      cin >> n >> e;
      for (int i = 0; i < e; i++) {
         cin >> u >> v;
         g[u].push_back (v);
      }
      printf ("Case %d: ", ++cs);
      cycle = false;
      dfs (n);
      reverse (vc.begin(), vc.end());
      cout << "Topological sort is: ";
      for (int i = 0; i < vc.size(); i++) cout << vc[i] << " ";
      cout << endl;

      if (cycle == true) cout << "No, Topological sort impossible, cycle exist" << endl;
      else cout << "Yes, Topological sort possible" << endl;

      vector <int> t[mx]; swap (g, t);
      mp.clear();
      vc.clear();
   }
   return 0;
}

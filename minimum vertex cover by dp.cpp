/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com || mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Catagory: Graph (Minimum Vertex Cover)
   Comment:  MVC by using DP technique.

*/
#include <bits/stdc++.h>
using namespace std;
#define MX  100002
vector <int> g[MX];
int par[MX];
int dp[MX][2];
int MVC (int u, bool guard) { //current node u, and this node have guard or not.
   if (g[u].size() == 0) return 0;
   if (dp[u][guard] != -1) return dp[u][guard]; //already optimized.
   int sum = 0;
   for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (v != par[u]) { //prevent going back.
         par[v] = u;
      //current node have no guard, so next node must have a guard.
      //or current node have a guard, so next node may have guard or not.
         if (guard == 0) sum += MVC (v, 1);
         else sum += min (MVC(v, 0), MVC(v, 1));
      }
   }
   return dp[u][guard] = sum + guard; //if current node have a guard, we must add 1.
}
int main ()
{
   int n, e, u, v, tc, cs = 0;
   cin >> tc;
   while (tc--) {
      memset (dp, -1, sizeof (dp));
      memset (par, -1, sizeof (par));
      cin >> e;
      for (int i = 0; i < e; i++) {
         cin >> u >> v;
         g[u].push_back (v);
         g[v].push_back (u);
      }
      int ans = min (MVC(1, 0), MVC(1, 1));
      cout << "Minimum Vertex Cover is: " << ans << endl;
      vector <int> t[MX]; swap (t, g);
   }
   return 0;
}

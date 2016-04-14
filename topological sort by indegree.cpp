/*
   Name:  Md. Abdul Mazed
   Noakhali Science & Technology University
   Email:  mazedrupok@gmail.com
           or, mazed4g@gmail.com
   FB id:  www.facebook.com/mazedrupok
   github: www.github.com/mazedrupok

   Problem: Graph (Topological Sort)
   Comment: Topological sort works for directed acyclic graph.
            Here I used in-degree technique :)
*/
#include <bits/stdc++.h>
using namespace std;
#define mx 10005
vector <int> g[mx];
vector <int> vc;
int indeg[mx];
void top_sort (int n) {
   for (int i = 1; i <= n; i++) {
      if (indeg[i] == 0) vc.push_back (i);
   }
   for (int i = 0; i < vc.size(); i++) {
      int u = vc[i];
      for (int j = 0; j < g[u].size(); j++) {
         int v = g[u][j];
         indeg[v]--;
         if (indeg[v] == 0) vc.push_back (v);
      }
   }
   bool temp = false;
   for (int i = 1; i <= n; i++) {
      if (indeg[i] > 0) {temp = true; break;}
   }
   if (temp == true ) cout << "No, Sort not possible" << endl;
   else cout << "Yes, Sort is possible" << endl;

   cout << "Topological Sort is: ";
   for (int i = 0; i < vc.size(); i++)
      cout << vc[i] << " "; cout << endl;

}
int main ()
{
   int tc, cs = 0, cnt = 1, n, e, u, v;

   cin >> tc;
   while (tc--) {
      memset (indeg, 0, sizeof (indeg));

      cin >> n >> e;
      for (int i = 0; i < e; i++) {
         cin >> u >> v;
         g[u].push_back (v); //one directional graph..
         g[v].push_back (u);
         indeg[u]++;
         indeg[v]++;
      }

      printf ("Case %d: ", ++cs);
      top_sort(n);

      vector <int> t1[mx];
      swap (t1, g);
      vc.clear();
   }
   return 0;
}


//Shafayet er Blog
//Prim's Algorithm
//Minimum spanning tree
#include <bits//stdc++.h>
using namespace std;
struct data {
   int u, v, cost;
   data (int a, int b, int c) {u = a; v = b; cost = c;}
   bool operator < (const data &p) const {
      return p.cost < cost;
   }
};
bool visit[1010];
vector <int > G[1010];
vector <int > cost[1010];
int prims_mst (int n, int m, int k) {
   priority_queue <data> pq;
   memset (visit, 0, sizeof (visit));
   visit[k] = 1;
   for (int i = 0; i < G[k].size(); i++) {
      int v = G[k][i];
      int w = cost[k][i];
      pq.push(data(k, v, w));
   }
   int cnt = 0;
   while (pq.empty() == 0) {
      data a = pq.top(); pq.pop();
      int u, v, w;
      u = a.u; v = a.v; w = a.cost;
      //printf ("%d %d %d\n", u, v, w);
      if (!visit[v]) {
         visit[v] = 1;
         cnt += w;
         u = v;
         for (int i = 0; i < G[u].size(); i++) {
            v = G[u][i];
            w = cost[u][i];
            if (!visit[v]) pq.push(data(u, v, w));
         }
      }
   }
   return cnt;
}
int main ()
{
   int n, e, temp = 0, tc, cas = 0, k, m;
   //freopen ("in.txt", "r", stdin);
   scanf (" %d", &tc);
   while (tc--) {
      scanf (" %d %d %d", &n, &m, &k);
      for (int i = 0; i < m; i++) {
         int u, v, w;
         scanf (" %d %d %d", &u, &v, &w);
         G[u].push_back (v);
         G[v].push_back (u);
         cost[u].push_back (w);
         cost[v].push_back (w);
      }
      int x = prims_mst (n, m, k);
      if (x == 0) printf ("Case %d: impossible\n", ++cas);
      else printf ("Case %d: %d\n", ++cas, x);

      vector <int> t1[1010];
      vector <int> t2[1010];
      swap (G, t1);
      swap (cost, t2);
   }

   return 0;
}
/*
1
7 11 1
1 2 7
1 4 5
2 3 8
2 4 9
2 5 7
3 5 5
4 5 15
4 6 6
5 6 8
5 7 9
6 7 11
*/
/*
tricky case by jane alam jan..
1
5 10 3
3 1 80
3 2 67
3 4 94
1 2 39
1 0 53
1 4 16
2 1 88
2 0 30
2 4 47
4 1 26
*/

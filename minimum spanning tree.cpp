//from shafayets blog..
//Kruskal algorithm..
#include <bits//stdc++.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define mx 200000
struct node {
   int u, v, w;
   node (int a, int b, int c) {u = a; v = b; w = c;}
   bool operator < (const node& p) const {return w < p.w;} //if present nodes cost is greater,
};                                                        //it means present nodes is greater..
vector <node > edge;
int par[mx];
int find (int r) {  //getting representative of set..
   return (r == par[r] ) ? r : find (par[r]);
}
int mst (int n) {
   sort (edge.begin(), edge.end());
   for (int i = 1; i <= n; i++) par[i] = i; //Creating disjoint set as node numbers..
   int count = 0, s = 0;
   for (int i = 0; i < (int ) edge.size(); i++) {
      int u = find (edge[i].u); int v = find (edge[i].v);
      if (u != v) {  //checking connection & cycle..
         par[u] = v;
         count++;
         s += edge[i].w; //adding minimum edges value..
         if (count == n-1) break; //node number of spanning tree is n-1..
      }
   }
   return s;
}
int main ()
{
   int n, e;
   cin >> n >> e;
   for (int i = 0; i < e; i++ ) {
      int u, v, w;
      cin >> u >> v >> w;
      edge.push_back (node (u, v, w)); //Entering graph as Edge..
   }
   cout << mst (n) << endl; //sum of edges of minimum spanning tree..
   edge.clear ();
}

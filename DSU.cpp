#include <bits/stdc++.h>
using namespace std;
#define MX  30050
typedef long long LL;
#define V 4
#define INF 1e9
//class DisjointSet{
//public:
//    vector<int> parent;
//    DisjointSet(int n): parent(n) { for(int i=0; i<n; i++) parent[i] = i; }
//    void join(int a, int b) { parent[find(b)] = find(a); }
//    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }
//    bool check(int a, int b){ return find(a) == find(b); }
//};
int parent[1000], Rank[1000];
int Find(int x){
    return parent[x] = (parent[x] == x ? x : Find(parent[x]));
}
bool check(int a, int b){ return Find(a) == Find(b); }
void Union(int p, int q) {
    parent[Find(p)] = Find(q);
}
void UnionByRank(int p, int q){
    p = Find(p);
    q = Find(q);
    if(Rank[p] < Rank[q]) parent[p] = q;
    else parent[q] = p;
    if(Rank[p] == Rank[q]) Rank[p]++;
}

int main()
{
    //freopen ("in.txt", "r", stdin);
    int tc, temp = 0;
    for (int i = 0; i < 1000; i++) {
        parent[i] = i;
        Rank[i] = 0;
    }

    return 0;
}

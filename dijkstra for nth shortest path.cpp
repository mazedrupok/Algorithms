#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<limits>
#include<climits>
#include<cmath>
#include<functional>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<typeinfo>

using namespace std;

typedef long long int ll;
typedef short int i16;
typedef unsigned long long int u64;
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char u8;

const int N = 128;

struct edge
{
    int to, w;
    edge(){}
    edge(int a, int b)
    {
        to = a;
        w = b;
    }
};

struct el {
    int city, cost;
    el(){}
    el(int a, int b) {
        city = a;
        cost = b;
    }
    bool operator < (const el &a) const {
        return cost > a.cost; //for small to large
    }
};
priority_queue <el> pq;
vector <edge> v[N];
vector <int> dist[N];
int n, m, q;

void input() {
    int i, a, b, c;
    for(i = 0; i < N; i++)
        v[i].clear();
    for(i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        a++; //it avoid 0th node
        b++;
        v[a].push_back(edge(b, c));
        v[b].push_back(edge(a, c));
    }
}

void Dijkstra(int starting_node, int ending_node) {
    int i, curr_dis;
    el curr;
    for(i = 0; i < N; i++)
        dist[i].clear();
    while(!pq.empty())
        pq.pop();
    pq.push(el(starting_node, 0));
    while(!pq.empty()) {
        curr = pq.top();
        pq.pop();
        if(dist[curr.city].size() == 0)
            dist[curr.city].push_back(curr.cost);
        else if(dist[curr.city].back() != curr.cost)
            dist[curr.city].push_back(curr.cost);
        if(dist[curr.city].size() > 2) //for 2nd shortest path
            continue;
        for(i = 0; i < v[curr.city].size(); i++) {
            if(dist[v[curr.city][i].to].size() == 2) //for only 2nd shortest path
                continue;
            curr_dis = v[curr.city][i].w + curr.cost;
            pq.push(el(v[curr.city][i].to, curr_dis));
        }
    }
    if(dist[ending_node].size() < 2)
        printf("?\n");
    else
        printf("%d\n", dist[ending_node][1]);
}

void solve() {
    int i, a, b;
    scanf("%d", &q);
    for(i = 1; i <= q; i++) {
        scanf("%d %d", &a, &b);
        a++;
        b++;
        Dijkstra(a, b);
    }
}

int main()
{
    int i;
    for(i = 1; scanf("%d %d", &n, &m)!=EOF; i++) {
        input();
        printf("Set #%d\n", i);
        solve();
    }
    return 0;
}

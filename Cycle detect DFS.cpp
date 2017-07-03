#include <bits/stdc++.h>
#define N 100005
#define pb push_back
//http://www.geeksforgeeks.org/detect-cycle-in-a-graph/
using namespace std;
vector <int> g[N];
bool seen[N], recStack[N];
bool dfs (int u) {
    seen[u] = 1;
    recStack[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!seen[v] && dfs (v)) return 1; //not visited & in future any cycle
        else if (recStack[v]) return 1; //already visited & in recursive stack
    }
    recStack[u] = 0; //erasing from recursive stack
    return 0; //no cycle
}
bool isCycle () {
    memset (seen, 0, sizeof (seen));
    memset (recStack, 0, sizeof (recStack)); //recursive stack

    for (int i = 0; i < 4; i++) {
        if (!seen[i] && dfs (i)) {
            return 1;
        }
    }
    return 0;
}
int main ()
{
    g[0].pb (1);
    g[0].pb (2);
    g[1].pb (2);
    g[2].pb (0);
    g[2].pb (3);
    //g[3].pb (3);

    if (isCycle()) cout << "Cycle detected\n";
    else cout << "No Cycle\n";
    return 0;
}
